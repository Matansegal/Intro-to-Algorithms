//
// Created by matan on 2/1/2020.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H


#include "Allocator.h"


class FirstFit : public Allocator{
public:
    FirstFit(size_t unnamed);
    virtual void* addToMemory(size_t bytes, bool isArray = false);
    virtual ~FirstFit();

private:
    void *reuseFreeList(int bytes);
};


#endif //INC_20S_3353_PA01_FIRSTFIT_H
