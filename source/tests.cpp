#include "func.h"
#include "gtest/gtest.h" // do not use a global installation of google test here but the local on installed via bazel

int sum(int,int);
int prod(int,int);
int sub(int,int);


TEST(FunctionTests,AddTwoPositives){
    const int a = 3;
    const int b = 4;
    EXPECT_EQ(sum(a,b),7) << "The sum is not correct!";
}

TEST(FunctionTests,MultiplyTwoPositives){
    const int a = 3;
    const int b = 4;
    EXPECT_EQ(prod(a,b),12) << "The product is not correct!";
}

TEST(FunctionTests,SubTwoPositives){
    const int a = 3;
    const int b = 4;
    EXPECT_EQ(sub(a,b),-1) << "The substraction result is not correct!";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}