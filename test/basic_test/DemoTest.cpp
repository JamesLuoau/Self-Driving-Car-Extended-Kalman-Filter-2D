//
// Created by James Luo on 21/4/17.
//

#include "DemoTest.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;
using namespace std;

namespace {

    class ClassDeclaration : public testing::Test {
    public:
        string str = "hello";

        ClassDeclaration(){
            str;
        }
    };
}

TEST_F(ClassDeclaration, myFirstTest){
    ASSERT_EQ("", "");
}

TEST_F(ClassDeclaration, mySecondTest){
    ASSERT_EQ("", "1");
}