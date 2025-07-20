#pragma once

class String
{
  public:
    String();
    String(const char* pointerToCString);
    String(const String& referenceToString);
    String(String&& referenceToString);
};
