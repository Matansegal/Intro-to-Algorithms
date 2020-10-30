//
// Created by matan on 4/8/2020.
//

#ifndef INC_20S_PA03_MATANSEGAL_INDEX_H
#define INC_20S_PA03_MATANSEGAL_INDEX_H

#include <string>

using namespace std;

class index {
public:
    index();
    virtual ~index();
    virtual int find(string) = 0;
    virtual void makeSet(string,string) = 0;
    virtual void Union(int,int)= 0;
    virtual void unionIdx(string,int)= 0;
    virtual int getNumConnect()=0;
    virtual bool isAllinside()=0;
    virtual void setNumOfElem(int)=0;

};


#endif //INC_20S_PA03_MATANSEGAL_INDEX_H
