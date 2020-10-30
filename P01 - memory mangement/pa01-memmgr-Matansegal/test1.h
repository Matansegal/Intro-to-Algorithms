//
// Created by matan on 2/1/2020.
//

#ifndef INC_20S_3353_PA01_TEST1_H
#define INC_20S_3353_PA01_TEST1_H

#include <chrono>
#include "global.h"

using namespace std;

class test1 {
private:
    long runTime;
    int** ptrArray[100000];
    int dataSize;
    void setDataSize(string);
public:
    test1();
    long runTest(string);
};


#endif //INC_20S_3353_PA01_TEST1_H
