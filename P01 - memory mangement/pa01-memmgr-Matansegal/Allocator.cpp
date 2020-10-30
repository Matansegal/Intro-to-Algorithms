//
// Created by matan on 1/29/2020.
//

#include <iostream>
#include "Allocator.h"

using namespace std;


Allocator::Allocator(const size_t numOfMem) {
    totalMem = numOfMem;
    pool = malloc(numOfMem);
    if(MDEBUG){
        cout << "ALLOCATOR CONSTRUCTOR for " << totalMem << " bytes" << endl;
        cout << "Memory start at: " << pool << endl;
    }
    // to save the address as int in order to add to it
    poolAddress = *((int*)(&pool));

    next = 0;
}


Allocator::~Allocator() {

}

void Allocator::releaseMemory() {
    free(pool);

    // free bookKeep
    for (int i = 0; i < 100000; ++i) {
        int k = 0;
        while(BookKeep[i][k] != nullptr){
            free(BookKeep[i][k]);
            k++;
        }
    }

    //free freeList
    int k = 0;
    while( k < 10000){
        for (int i = 0; i < 100; ++i) {
            int n = 0;
            while(freeList[k+i][n] != nullptr){
                free(freeList[k+1][n]);
                n++;
            }
            // end of group
            break;
        }
        k += 100;
    }

}

void Allocator::freeMemory(void *p, bool isArray, int size) {

    // first check if array and look in the book keeping
    if(isArray){
        int startAddress = *((int*)(&p)) - poolAddress;
        // start address is the distance from the poolAddress
        // the index is every 2684 bytes
        int index = startAddress/2684;
        if(index >= 100000){index = 99999;}

        for (int i = 0; i < 671; ++i) {
//            if (BookKeep[index][i] == nullptr){
//                break;  // very bad if here...
//            }
            if (p == BookKeep[index][i]->getStartAdd()) {
                size = BookKeep[index][i]->getLength();
                // so it will free the address
                BookKeep[index][i]->setAddressNull();
                if (MDEBUG) { cout << "Got to the right place!!!!!" << endl; }
                break;
            }
        }
    }

    // add to the free list
    BookKeepingNode* b = (BookKeepingNode*)malloc(sizeof(BookKeepingNode));
    new(b) BookKeepingNode(p,size);

    //updateFreeAdds(b);
    addToFreeList(b);

}


void Allocator::addToFreeList(BookKeepingNode*& b) {
    int size = b->getLength();
    int startIndex = (size/400)*100;
    for (int j = startIndex; j < startIndex + 100; ++j) {
        // if did not find the same length and get to null, make one
        if(freeList[j][0] == nullptr){
            freeList[j][0] = b;
            break;
        }
        else if(freeList[j][0]->getLength() == size){
            int k = 1;
            // check for the free spot
            while(freeList[j][k] != nullptr){
                k++;
            }
            // store it in the free place
            freeList[j][k] = b;
            break;
        }
        // otherwise will keep the loop
    } // end for loop
}


void Allocator::updateFreeAdds(BookKeepingNode*& b) {
    void* p = b->getStartAdd();
    int size = b->getLength();
    int startAdd = (*((int*)(&p))-poolAddress);
    int index = startAdd/2684;
    addedToFreeAdd = false;
    // insert the start address and the size of it
    if (freeAddresses[index].size() > 0){
        itr = freeAddresses[index].begin();
        // see if continue of other free space
        while(itr != freeAddresses[index].end()){
            // if it is a continue of prev add
            if(itr->first + itr->second == startAdd){
                addedToFreeAdd = true;
                // delete from the freeList
                BookKeepingNode* prevNode = findFreelistItem(itr->second, (void*)(poolAddress+itr->first));
                // remove prevNode
                if(prevNode != nullptr){prevNode->setAddressNull();}

                // update b length and address
                itr->second += size;
                b->setLength(itr->second);
                b->setAddress((void*)(poolAddress+itr->first));
            }
            // if it continuing by other space
            else if(startAdd + size == itr->first){
                // delete from free list
                BookKeepingNode* prevNode2 = findFreelistItem(itr->second, (void*)(poolAddress+itr->first));
                // address stays the same, set new size
                b->setLength(size + itr->second);
                // remove prevNode
                if(prevNode2 != nullptr){
                    prevNode2->setAddressNull();
                }
                // insert the new one
                freeAddresses[index].insert({startAdd, (size + itr->second)});
                // remove from freeAdds
                freeAddresses[index].erase(itr);
                addedToFreeAdd = true;
            }
            if(addedToFreeAdd){break;}
            itr++;
        }
    }
    if(!addedToFreeAdd){
        freeAddresses[index].insert({startAdd, size});
    }

}

// two option - one for erasing when we send an address
// second for just finding a new position when do not send address
BookKeepingNode* Allocator::findFreelistItem(int bytes, void* startAdd) {
    int startIndex = (bytes/400)*100;
    for (int i = startIndex; i < startIndex + 100; ++i) {
        // check if the group contains nodes
        if(freeList[i][0] == nullptr){
            break;
        }
        if(freeList[i][0]->getLength() >= bytes){
            int k = 0;
            while(freeList[i][k] != nullptr){
                // if found larger spot
                if(freeList[i][k]->getStartAdd() != nullptr){
                    // if doesnt care about address - for the fir
                    if(startAdd == nullptr){
                        return freeList[i][k];
                    }
                    // if do care about the address - for erasing
                    else if (startAdd == freeList[i][k]->getStartAdd()){
                        return freeList[i][k];
                    }

                }
                k++;
            } // end of inner while
        }
    } // end of for loop
    return nullptr;
}

int Allocator::getNext() {
    return next;
}





