//
// Created by matan on 2/1/2020.
//

#ifndef INC_20S_3353_PA01_BESTFIT_H
#define INC_20S_3353_PA01_BESTFIT_H


#include "Allocator.h"

class BestFit : public Allocator{
public:
    BestFit(size_t unnamed);
    virtual void* addToMemory(size_t bytes, bool isArray = false);
    virtual ~BestFit();

private:
    void *bestReuseFreeList(size_t bytes);
};


#endif //INC_20S_3353_PA01_BESTFIT_H
