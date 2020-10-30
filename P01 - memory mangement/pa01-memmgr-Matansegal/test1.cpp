//
// Created by matan on 2/1/2020.
//

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "test1.h"

using namespace std;

test1::test1() {
    if(MDEBUG) {cout << "TEST1 CONSTRUCTOR" << endl;}
}

// this test have array of 100,000 pointers to pointers
// each pointer will allocate random bytes of memory
// in addition every 3 elements it will use the delete operation.
// for time analysis I changed the for loop size, which is the "Data size"
long test1::runTest(string s) {
    setDataSize(s);
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < dataSize; ++i) {
        srand (i);
        // 256 * 4 = max 1024 bytes
        int numOfElements = (rand() % 256) + 1;
        if(MDEBUG){ cout << "  i = " << i << "\n   num of elements - " << numOfElements << endl;}
        ptrArray[i] = new int*[numOfElements];
        if(i % 2 == 0){
            delete [] ptrArray[i];
        }
    }


    auto t2 = chrono::high_resolution_clock::now();
    runTime=chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return runTime;
}

void test1::setDataSize(string s) {
    if(s == "small"){
        dataSize = 7000;
    }
    else if(s == "med"){
        dataSize = 20000;
    }
    else if(s == "large"){
        dataSize = 50000;
    }
}
