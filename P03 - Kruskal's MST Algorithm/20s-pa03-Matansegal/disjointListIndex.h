//
// Created by matan on 4/7/2020.
//

#ifndef INC_20S_PA03_MATANSEGAL_DISJOINTLISTINDEX_H
#define INC_20S_PA03_MATANSEGAL_DISJOINTLISTINDEX_H

#include "disjointList.h"
#include "index.h"

class disjointListIndex : public index{
private:
    disjointList<string>* djl;
    int totalElem;
public:
    disjointListIndex();
    disjointListIndex(const disjointListIndex&);
    disjointListIndex& operator=(const disjointListIndex&);
    virtual ~disjointListIndex();
    virtual int find(string);
    virtual void makeSet(string,string);
    // accept two locations in the list
    virtual void Union(int,int);
    // accept element and location in the list
    virtual void unionIdx(string,int);
    // return number of total indexes in disjoint
    virtual int getNumConnect();
    virtual bool isAllinside();
    virtual void setNumOfElem(int);


};


#endif //INC_20S_PA03_MATANSEGAL_DISJOINTLISTINDEX_H
