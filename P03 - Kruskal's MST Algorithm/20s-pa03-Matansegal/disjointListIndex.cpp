//
// Created by matan on 4/7/2020.
//

#include "disjointListIndex.h"

disjointListIndex::disjointListIndex() {
    djl = new disjointList<string>;
}

disjointListIndex::disjointListIndex(const disjointListIndex &newDjl) {
    *djl = *newDjl.djl;
    totalElem = newDjl.totalElem;
}

disjointListIndex &disjointListIndex::operator=(const disjointListIndex &newDjl) {
    *djl = *newDjl.djl;
    totalElem = newDjl.totalElem;
    return *this;
}

disjointListIndex::~disjointListIndex() {
    delete djl;
}

int disjointListIndex::find(string s) {
    return djl->find(s);
}

void disjointListIndex::makeSet(string s1, string s2) {
    djl->makeSet(s1,s2);
}

void disjointListIndex::Union(int loc1, int loc2) {
    djl->Union(loc1,loc2);
}

void disjointListIndex::unionIdx(string s, int loc) {
    djl->unionIdx(s,loc);
}

int disjointListIndex::getNumConnect() {
    return djl->getNumOfLists();
}

bool disjointListIndex::isAllinside() {
    return djl->numOfIdx() == totalElem;
}

void disjointListIndex::setNumOfElem(int numOfElem) {
    totalElem = numOfElem;
}
