//
// Created by wangguozhi on 2020-11-26.
//

#ifndef GRIDVILLE_GRIDVILLE_H
#define GRIDVILLE_GRIDVILLE_H

class Gridville {
private:
    unsigned int     m;      // # of rows
    unsigned int     n;      // # of columns
    unsigned short   h;      // # of minimal height
    unsigned short*  p;      // Land Supply Plan

    int     get(int x, int y);
    void    set(int x, int y, int value);

public:
    Gridville();
    Gridville(int m, int n, int h);

    int*    dp_max_square_mem();
    int*    dp_max_square_bottom_up();
    int*    bf_max_rec();
    int*    dp_max_rec_mn();
    int*    dp_max_rec();

    void    input_plan();
    void    test_setup();

    int*    performance_test_setup(bool is_square);

};


#endif //GRIDVILLE_GRIDVILLE_H
