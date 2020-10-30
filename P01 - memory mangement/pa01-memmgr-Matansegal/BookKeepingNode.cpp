//
// Created by matan on 1/30/2020.
//
#include <iostream>
#include "BookKeepingNode.h"

using namespace std;

BookKeepingNode::BookKeepingNode(void *s, int l){
    length = l;
    startAdd = s;
    lastElm = true;
    if(MDEBUG) {
        cout << "BookKeepingnode" << endl;
        cout << "initialize book keeping at: " << startAdd << " for " << length << endl;
        if (length <= 0){
            cout << "WAHTT??" << endl;
        }
    }
}

BookKeepingNode::~BookKeepingNode() {
    if(MDEBUG){cout << "DESTRUCTOR BookKeepingnode" << endl;}

}

void *BookKeepingNode::getStartAdd() {
    return startAdd;
}

int BookKeepingNode::getLength() {
    return length;
}

void BookKeepingNode::setAddressNull() {
    startAdd = nullptr;
}

void BookKeepingNode::setAddress(void *p) {
    startAdd = p;
}

void BookKeepingNode::setLength(int newLen) {
    length = newLen;
}

bool BookKeepingNode::isLastElm() {
    return lastElm;
}

void BookKeepingNode::setLastElmFalse() {
    lastElm = false;
}





