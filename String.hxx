#pragma once

class String
{
  public:
    String();
    String(const char* pointerToCString);
    String(const String& referenceToString);
    String(String&& referenceToString);
    String& operator=(const char* pointerToCString);
    String& operator=(const String& referenceToString);
    String& operator=(String&& referenceToString);
    String& operator+=(const char* pointerToCString);
    String& operator+=(const String& referenceToString);
    String& operator=(String&& referenceToString);
};
