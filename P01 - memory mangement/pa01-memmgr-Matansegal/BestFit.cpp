//
// Created by matan on 2/1/2020.
//

#include "BestFit.h"

BestFit::BestFit(size_t unnamed) : Allocator(unnamed) {
    if(MDEBUG) { cout << "BestFit CONSTRUCTOR " << endl;}
}

BestFit::~BestFit() {

}

void *BestFit::addToMemory(size_t bytes, bool isArray) {
    // make it fit a 4 bytes block
    if(bytes % 4 != 0){
        bytes += 4 - (bytes % 4);
    }
    bool reUsedMem = false;
    void* returnVal = (void*)(poolAddress + next);

    // check for best free list positions
    void* p = bestReuseFreeList(bytes);
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
    if((next + bytes) > totalMem){
        cout << " NO MORE MEMORY!!" << endl;
        return nullptr;
    }

    if(MDEBUG){cout << "start location -- " << returnVal << "  num of bytes: " << bytes << endl;} // FOR TEST

    if(!reUsedMem){next += bytes;}
    return returnVal;
}

void *BestFit::bestReuseFreeList(size_t bytes) {
    bool foundPlace = false;
    int startIndex = (bytes/400)*100;
    if (startIndex > 10000) {startIndex = 9900;}
    void* p = nullptr;
    BookKeepingNode* bestFit = nullptr;

    while(!foundPlace && startIndex < 10000){

        for (int i = startIndex; i < startIndex + 100; ++i) {
            // check if the group contains nodes
            if(freeList[i][0] == nullptr){
                break;
            }
            if(freeList[i][0]->getLength() >= bytes){
                int k = 0;
                // while in the second dimension
                while(freeList[i][k] != nullptr){
                    // if found larger spot, check if already used (if it null)
                    if(freeList[i][k]->getStartAdd() != nullptr){
                        // initialize it on the first time
                        if(bestFit == nullptr) {bestFit = freeList[i][k];}
                        else if (bestFit->getLength() > freeList[i][k]->getLength()){
                            bestFit = freeList[i][k];
                            p = bestFit->getStartAdd();
                        }
                    }
                    k++;
                } // end of inner while
            }
        } // end for loop
        if(p != nullptr){
            int freeNodeSize = bestFit->getLength();
            // if does not fit completely, adjast the freelist and the feeAdds
            if (freeNodeSize - bytes > 0){
                int startAdd = (*((int*)(&p))-poolAddress + freeNodeSize);
                int index = startAdd/2684;
                // add to freeAdds
                freeAddresses[index].insert(pair<int, int>(startAdd, freeNodeSize - bytes));
                // make a new node for the free list with the adjasted size
                BookKeepingNode* b = (BookKeepingNode*)malloc(sizeof(BookKeepingNode));
                new(b) BookKeepingNode(p,freeNodeSize - bytes);
                addToFreeList(b);
            }
            bestFit->setAddressNull();
            return p;
        }
        // if did not return yet, move to the next group:
        startIndex += 100;
    } // end outer while
    // when there is no fir spots in the free list return null
    return nullptr;
}




