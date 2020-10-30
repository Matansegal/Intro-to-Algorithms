//
// Created by matan on 2/1/2020.
//

#include "MyFit.h"


MyFit::MyFit(size_t unnamed) : Allocator(unnamed) {
    if(MDEBUG) { cout << "MyFit CONSTRUCTOR " << endl;}
}

MyFit::~MyFit() {

}

// in my Fit it will keep use the memory until it will get to the break point (end of the allocated heap),
// then it will start to use the free locations
void *MyFit::addToMemory(size_t bytes, bool isArray) {
    // make it fit a 4 bytes block
    if(bytes % 4 != 0){
        bytes += 4 - (bytes % 4);
    }
    bool reUsedMem = false;
    void* returnVal = (void*)(poolAddress + next);
    // check if get to the break point
    if((next + bytes) > totalMem){
        // use first fit implamentation
        void* p = reuseFreeList(bytes);
        if(p != nullptr) {
            if(MDEBUG){cout << "start location -- " << p << "  num of bytes: " << bytes << endl;} // FOR TEST
            returnVal = p;
            reUsedMem = true;
        }
        cout << " NO MORE MEMORY!!" << endl;
        return nullptr;
    }

    // if array it will add it to the book keeping
    if(isArray){
        BookKeepingNode* b = (BookKeepingNode*)malloc(sizeof(BookKeepingNode));
        new(b) BookKeepingNode(returnVal,bytes);
        // next is the start address of the array
        // the index is every 2684 bytes
        int index = (*((int*)(&returnVal))-poolAddress)/2684;
        for (int i = 0; i < 671; ++i) {
            if(BookKeep[index][i] == nullptr){
                BookKeep[index][i] = b;
                break;
            }
        }
    }


    if(MDEBUG){cout << "start location -- " << returnVal << "  num of bytes: " << bytes << endl;} // FOR TEST

    if(!reUsedMem){next += bytes;}
    return returnVal;
}

void *MyFit::reuseFreeList(size_t bytes) {
    int startIndex = (bytes/400)*100;
    if (startIndex > 10000) {startIndex = 9900;}
    void* p;

    while(startIndex < 10000){
        // if find spot k is not null
        BookKeepingNode* k = findFreelistItem(bytes);
        // if found, update the size of it
        if(k != nullptr) {
            p = k->getStartAdd();
            int freeNodeSize = k->getLength();
            int startAdd = (*((int*)(&p))-poolAddress + freeNodeSize);
            int index = startAdd/2684;
            // add to freeAdds
            freeAddresses[index].insert(pair<int, int>(startAdd, freeNodeSize - bytes));
            // make a new node for the free list with the adjasted size
            BookKeepingNode* b = (BookKeepingNode*)malloc(sizeof(BookKeepingNode));
            new(b) BookKeepingNode(p,freeNodeSize - bytes);
            addToFreeList(b);
            return p;
        }
        // if did not return yet, move to the next group:
        startIndex += 100;
    }
    // when there is no free spots in the free list return null
    return nullptr;
}


