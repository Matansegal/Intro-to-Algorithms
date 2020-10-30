//
// Created by matan on 1/30/2020.
//

#ifndef PROJECT1_CS3353_BOOKKEEPINGNODE_H
#define PROJECT1_CS3353_BOOKKEEPINGNODE_H

#include "global.h"

// should save just the objects using the new[] operator
class BookKeepingNode {
private:
    void* startAdd;
    int length;
    bool lastElm;
public:
    BookKeepingNode(void*, int);
    ~BookKeepingNode();
    void* getStartAdd();
    void setAddressNull();
    void setAddress(void*);
    int getLength();
    void setLength(int);
    bool isLastElm();
    void setLastElmFalse();
};


#endif //PROJECT1_CS3353_BOOKKEEPINGNODE_H
