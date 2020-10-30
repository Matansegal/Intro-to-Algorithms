//
// Created by matan on 2/10/2020.
//

#include "test2.h"

test2::test2() {

}

void test2::setDataSize(string s) {
    if(s == "small"){
        dataSize = 5000;
    }
    else if(s == "med"){
        dataSize = 16000;
    }
    else if(s == "large"){
        dataSize = 30000;
    }
}

// In test 2 it will create many new foo ptrs which each contains 1 - 10 foo objects
// foo contains many primitives
long test2::runTest(string s) {
    setDataSize(s);
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < dataSize; ++i) {
        ptrArray[i] = new foo*[i%10+1];
        if(i % 5 == 4){
            delete [] ptrArray[i-2];
        }
    }


    auto t2 = chrono::high_resolution_clock::now();
    runTime=chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return runTime;
}
