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
        ASSERT_EQ(string, String{string});
    }

    {
        String s0{"!@#$%^&*"};
        String s1{std::move(s0)};

        ASSERT_EQ(s1, "!@#$%^&*");
    }
}

TEST(Assign, CopyAssignString)
{
    String s0{"hello, world!"};
    String s1{"world, goodbye!"};

    s0 = s1;
    ASSERT_EQ(s0, s1);
    s1 = s0;
    ASSERT_EQ(s0, s1);
}

TEST(Assign, MoveAssingString)
{
    String s0{"hello, world!"};
    String s1{"world, goodbye!"};

    s0 = std::move(s1);
    ASSERT_EQ(s0, "world, goodbye!");
}

TEST(Assign, AssingCString)
{
    String s0{"hello, world!"};

    s0 = "!@#$%^&*";
    ASSERT_EQ(s0, "!@#$%^&*");
}

TEST(AdditionAssignment, String)
{
    String s0{"hello,"};
    String s1{" world!"};

    s0 += s1;
    ASSERT_EQ(s0, "hello, world!");
    s1 += s0;
    ASSERT_EQ(s1, " world!hello, world!");
}

TEST(Compare, Equality)
{
    ASSERT_EQ(String{}, String{});
    ASSERT_EQ(String{}, String{"\0"});
    ASSERT_EQ(String{"\0"}, String{});
    ASSERT_EQ(String{"\0"}, String{"\0\0"});
    ASSERT_EQ(String{"\0\0"}, String{"\0"});
}

TEST(Compare, Less)
{
    ASSERT_LT(String{}, String{"a"});
    ASSERT_LT(String{"a"}, String{"b"});
}

TEST(Compare, Greater)
{
    ASSERT_GT(String{"a"}, String{});
    ASSERT_GT(String{"b"}, String{"a"});
}

int main(int amountArguments, char** pointerToArguments)
{
    testing::InitGoogleTest(&amountArguments, pointerToArguments);
    return RUN_ALL_TESTS();
}
