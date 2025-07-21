#include <gtest/gtest.h>
#include <iostream>

#include "String.hxx"

TEST(Construct, DefaultConstructor)
{
    String{};
}

TEST(Construct, CreateFromCString)
{
    String{nullptr};
    String{""};
    String{"\0"};
    String{"hello, world!"};
}

TEST(Construct, CreateFromReferenceToString)
{
    String{String{}};
    String{std::move(String{})};

    {
        String string{"!@#$%^&*"};
        String{string};
    }

    {
        String string{"!@#$%^&*"};
        String{std::move(string)};
    }
}

int main(int amountArguments, char** pointerToArguments)
{
    testing::InitGoogleTest(&amountArguments, pointerToArguments);
    return RUN_ALL_TESTS();
}
