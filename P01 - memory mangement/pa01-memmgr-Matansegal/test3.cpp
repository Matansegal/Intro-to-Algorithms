//
// Created by matan on 2/10/2020.
//

#include "test3.h"

test3::test3() {

}

void test3::setDataSize(string s) {
    if(s == "small"){
        dataSize = 7000;
    }
    else if(s == "med"){
        dataSize = 20000;
    }
    else if(s == "large"){
        dataSize = 30000;
    }
}

// test 3 will is similar to test one but with long and double ptr arrays.
long test3::runTest(string s) {
    setDataSize(s);
    auto t1 = chrono::high_resolution_clock::now();

    for (int i = 0; i < dataSize; ++i) {
        longPtr[i] = new long*[(i % 50) + 1];
        doublePtr[i] = new double*[(i % 37) + (i % 89)];
        if(i % 5 == 2){
            delete [] longPtr[i-1];
        }
        else if(i % 15 == 7){
            delete [] doublePtr[i/2];
        }
    }

    auto t2 = chrono::high_resolution_clock::now();
    runTime=chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return runTime;
}
