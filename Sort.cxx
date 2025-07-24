#include <algorithm>
#include <iostream>
#include <vector>

#include "String.hxx"

int main()
{
    std::vector<String> strings{};

    for (String string{}; std::cin >> string; )
    {
        strings.push_back(std::move(string));
    }

    std::sort(strings.begin(), strings.end(), std::greater<String>{});

    for (const String& referenceToString : strings)
    {
        std::cout << referenceToString << '\n';
    }

    return 0;
}
