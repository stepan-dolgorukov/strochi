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

std::ostream& operator<<(std::ostream& referenceToStream, const String& referenceToString)
{
    for (std::size_t position{0u}; position < referenceToString.m_length; ++position)
    {
        referenceToStream << referenceToString.m_pointerToStorage[position];
    }

    return referenceToStream;
}
