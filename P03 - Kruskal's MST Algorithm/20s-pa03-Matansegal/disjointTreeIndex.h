//
// Created by matan on 4/9/2020.
//

#ifndef INC_20S_PA03_MATANSEGAL_DISJOINTTREEINDEX_H
#define INC_20S_PA03_MATANSEGAL_DISJOINTTREEINDEX_H

#include "disjointTree.h"
#include "index.h"

class disjointTreeIndex : public index{
private:
    disjointTree<string>* djt;
    int totalElem;
public:
    disjointTreeIndex();
    disjointTreeIndex(const disjointTreeIndex&);
    disjointTreeIndex& operator=(const disjointTreeIndex&);
    virtual ~disjointTreeIndex();
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
    int stringToint(string);
};


#endif //INC_20S_PA03_MATANSEGAL_DISJOINTTREEINDEX_H
