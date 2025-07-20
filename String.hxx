#pragma once

#include <cstddef>

class String
{
  public:
    String();
    String(const char* pointerToCString) = delete;
    String(const String& referenceToString) = delete;
    String(String&& referenceToString) = delete;
    String& operator=(const char* pointerToCString) = delete;
    String& operator=(const String& referenceToString) = delete;
    String& operator=(String&& referenceToString) = delete;
    String& operator+=(const char* pointerToCString) = delete;
    String& operator+=(const String& referenceToString) = delete;
    String& operator=(String&& referenceToString) = delete;

  private:
    char* pointerToStorage{};
    std::size_t sizeStorage;
    std::size_t length{};
};
