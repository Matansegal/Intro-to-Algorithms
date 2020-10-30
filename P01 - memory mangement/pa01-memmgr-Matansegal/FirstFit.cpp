//
// Created by matan on 2/1/2020.
//

#include "FirstFit.h"

FirstFit::FirstFit(size_t unnamed) : Allocator(unnamed) {
    if(MDEBUG) { cout << "FirstFit CONSTRUCTOR " << endl;}
}

FirstFit::~FirstFit() {

}

void *FirstFit::addToMemory(size_t bytes, bool isArray) {
    // make it fit a 4 bytes block
    if(bytes % 4 != 0){
        bytes += 4 - (bytes % 4);
    }
    bool reUsedMem = false;
    void* returnVal = (void*)(poolAddress + next);

    // check for free list positions
    void* p = reuseFreeList(bytes);
    if(p != nullptr) {
        returnVal = p;
        reUsedMem = true;
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

    // if there is no enough space
    if(next + bytes > totalMem && !reUsedMem){
        cout << " NO MORE MEMORY!!" << endl;
        return nullptr;
    }

    if(MDEBUG){cout << "start location -- " << returnVal << "  num of bytes: " << bytes << endl;} // FOR TEST

    if(!reUsedMem){next += bytes;}
    return returnVal;
}

void *FirstFit::reuseFreeList(int bytes) {
    int startIndex = (bytes/400)*100;
    if (startIndex >= 10000) {startIndex = 9900;}
    void* p;

    while(startIndex < 10000){
        // if find spot k is not null
        BookKeepingNode* k = findFreelistItem(bytes);
        // if found, update the size of it
        if(k != nullptr) {
            p = k->getStartAdd();
            int freeNodeSize = k->getLength();
            int newFreeSpotAdd = (*((int*)(&p))-poolAddress + bytes);
            int indexToRemove = (*((int*)(&p))-poolAddress)/2684;
            int index = newFreeSpotAdd/2684;
            void* freeNodeNewAdd = (void*)(poolAddress+bytes);
            // remove from free list
            k->setAddressNull();
            // remove from freeAdds
            freeAddresses[indexToRemove].erase((*((int*)(&p))-poolAddress));
            if(freeNodeSize - bytes > 0){
                // add to freeAdds
                freeAddresses[index].insert(pair<int, int>(newFreeSpotAdd, freeNodeSize - bytes));
                // make a new node for the free list with the adjasted size
                BookKeepingNode* b = (BookKeepingNode*)malloc(sizeof(BookKeepingNode));
                new(b) BookKeepingNode(freeNodeNewAdd,freeNodeSize - bytes);
                addToFreeList(b);
            }
            return p;
        }
        // if did not return yet, move to the next group:
        startIndex += 100;
    }
    // when there is no free spots in the free list return null
    return nullptr;
}




