//
// Created by matan on 1/29/2020.
//

#ifndef PROJECT1_CS3353_ALOMEMORY_H
#define PROJECT1_CS3353_ALOMEMORY_H

#include "AllocatorSingleton.h"
#include <math.h>

using namespace std;

// initialize the allocator
Allocator* AS = AllocatorSingleton::initMemory();

void* operator new(size_t numBytes) {
    return AS->addToMemory(numBytes);
}

void operator delete(void* ptr, size_t size) {
    if(MDEBUG){cout << "DELETE called!, size " << size << endl;}
    AS->freeMemory(ptr,false, size);
}

void* operator new[](size_t numBytes) {
    // here the allocator doesnt know the size of the pointer, we need to save the number of bytes
    return AS->addToMemory(numBytes, true);
}

void operator delete[] (void* ptr) {
    if(MDEBUG){cout << "DELETE[] called!" << endl;}
    AS->freeMemory(ptr, true);
}

#endif //PROJECT1_CS3353_ALOMEMORY_H
