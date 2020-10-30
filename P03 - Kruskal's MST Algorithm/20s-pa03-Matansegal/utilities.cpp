//
// Created by matan on 3/1/2020.
//

#include <iostream>
#include "utilities.h"
#include <chrono>

using namespace std;

utilities::utilities(string s, int numOfelm) {
    type = s;
    if (type == "LIST"){
        djli = new disjointListIndex;
    } else if (type == "TREE"){
        djli = new disjointTreeIndex;
    }
    djli->setNumOfElem(numOfelm);
}

utilities::~utilities() {
    delete djli;
}

void utilities::kruskals(multiset<edge<string>> &edgesList, string& toReturn) {

    multiset<edge<string>>::iterator it;
    it = edgesList.begin();
    // djli need to have the same number of indexes as the index list
    // and need to have only 1 connection in the disjoint

    int i = 0;
    while(!(djli->getNumConnect() == 1 && djli->isAllinside())){
        // can do the while loop until mst.size == numElem - 1
        string idx1 = it->getIndex1();
        string idx2 = it->getIndex2();

        int found1 = djli->find(idx1);
        int found2 = djli->find(idx2);

        // if both not in the disjoint
        if ((found1 == -1) && (found2 == -1)){
            djli->makeSet(idx1,idx2);
            // inser to the min spanning tree edges
            mst.insert(*it);
        }
        // if just 1 in the disjoint
        else if (found1 != -1 && found2 == -1){
            djli->unionIdx(idx2,found1);
            mst.insert(*it);
        }
        // if just 2 in
        else if (found1 == -1 && found2 != -1){
            djli->unionIdx(idx1,found2);
            mst.insert(*it);
        }
        // if both in disjoint but not on the same connection, union
        else if (found1 != found2) {
            djli->Union(found1,found2);
            mst.insert(*it);
        }
        // move to next element in the list
        if( it!=--edgesList.end()) it++;
    }

    // add to the returning string
    toReturn += "Using " + type + " type disjoint set\n";
    toReturn += "MST size: " + to_string(mst.size()) + ", total weight: " +
            to_string(getMSTweight()) + "\n";
    set<edge<string>>::iterator it2;
    for (it2=mst.begin(); it2!=mst.end(); ++it2)
        toReturn += it2->print()  + "\n";
}

int utilities::getMSTweight() {
    int totWeight = 0;
    set<edge<string>>::iterator it2;
    for (it2=mst.begin(); it2!=mst.end(); ++it2)
        totWeight += it2->getWeight();
    return totWeight;
}


