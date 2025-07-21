#pragma once

#include <cstddef>
#include <ostream>

class String
{
  public:
    ~String();
    String();
    String(const char* pointerToCString);
    String(const String& referenceToString);
    String(String&& referenceToString);
    String& operator=(const String& referenceToString);
    String& operator=(String&& referenceToString);
    String& operator=(const char* pointerToCString) = delete;
    String& operator+=(const char* pointerToCString) = delete;
    String& operator+=(const String& referenceToString);
    friend bool operator==(const String& referenceToLeftString, const String& referenceToRightString);
    friend std::ostream& operator<<(std::ostream& referenceToStream, const String& referenceToString);

  private:
    char* m_pointerToStorage{nullptr};
    std::size_t m_sizeStorage{0u};
    std::size_t m_length{0u};
};
