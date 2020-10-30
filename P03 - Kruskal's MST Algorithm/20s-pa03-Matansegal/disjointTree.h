//
// Created by matan on 4/9/2020.
//

#ifndef INC_20S_PA03_MATANSEGAL_DISJOINTTREE_H
#define INC_20S_PA03_MATANSEGAL_DISJOINTTREE_H

#include <set>

using namespace std;

template<class T>
class Node {
    template<class u> friend class disjointTree;
public:
    //Node():parent(this),rank(0),numOfElem(1){}
    Node(T val, int loc):parent(this),data(val),rank(0),numOfElem(1),locInList(loc){}
    Node(const Node<T>& d2):parent(this),data(d2.data),
            rank(d2.rank),numOfElem(d2.numOfElem),locInList(d2.locInList){}

private:
    // initialize parent to itself
    Node<T>* parent;
    T data;
    int rank;
    // if the root, will have more than one
    int numOfElem;
    int locInList;

};

template<class T>
class disjointTree {
private:
    // array contain pointer to all the nodes
    // contain certain order as specify in the disjointTreeIndex
    // if == nullptr, nit in the disjoint, if point to itself - it is the root
    Node<T>** refferingList;
    int size;
    int totElem;
    // set contain the index of the roots
    set<int> rootList;

public:
    // accept the number of elemnts
    disjointTree(int);
    disjointTree(const disjointTree<T>&);
    disjointTree<T>& operator=(const disjointTree<T>&);
    ~disjointTree();
    // accept location in the array
    // return the parent
    int find(int);
    void makeSet(T,int,T,int);
    void Union(int,int);
    void unionIdx(T,int,int);
    int numOfIdx();
    int getNumOfLists();
};

template<class T>
disjointTree<T>::disjointTree(int numOfelm) {
    totElem = numOfelm;
    size = 0;
    refferingList = new Node<T>*[numOfelm];
    // initialize all to nullptr
    for (int k = 0 ; k < numOfelm ; k++){
        refferingList[k] = nullptr;
    }
}

template<class T>
disjointTree<T>::disjointTree(const disjointTree<T> &djt) {
    size = djt.size;
    totElem = djt.totElem;
    for (int i = 0; i < totElem; ++i) {
        if(djt.refferingList[i] == nullptr){
            refferingList[i] = nullptr;
        } else {
            Node<T>* newNode = new Node<T>(*djt.refferingList[i]);
            refferingList[i] = &newNode;
            // if root, push to the root list
            if(refferingList[i] == refferingList[i]->parent){
                rootList.insert(i);
            }
        }
    }
}

template<class T>
disjointTree<T> &disjointTree<T>::operator=(const disjointTree<T> &djt) {
    size = djt.size;
    totElem = djt.totElem;
    for (int i = 0; i < totElem; ++i) {
        if(djt.refferingList[i] == nullptr){
            refferingList[i] = nullptr;
        } else {
            Node<T>* newNode = new Node<T>(*djt.refferingList[i]);
            refferingList[i] = &newNode;
            // if root, push to the root list
            if(refferingList[i] == refferingList[i]->parent){
                rootList.insert(i);
            }
        }
    }
    return *this;
}

template<class T>
disjointTree<T>::~disjointTree() {
    for (int i = 0; i < totElem; ++i) {
        delete refferingList[i];
    }
    delete [] refferingList;
}

template<class T>
int disjointTree<T>::find(int loc) {
    // if null - not in the disjoint
    if(refferingList[loc] == nullptr){
        return -1;
    }
    // if the parent of itself - it is the root
    else if(refferingList[loc] == refferingList[loc]->parent){
        return loc;
    } else{
        // loop to find parent
        Node<T>* temp = refferingList[loc];
        while(temp != temp->parent){
            temp = temp->parent;
        }
        refferingList[loc]->parent = temp;
        // return the location of the parent
        return temp->locInList;
    }
}

template<class T>
void disjointTree<T>::makeSet(T a, int loc1, T b, int loc2) {
    Node<T>* newNode1 = new Node<T>(a,loc1);
    refferingList[loc1] = newNode1;
    Node<T>* newNode2 = new Node<T>(b,loc2);
    refferingList[loc2] = newNode2;

    // node 1 is the root
    newNode2->parent = newNode1;
    newNode1->rank++;
    newNode1->numOfElem++;

    rootList.insert(loc1);
    size += 2;
}

template<class T>
void disjointTree<T>::Union(int a, int b) {
    Node<T>* root1 = refferingList[a];
    Node<T>* root2 = refferingList[b];

    // check which root has higher rank
    if (root1->rank > root2->rank){
        root2->parent=root1;
        root1->numOfElem += root2->numOfElem;
        rootList.erase(b);
    } else {
        root1->parent=root2;
        root2->numOfElem += root1->numOfElem;
        rootList.erase(a);
        // if equal rank, incraemnt
        if(root1->rank == root2->rank) root2->rank++;
    }
}

template<class T>
void disjointTree<T>::unionIdx(T a, int loc1, int loc2) {
    Node<T>* newNode1 = new Node<T>(a,loc1);
    refferingList[loc1] = newNode1;

    newNode1->parent = refferingList[loc2];
    refferingList[loc2]->numOfElem++;
    size++;
}

template<class T>
int disjointTree<T>::numOfIdx() {
    return size;
}

template<class T>
int disjointTree<T>::getNumOfLists() {
    return rootList.size();
}


#endif //INC_20S_PA03_MATANSEGAL_DISJOINTTREE_H
