//
// Created by wangguozhi on 2020-11-28.
//

#include "Gridville.h"
#include "gtest/gtest.h"

Gridville*      gridville;

void setup() {
    if (gridville) delete gridville;
    gridville = new Gridville();
}

TEST(Correctness, alg1) {
    int* rectangle = gridville->performance_test_setup(true);
    int* result = gridville->dp_max_square_mem();
    ASSERT_EQ(rectangle[0], result[0]);
    ASSERT_EQ(rectangle[1], result[1]);
    ASSERT_EQ(rectangle[2], result[2]);
    ASSERT_EQ(rectangle[3], result[3]);
    delete result;
}

TEST(Correctness, alg2) {
    int* rectangle = gridville->performance_test_setup(true);
    int* result = gridville->dp_max_square_bottom_up();
    ASSERT_EQ(rectangle[0], result[0]);
    ASSERT_EQ(rectangle[1], result[1]);
    ASSERT_EQ(rectangle[2], result[2]);
    ASSERT_EQ(rectangle[3], result[3]);
    delete result;
}

TEST(Correctness, alg3) {
    gridville->test_setup();
    int* result = gridville->bf_max_rec();
    ASSERT_EQ(2, result[0]);
    ASSERT_EQ(1, result[1]);
    ASSERT_EQ(3, result[2]);
    ASSERT_EQ(4, result[3]);
    delete result;
}

TEST(Correctness, alg4) {
    int* rectangle = gridville->performance_test_setup(false);
    int* result = gridville->dp_max_rec_mn();
    ASSERT_EQ(rectangle[0], result[0]);
    ASSERT_EQ(rectangle[1], result[1]);
    ASSERT_EQ(rectangle[2], result[2]);
    ASSERT_EQ(rectangle[3], result[3]);
    delete result;
}

TEST(Correctness, alg5) {
    int* rectangle = gridville->performance_test_setup(false);
    int* result = gridville->dp_max_rec();
    ASSERT_EQ(rectangle[0], result[0]);
    ASSERT_EQ(rectangle[1], result[1]);
    ASSERT_EQ(rectangle[2], result[2]);
    ASSERT_EQ(rectangle[3], result[3]);
    delete result;
}

int main() {
    setup();
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}
