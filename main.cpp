#include <iostream>
#include "Gridville.h"

using namespace std;

int main(int argc, char **argv) {

    int method;     // Alg. number
    int m;          // # of rows
    int n;          // # of columns
    int h;          // # of minimal height
    int *result;    // {x1, y1, x2, y2}

    method = stoi(argv[1]);
    cin >> m >> n >> h;

    Gridville *gridville = new Gridville(m, n, h);
    gridville->input_plan();
    switch (method) {
        case 1: {
            result = gridville->dp_max_square_mem();
            break;
        }
        case 2: {
            result = gridville->dp_max_square_bottom_up();
            break;
        }
        case 3: {
            result = gridville->bf_max_rec();
            break;
        }
        case 4: {
            result = gridville->dp_max_rec_mn();
            break;
        }
        case 5: {
            result = gridville->dp_max_rec();
            break;
        }
    }

    if (result == nullptr) {
        cout << "none" << endl;
    }
    else {
        cout << "(" << result[0] << ", " << result[1] << ")" << endl;
        cout << "(" << result[2] << ", " << result[3] << ")" << endl;
    }

    delete gridville;
    delete result;

    return 0;
}
