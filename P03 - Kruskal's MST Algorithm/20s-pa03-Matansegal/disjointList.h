//
// Created by matan on 4/7/2020.
//

#ifndef INC_20S_PA03_MATANSEGAL_DISJOINTLIST_H
#define INC_20S_PA03_MATANSEGAL_DISJOINTLIST_H

#include <list>
#include <iterator>
#include <iostream>

using namespace std;

template <typename T>
class disjointList {
private:
    list<list<T>> disjoint;
    int size;
public:
    disjointList();
    disjointList(const disjointList<T>&);
    disjointList<T>& operator=(const disjointList<T>&);
    ~disjointList();
    // return location in the list
    int find(T);
    void makeSet(T,T);
    // accept two locations in the list
    void Union(int,int);
    // accept element and location in the list
    void unionIdx(T,int);
    // return number of total indexes in disjoint
    int numOfIdx();
    int getNumOfLists();

};

template<typename T>
disjointList<T>::disjointList() {
    size = 0;
}

template<typename T>
disjointList<T>::disjointList(const disjointList<T> &djl) {
    this->disjoint = djl.disjoint;
    this->size = djl.size;
}

template<typename T>
disjointList<T> &disjointList<T>::operator=(const disjointList<T> &djl) {
    this->disjoint = djl.disjoint;
    this->size = djl.size;
    return *this;
}

template<typename T>
disjointList<T>::~disjointList() {

}

template<typename T>
int disjointList<T>::find(T idx) {
    int i = 0;
    typename list<T>::iterator it;
    // loop thorugh the outer list
    for(auto& l : disjoint){
        // loop through the inner list
        for (it = l.begin() ;  it!= l.end() ; it++) {
            if (*it == idx) return i;
        }
        i++;
    }
    return -1;
}

template<typename T>
void disjointList<T>::makeSet(T a, T b) {
    list<T> temp;
    temp.push_back(a);
    temp.push_back(b);
    disjoint.push_back(temp);
    size += 2;
}

template<typename T>
void disjointList<T>::Union(int a, int b) {
    typename list<list<T>>::iterator it1 = disjoint.begin();
    // move it to location a
    advance(it1,a);
    typename list<list<T>>::iterator it2 = disjoint.begin();
    advance(it2,b);

    int sizeA = it1->size();
    int sizeB = it2->size();

    // check which is bigger
    if(sizeA > sizeB){
        // add list b to a
        it1->merge(*it2);
        // remove b from disjoint
        disjoint.erase(it2);
    } else{
        it2->merge(*it1);
        // remove a from disjoint
        disjoint.erase(it1);
    }

}

template<typename T>
void disjointList<T>::unionIdx(T idx, int a) {
    typename list<list<T>>::iterator it = disjoint.begin();
    advance(it,a);
    it->push_back(idx);
    size++;
}

template<typename T>
int disjointList<T>::numOfIdx() {
    return size;
}

template<typename T>
int disjointList<T>::getNumOfLists() {
    return disjoint.size();
}


#endif //INC_20S_PA03_MATANSEGAL_DISJOINTLIST_H
