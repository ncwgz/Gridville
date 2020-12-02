//
// Created by wangguozhi on 2020-11-28.
//

#include "Gridville.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

Gridville*      gridville;

void setup() {
    if (gridville) delete gridville;
    gridville = new Gridville();
}

TEST(Correctness, alg1) {
    int* rectangle = gridville->correctness_test_setup(true);
    int* result = gridville->dp_max_square_mem();
    ASSERT_EQ(rectangle[0], result[0]);
    ASSERT_EQ(rectangle[1], result[1]);
    ASSERT_EQ(rectangle[2], result[2]);
    ASSERT_EQ(rectangle[3], result[3]);
    delete result;
}

TEST(Correctness, alg2) {
    int* rectangle = gridville->correctness_test_setup(true);
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
    int* rectangle = gridville->correctness_test_setup(false);
    int* result = gridville->dp_max_rec_mn();
    ASSERT_EQ(rectangle[0], result[0]);
    ASSERT_EQ(rectangle[1], result[1]);
    ASSERT_EQ(rectangle[2], result[2]);
    ASSERT_EQ(rectangle[3], result[3]);
    delete result;
}

TEST(Correctness, alg5) {
    int* rectangle = gridville->correctness_test_setup(false);
    int* result = gridville->dp_max_rec();
    ASSERT_EQ(rectangle[0], result[0]);
    ASSERT_EQ(rectangle[1], result[1]);
    ASSERT_EQ(rectangle[2], result[2]);
    ASSERT_EQ(rectangle[3], result[3]);
    delete result;
}

TEST(Performance_Square_10, alg1) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/10/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_mem();
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(6, result[1]);
        ASSERT_EQ(9, result[2]);
        ASSERT_EQ(9, result[3]);
        delete result;
    }
}

TEST(Performance_Square_10, alg2) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/10/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_bottom_up();
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(6, result[1]);
        ASSERT_EQ(9, result[2]);
        ASSERT_EQ(9, result[3]);
        delete result;
    }
}

TEST(Performance_Square_10, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/10/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(6, result[1]);
        ASSERT_EQ(9, result[2]);
        ASSERT_EQ(9, result[3]);
        delete result;
    }
}

TEST(Performance_Square_10, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/10/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(6, result[1]);
        ASSERT_EQ(9, result[2]);
        ASSERT_EQ(9, result[3]);
        delete result;
    }
}

TEST(Performance_Square_50, alg1) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/50/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_mem();
        ASSERT_EQ(21, result[0]);
        ASSERT_EQ(21, result[1]);
        ASSERT_EQ(39, result[2]);
        ASSERT_EQ(39, result[3]);
        delete result;
    }
}

TEST(Performance_Square_50, alg2) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/50/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_bottom_up();
        ASSERT_EQ(21, result[0]);
        ASSERT_EQ(21, result[1]);
        ASSERT_EQ(39, result[2]);
        ASSERT_EQ(39, result[3]);
        delete result;
    }
}

TEST(Performance_Square_50, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/50/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(21, result[0]);
        ASSERT_EQ(21, result[1]);
        ASSERT_EQ(39, result[2]);
        ASSERT_EQ(39, result[3]);
        delete result;
    }
}

TEST(Performance_Square_50, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/50/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(21, result[0]);
        ASSERT_EQ(21, result[1]);
        ASSERT_EQ(39, result[2]);
        ASSERT_EQ(39, result[3]);
        delete result;
    }
}

TEST(Performance_Square_250, alg1) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/250/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_mem();
        ASSERT_EQ(124, result[0]);
        ASSERT_EQ(124, result[1]);
        ASSERT_EQ(233, result[2]);
        ASSERT_EQ(233, result[3]);
        delete result;
    }
}

TEST(Performance_Square_250, alg2) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/250/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_bottom_up();
        ASSERT_EQ(124, result[0]);
        ASSERT_EQ(124, result[1]);
        ASSERT_EQ(233, result[2]);
        ASSERT_EQ(233, result[3]);
        delete result;
    }
}

TEST(Performance_Square_250, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/250/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(124, result[0]);
        ASSERT_EQ(124, result[1]);
        ASSERT_EQ(233, result[2]);
        ASSERT_EQ(233, result[3]);
        delete result;
    }
}

TEST(Performance_Square_250, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/250/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(124, result[0]);
        ASSERT_EQ(124, result[1]);
        ASSERT_EQ(233, result[2]);
        ASSERT_EQ(233, result[3]);
        delete result;
    }
}

TEST(Performance_Square_1000, alg1) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/1000/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_mem();
        ASSERT_EQ(251, result[0]);
        ASSERT_EQ(251, result[1]);
        ASSERT_EQ(996, result[2]);
        ASSERT_EQ(996, result[3]);
        delete result;
    }
}

TEST(Performance_Square_1000, alg2) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/1000/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_square_bottom_up();
        ASSERT_EQ(251, result[0]);
        ASSERT_EQ(251, result[1]);
        ASSERT_EQ(996, result[2]);
        ASSERT_EQ(996, result[3]);
        delete result;
    }
}

TEST(Performance_Square_1000, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/1000/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(251, result[0]);
        ASSERT_EQ(251, result[1]);
        ASSERT_EQ(996, result[2]);
        ASSERT_EQ(996, result[3]);
        delete result;
    }
}

TEST(Performance_Square_1000, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/1000/" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(251, result[0]);
        ASSERT_EQ(251, result[1]);
        ASSERT_EQ(996, result[2]);
        ASSERT_EQ(996, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_10, alg3) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/10/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->bf_max_rec();
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(4, result[1]);
        ASSERT_EQ(9, result[2]);
        ASSERT_EQ(6, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_10, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/10/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(4, result[1]);
        ASSERT_EQ(9, result[2]);
        ASSERT_EQ(6, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_10, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/10/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(6, result[0]);
        ASSERT_EQ(4, result[1]);
        ASSERT_EQ(9, result[2]);
        ASSERT_EQ(6, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_50, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/50/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(16, result[0]);
        ASSERT_EQ(21, result[1]);
        ASSERT_EQ(24, result[2]);
        ASSERT_EQ(29, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_50, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/50/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(16, result[0]);
        ASSERT_EQ(21, result[1]);
        ASSERT_EQ(24, result[2]);
        ASSERT_EQ(29, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_250, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/250/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(123, result[0]);
        ASSERT_EQ(52, result[1]);
        ASSERT_EQ(234, result[2]);
        ASSERT_EQ(98, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_250, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/250/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(123, result[0]);
        ASSERT_EQ(52, result[1]);
        ASSERT_EQ(234, result[2]);
        ASSERT_EQ(98, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_1000, alg4) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/1000/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec_mn();
        ASSERT_EQ(251, result[0]);
        ASSERT_EQ(500, result[1]);
        ASSERT_EQ(500, result[2]);
        ASSERT_EQ(996, result[3]);
        delete result;
    }
}

TEST(Performance_Rectangle_1000, alg5) {
    for (int i = 0; i < 10; ++i) {
        std::string filepath("../../Google_tests/cases/1000/r" + to_string(i) + ".txt");
        gridville->read_plan(filepath);
        int* result = gridville->dp_max_rec();
        ASSERT_EQ(251, result[0]);
        ASSERT_EQ(500, result[1]);
        ASSERT_EQ(500, result[2]);
        ASSERT_EQ(996, result[3]);
        delete result;
    }
}

int main() {
    setup();
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}
