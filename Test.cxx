#include <gtest/gtest.h>
#include <iostream>

#include "String.hxx"

int main(int amountArguments, char** pointerToArguments)
{
    testing::InitGoogleTest(&amountArguments, pointerToArguments);
    return RUN_ALL_TESTS();
}
