//
// Created by matan on 2/1/2020.
//

#ifndef INC_20S_3353_PA01_MYFIT_H
#define INC_20S_3353_PA01_MYFIT_H

#include "Allocator.h"

class MyFit : public Allocator{

public:
    MyFit(size_t unnamed);
    virtual void* addToMemory(size_t bytes, bool isArray = false);
    virtual ~MyFit();

private:
    void *reuseFreeList(size_t bytes);
};


#endif //INC_20S_3353_PA01_MYFIT_H
