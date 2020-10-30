//
// Created by matan on 4/9/2020.
//

#include "disjointTreeIndex.h"
#include <math.h>
#include <iostream>

disjointTreeIndex::disjointTreeIndex() {
    // I initialize the djt in the get total element function
}

disjointTreeIndex::disjointTreeIndex(const disjointTreeIndex &djti) {
    djt=djti.djt;
    totalElem = djti.totalElem;
}

disjointTreeIndex &disjointTreeIndex::operator=(const disjointTreeIndex &djti) {
    djt=djti.djt;
    totalElem = djti.totalElem;
    return *this;
}

disjointTreeIndex::~disjointTreeIndex() {
    delete djt;
}

int disjointTreeIndex::find(string s) {
    int loc = stringToint(s);
    int retVal = djt->find(loc);
    return retVal;
}

void disjointTreeIndex::makeSet(string s1, string s2) {
    int loc1 = stringToint(s1);
    int loc2 = stringToint(s2);
    djt->makeSet(s1,loc1,s2,loc2);
}

void disjointTreeIndex::Union(int loc1, int loc2) {
    djt->Union(loc1,loc2);
}

void disjointTreeIndex::unionIdx(string s1, int loc) {
    int idxLoc = stringToint(s1);
    djt->unionIdx(s1,idxLoc,loc);
}

int disjointTreeIndex::getNumConnect() {
    return djt->getNumOfLists();
}

bool disjointTreeIndex::isAllinside() {
    return djt->numOfIdx() == totalElem;
}

void disjointTreeIndex::setNumOfElem(int numOfelm) {
    totalElem = numOfelm;
    djt = new disjointTree<string>(totalElem);
}

int disjointTreeIndex::stringToint(string s) {
    int val = 0 ;
    int l= s.length();
    // using ascii value A = 65
    // so the string A is location 0, AA location 26
    if(l == 1) {
        val = s[0] - 65;
    } else if (l == 2) {
        val = (s[0] - 64) * 26 + (s[1] - 65);
    }
    return val;

    // general case
//    for ( int i = 0; i < l ; i++){
//        val +=  (s[i] - 64) * pow(26,(l-i-1));
//    }
}
