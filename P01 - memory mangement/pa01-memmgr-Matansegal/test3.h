//
// Created by matan on 2/10/2020.
//

#ifndef INC_20S_3353_PA01_TEST3_H
#define INC_20S_3353_PA01_TEST3_H

#include <iostream>
#include <chrono>
#include <string.h>

using namespace std;

class test3 {
private:
    long** longPtr[100000];
    double** doublePtr[100000];
    long runTime;
    int dataSize;
    void setDataSize(string);
public:
    test3();
    long runTest(string);
};


#endif //INC_20S_3353_PA01_TEST3_H
