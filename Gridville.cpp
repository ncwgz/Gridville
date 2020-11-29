//
// Created by wangguozhi on 2020-11-26.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "Gridville.h"
#include "gtest/gtest.h"

using namespace std;

Gridville::Gridville() {
    this->p = nullptr;
}

Gridville::Gridville(int m, int n, int h) {
    this->m = m;
    this->n = n;
    this->h = h;
    this->p = new unsigned short[m * n];
}

int Gridville::get(int x, int y) {
    return this->p[x * n + y];
}

void Gridville::set(int x, int y, int value) {
    this->p[x * n + y] = value;
}

int* Gridville::dp_max_square_mem() {
    int     x1;             // up left x
    int     y1;             // up left y
    int     x2 = 0;         // bottom right x
    int     y2 = 0;         // bottom right y
    int     length = 0;     // size length of the square

    // memorandum, use one extra row and column for convenience
    vector<vector<int>> memo(m+1, vector<int>(n+1, 0));

    // dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (get(i-1, j-1) >= h) {
                // dp formulation
                memo[i][j] = 1 + min({
                    memo[i][j - 1], memo[i - 1][j], memo[i - 1][j - 1]
                });
            }
            else {
                memo[i][j] = 0;
            }
            // record the bottom right block
            if (memo[i][j] > length) {
                length = memo[i][j];
                x2 = i-1; y2 = j-1;
            }
        }
    }

    x1 = x2 - length + 1;
    y1 = y2 - length + 1;
    return length != 0 ? new int[4]{x1, y1, x2, y2} : nullptr;
}

int* Gridville::dp_max_square_bottom_up() {
    int     x1;                  // up left x
    int     y1;                  // up left y
    int     x2 = 0;              // bottom right x
    int     y2 = 0;              // bottom right y
    int     length = 0;          // size length of the biggest square
    int     memo[n + 1];         // memorandum, only one line
    int     up_left = 0;         // record itself for its bottom right block

    // initialize memo to 0
    for (int i = 0; i <= n; ++i) {
        memo[i] = 0;
    }

    // dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int itself = memo[j];
            if (get(i-1, j-1) >= h) {
                // dp formulation
                memo[j] = 1 + min({
                    itself, memo[j - 1], up_left
                });
            } else {
                memo[j] = 0;
            }
            up_left = itself;
            if (memo[j] > length) {
                length = memo[j];
                x2 = i-1; y2 = j-1;
            }
        }
    }

    x1 = x2 - length + 1;
    y1 = y2 - length + 1;
    return length != 0 ? new int[4]{x1, y1, x2, y2} : nullptr;
}

int* Gridville::bf_max_rec() {

    int*    to_return;      // {x1, y1, x2, y2}
    int     largest = 0;    // the area of the largest rectangle

    // any rectangle whose up left is (x1, y1)
    for (int x1 = 0; x1 < m; ++x1) {
    for (int y1 = 0; y1 < n; ++y1) {
        // and whose bottom right is (x2, y2)
        // x2 >= x1; y2 >= y1;
        for (int x2 = x1; x2 < m; ++x2) {
        for (int y2 = y1; y2 < n; ++y2) {

            // check if each block in this rectangle is qualified
            bool is_qualified = true;
            for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                if (get(i, j) < h) {
                    is_qualified = false;
                }
            }
            }
            // if qualified, check if it is the current largest rectangle
            if (is_qualified) {
                int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                if (area > largest) {
                    largest = area;
                    to_return = new int[4]{x1, y1, x2, y2};
                }
            }
        }
        }
    }
    }
    return to_return;
}

int *Gridville::dp_max_rec_mn() {
    int     x1;                  // up left x
    int     y1;                  // up left y
    int     x2 = 0;              // bottom right x
    int     y2 = 0;              // bottom right y
    int     largest = 0;         // area of the largest rectangle
    auto*   left = new vector<vector<int>>(m+1, vector<int>(n, 0));
    auto*   right = new vector<vector<int>>(m+1, vector<int>(n, n));
    auto*   height = new vector<vector<int>>(m+1, vector<int>(n, 0));
    for (int i = 1; i <= m; ++i) {
        int leftmost = 0;
        int rightmost = n;
        for (int j = 0; j < n; ++j) {
            if (get(i-1, j) >= h) (*height)[i][j] = (*height)[i-1][j] + 1;
            else (*height)[i][j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (get(i-1, j) >= h) (*left)[i][j] = max((*left)[i-1][j], leftmost);
            else {
                (*left)[i][j] = 0;
                leftmost = j + 1;
            }
        }
        for (int j = n-1; j >= 0; --j) {
            if (get(i-1, j) >= h) (*right)[i][j] = min((*right)[i-1][j], rightmost);
            else {
                (*right)[i][j] = n;
                rightmost = j;
            }
        }
        for (int j = 0; j < n; ++j) {
            int area = ((*right)[i][j] - (*left)[i][j]) * (*height)[i][j];
            if (area >= largest) {
                largest = area;
                x1 = i - (*height)[i][j];
                y1 = (*left)[i][j];
                x2 = i -1;
                y2 = (*right)[i][j] - 1;
            }
        }
    }
    return new int[4]{x1, y1, x2, y2};
}

int* Gridville::dp_max_rec() {
    int         x1;                   // up left x
    int         y1;                   // up left y
    int         x2 = 0;               // bottom right x
    int         y2 = 0;               // bottom right y
    int         largest = 0;          // area of the largest rectangle
    vector<int> left(n, 0);     //
    vector<int> right(n, n);    //
    vector<int> height(n, 0);   //
    for (int i = 0; i < m; ++i) {
        int leftmost = 0;
        int rightmost = n;
        for (int j = 0; j < n; ++j) {
            if (get(i, j) >= h) height[j] ++;
            else height[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (get(i, j) >= h) left[j] = max(left[j], leftmost);
            else {
                left[j] = 0;
                leftmost = j + 1;
            }
        }
        for (int j = n-1; j >= 0; --j) {
            if (get(i, j) >= h) right[j] = min(right[j], rightmost);
            else {
                right[j] = n;
                rightmost = j;
            }
        }
        for (int j = 0; j < n; ++j) {
            int area = (right[j] - left[j]) * height[j];
            if (area >= largest) {
                largest = area;
                x1 = i - height[j] + 1;
                y1 = left[j];
                x2 = i;
                y2 = right[j] - 1;
            }
        }
    }
    return new int[4]{x1, y1, x2, y2};
}

void Gridville::input_plan() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            set(i, j, value);
        }
    }
}

void Gridville::read_plan(string filepath) {
    ifstream file(filepath);
    file >> m >> n >> h;
    this->p = new unsigned short[m*n]();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            file >> value;
            set(i, j, value);
        }
    }
}

void Gridville::test_setup() {
    this->m = 4;
    this->n = 5;
    this->h = 5;
    this->p = new unsigned short [20] {
        9, 0, 9, 0, 0,
        9, 0, 9, 9, 0,
        0, 9, 9, 9, 9,
        9, 9, 9, 9, 9
    };
}

int* Gridville::correctness_test_setup(bool is_square) {

    srand(time(nullptr));

    int c = 10;

    this->m = 256 + rand() % 256;
    this->n = 256 + rand() % 256;
    this->h = 1;

    m *= c;
    n *= c;

    int x1 = rand() % 128;
    int y1 = rand() % 128;
    int x2;
    int y2;

    int length = 16 + rand() % 16;
    x2 = x1 + length;
    if (is_square) {
        y2 = y1 + length;
    } else {
        int lengthh = 16 + rand() % 16;
        y2 = y1 + lengthh;
    }

    if (p != nullptr) {
        delete p;
    }
    this->p = new unsigned short[m * n];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            set(i, j, 0);
        }
    }

    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            set(i, j, 1);
        }
    }

    return new int[4]{x1, y1, x2, y2};
}
