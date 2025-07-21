#include <cstdlib>
#include <cstring>
#include <stdexcept>

#include "String.hxx"

String::~String()
{
    std::free(m_pointerToStorage);
}

String::String() : m_pointerToStorage{nullptr} {}

String::String(const char* pointerToCString)
{
    if (pointerToCString == nullptr)
    {
        return;
    }

    const std::size_t length{std::strlen(pointerToCString)};

    if (length == 0u)
    {
        return;
    }

    m_pointerToStorage = reinterpret_cast<char*>(std::malloc(length));

    if (m_pointerToStorage == nullptr)
    {
        throw std::runtime_error{"fail to allocate memory for string"};
    }

    m_length = m_sizeStorage = length;
    std::strncpy(m_pointerToStorage, pointerToCString, length);
}

String::String(const String& referenceToString)
{
    m_pointerToStorage = reinterpret_cast<char*>(std::malloc(referenceToString.m_sizeStorage));

    if (m_pointerToStorage == nullptr)
    {
        throw std::runtime_error{"fail to allocate memory for string"};
    }

    m_sizeStorage = referenceToString.m_sizeStorage;
    std::strncpy(m_pointerToStorage, referenceToString.m_pointerToStorage, referenceToString.m_length);
    m_length = referenceToString.m_length;
}

String::String(String&& referenceToString)
    : m_pointerToStorage{referenceToString.m_pointerToStorage},
      m_sizeStorage{referenceToString.m_sizeStorage},
      m_length{referenceToString.m_length}
{
    referenceToString.m_pointerToStorage = nullptr;
    referenceToString.m_sizeStorage = 0u;
    referenceToString.m_length = 0u;
}

String& String::operator=(const String& referenceToString)
{
    if (this == &referenceToString)
    {
        return *this;
    }

    std::free(m_pointerToStorage);
    m_pointerToStorage = reinterpret_cast<char*>(std::malloc(referenceToString.m_sizeStorage));

    if (m_pointerToStorage == nullptr)
    {
        throw std::runtime_error{"fail to allocate memory for string"};
    }

    m_sizeStorage = referenceToString.m_sizeStorage;
    m_length = referenceToString.m_length;
    std::strncpy(m_pointerToStorage, referenceToString.m_pointerToStorage, m_length);

    return *this;
}

String& String::operator=(String&& referenceToString)
{
    if (this == &referenceToString)
    {
        return *this;
    }

    std::free(m_pointerToStorage);
    m_sizeStorage = referenceToString.m_sizeStorage;
    m_pointerToStorage = referenceToString.m_pointerToStorage;
    referenceToString.m_pointerToStorage = nullptr;
    m_length = referenceToString.m_length;

    return *this;
}

String& String::operator=(const char* pointerToCString)
{
    return operator=(String{pointerToCString});
}

String& String::operator+=(const String& referenceToString)
{
    if (referenceToString.m_length == 0)
    {
        return *this;
    }

    char* pointerToStorage{
        reinterpret_cast<char*>(std::realloc(m_pointerToStorage, m_length + referenceToString.m_length))};

    if (pointerToStorage == nullptr)
    {
        throw std::runtime_error{"fail to allocate memory for string"};
    }

    m_pointerToStorage = pointerToStorage;
    std::strncpy(m_pointerToStorage + m_length, referenceToString.m_pointerToStorage, referenceToString.m_length);
    m_length += referenceToString.m_length;
    return *this;
}

bool operator==(const String& referenceToLeftString, const String& referenceToRightString)
{
    if (referenceToLeftString.m_length != referenceToRightString.m_length)
    {
        return false;
    }

    for (std::size_t position{0u}; position < referenceToLeftString.m_length; ++position)
    {
        if (referenceToLeftString.m_pointerToStorage[position] != referenceToRightString.m_pointerToStorage[position])
        {
            return false;
        }
    }

    return true;
}

bool operator!=(const String& referenceToLeftString, const String& referenceToRightString)
{
    return !operator==(referenceToLeftString, referenceToRightString);
}

std::ostream& operator<<(std::ostream& referenceToStream, const String& referenceToString)
{
    if (referenceToString.m_pointerToStorage == nullptr)
    {
        return referenceToStream;
    }

    for (std::size_t position{0u}; position < referenceToString.m_length; ++position)
    {
        referenceToStream << referenceToString.m_pointerToStorage[position];
    }

    return referenceToStream;
}
