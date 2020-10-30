//
// Created by matan on 3/1/2020.
//

#ifndef INC_20S_PA02_MATANSEGAL_GRAPHNODE_H
#define INC_20S_PA02_MATANSEGAL_GRAPHNODE_H

#include <vector>

using namespace std;

template <typename T>
class graphNode{
private:
    T value;
    vector<graphNode<T>*> connection;

    // for searching Algs.
    int disToStart;
    vector<graphNode<T>*> fromNodes;
    vector<graphNode<T>*> children;
    bool visited;
    // for Girvan Newman
    double points;

public:
    graphNode(T&);
    ~graphNode();
    T getValue();
    void addConnection(graphNode<T>*);
    vector<graphNode<T>*>& getConnection();
    void eraseConnection(int);

    // functions for searching Algorithms:
    int getDis();
    void setDis(int);
    void addFromNode(graphNode<T>*);
    vector<graphNode<T>*>& getFromNode();
    void addChild(graphNode<T>*);
    vector<graphNode<T>*>& getChildren();
    bool isVisited();
    void setToVisited();
    void setPoints(double);
    double getPoints();
    void incPoints(double);
    // reset all the search elements
    void resetNode();


};

template<typename T>
graphNode<T>::graphNode(T& v) {
    value = v;
    disToStart = -1;
    visited = false;
    points = 0;
}

template<typename T>
graphNode<T>::~graphNode() {
    // dont need to delete because it is deleted in graph class
}

template<typename T>
T graphNode<T>::getValue() {
    return value;
}

template<typename T>
void graphNode<T>::addConnection(graphNode<T>* n) {
    connection.push_back(n);
}

template<typename T>
vector<graphNode<T> *> &graphNode<T>::getConnection() {
    return connection;
}

template<typename T>
void graphNode<T>::setToVisited() {
    visited = true;
}

template<typename T>
int graphNode<T>::getDis() {
    return disToStart;
}

template<typename T>
void graphNode<T>::setDis(int d) {
    disToStart = d;
}

template<typename T>
void graphNode<T>::addFromNode(graphNode<T>* n) {
    fromNodes.push_back(n);
}

template<typename T>
vector<graphNode<T> *> &graphNode<T>::getFromNode() {
    return fromNodes;
}

template<typename T>
void graphNode<T>::resetNode() {
    fromNodes.clear();
    children.clear();
    disToStart = -1;
    visited = false;
    points = 0;
}

template<typename T>
bool graphNode<T>::isVisited(){
    return visited;
}

template<typename T>
void graphNode<T>::addChild(graphNode<T> *n) {
    children.push_back(n);
}

template<typename T>
vector<graphNode<T> *> &graphNode<T>::getChildren() {
    return children;
}

template<typename T>
void graphNode<T>::setPoints(double p) {
    points = p;
}

template<typename T>
double graphNode<T>::getPoints() {
    return points;
}

template<typename T>
void graphNode<T>::incPoints(double p) {
    points += p;
}

template<typename T>
void graphNode<T>::eraseConnection(int i) {
    connection.erase(connection.begin()+i);
}


#endif //INC_20S_PA02_MATANSEGAL_GRAPHNODE_H
