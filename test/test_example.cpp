#include <gtest/gtest.h>
#include <ros/ros.h>

// Example function to be tested
int add(int a, int b) {
    return a + b;
}

// Unit test
TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(AdditionTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(AdditionTest, Zero) {
    EXPECT_EQ(add(0, 0), 0);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "test_example");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
