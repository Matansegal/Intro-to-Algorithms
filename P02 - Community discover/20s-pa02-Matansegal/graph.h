//
// Created by matan on 3/1/2020.
//

#ifndef INC_20S_PA02_MATANSEGAL_GRAPH_H
#define INC_20S_PA02_MATANSEGAL_GRAPH_H

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include "graphNode.h"
#include "edge.h"
#include <set>

using namespace std;

template <typename T>
class graph{
private:
    // key is the element itself, the value is the node
    map<T,graphNode<T>*> hashList;
    // stack for the dfs
    stack<graphNode<T>*> stc;
    // inner function for dfs
    void dfsLoop(graphNode<T>*);
    // ordered map of the edges
    // the value is a pair of <cumulative betweenness, temporary beetweenness>
    map<edge<T>,pair<double,double>> edges;
    void GirvanNewman();
    ofstream output;

public:
    graph();
    graph(const graph<T>&);
    graph<T>& operator=(const graph<T>&);
    ~graph();
    void insertKey(T&);
    void insertVal(T&, T&);
    void print();
    void bfs(T, bool reset = true);
    void dfs(T, bool reset = true);
    void makeConnection(T,T);
    void findCommunities();
    void setOutput(string);

};

template<typename T>
graph<T>::graph() {

}

template<typename T>
graph<T>::graph(const graph<T> &g) {
    this->hashList = g.hashList;
}

template<typename T>
graph<T> &graph<T>::operator=(const graph<T>& g) {
    this->hashList = g.hashList;
    return *this;
}

template<typename T>
graph<T>::~graph() {
    // delete the ptr to the vectors
    for (auto& x: hashList) {
        delete x.second;
    }
    output.close();
}

template<typename T>
void graph<T>::insertKey(T &newKey) {
    graphNode<T>* n = new graphNode<T>(newKey);
    hashList.insert({newKey,n});
}

template<typename T>
void graph<T>::insertVal(T &key, T &val) {
    (hashList.find(key)->second)->addConnection(hashList.find(val)->second);
    // make the edge
    edge<T> e(key,val);
    pair<double,double> p(0.0,0.0);
    edges.insert(pair<edge<T>,pair<double,double>>(e,p));
}

// for testing
template<typename T>
void graph<T>::print() {
    for (auto& x: hashList) {
        cout << x.first << " : ";
        vector<graphNode<T> *> v = x.second->getConnection();
        for (size_t j = 0; j < v.size(); ++j) {
            cout << v.at(j)->getValue() << ", ";
        }
        cout << endl;
    }
    cout << "---------------edges-------------" << endl;
    for (auto& x: edges){
        cout << x.first.print() << endl;
    }
}

template<typename T>
void graph<T>::bfs(T startKey, bool reset) {
    // check if the startKey is in the graph
    if( hashList.find(startKey) == hashList.end()){
        cout << "Given key for bfs is not in the graph!!" << endl;
        return;
    }

    queue<graphNode<T>*> q;
    int dis = 0;
    // set active to the graphNode of the given start value
    graphNode<T>* active = hashList.find(startKey)->second;
    q.push(active);
    // set its distance to 0
    active->setDis(dis);
    vector<graphNode<T>*> connections;

    while(!q.empty()){
        // get its connection list
        connections = active->getConnection();
        //active->setToActiv();
        dis = active->getDis() + 1;
        // looking at all its connections
        for (auto& x: connections) {
            // if node that was not visited, its distance = -1, so set it
            if(x->getDis() == -1){
                x->setDis(dis);
                x->addFromNode(active);
                active->addChild(x);
                q.push(x);
            }
            // if node with the same distance, add to the from list
            else if(x->getDis() == dis){ // should I add && not activated?
                x->addFromNode(active);
                active->addChild(x);
            }
        }

        q.pop();
        // activate next node
        if(!q.empty()){
            active = q.front();
        }

    } // end while

    // -----------------------print-------------------------
    if(reset){
        output << "----------------bfs---------------" << endl;
        string toPrint = "{";
        for(auto& x : hashList){
            for(auto& k : x.second->getChildren()){
                toPrint += "(" + x.first + " - " + k->getValue() + "), ";
            }
        }
        // to remove last ,:
        toPrint[toPrint.size()-2] = '}';
        output << toPrint << endl << endl;
    }
    // --------------------------------------------------------------

    // for next searches
    if(reset){
        for(auto& x : hashList){
            x.second->resetNode();
        }
    }


}

template<typename T>
void graph<T>::dfs(T startKey, bool reset) {
    // check if the startKey is in the graph
    if( hashList.find(startKey) == hashList.end()){
        cout << "Given key for dfs is not in the graph!!" << endl;
        return;
    }

    // set active to the graphNode of the given start value
    graphNode<T>* active = hashList.find(startKey)->second;
    stc.push(active);
    // set its distance to 0
    active->setDis(0);
    // calling recursive function
    dfsLoop(active);

    //  ----------------------- print ------------------------------
    if(reset){
        output << "----------------dfs---------------" << endl;
        string toPrint = "{";
        for(auto& x : hashList){
            for(auto& k : x.second->getChildren()){
                toPrint += "(" + x.first + " - " + k->getValue() + "), ";
            }
        }
        // to remove last ,:
        toPrint[toPrint.size()-2] = '}';
        output << toPrint << endl << endl;
    }
    // --------------------------------------------------------------

    // for next searches
    if(reset){
        for(auto& x : hashList){
            x.second->resetNode();
        }
    }

}

// the recursive function for the dfs
template<typename T>
void graph<T>::dfsLoop(graphNode<T>* act) {
    // base case
    if(stc.empty()){
        return;
    }

    vector<graphNode<T>*> connections;
    connections = act->getConnection();
    int dis = act->getDis() + 1;
    for (auto& x: connections){
        // if not visited
        if(x->getDis() == -1 || dis < x->getDis()){
            x->setDis(dis);
            x->addFromNode(act);
            act->addChild(x);
            stc.push(x);
        }
    }

    // recursion call
    act = stc.top();
    stc.pop();
    dfsLoop(act);
}

template<typename T>
void graph<T>::makeConnection(T start, T end) {
    dfs(start, false);
    graphNode<T>* stepBack = hashList.find(end)->second;
    string toPrint = "";
    // while it didnt get to the start node
    while(stepBack->getDis() != 0){
        // previous node
        T prev = stepBack->getFromNode().back()->getValue();
        // add it in reverse order to the string
        toPrint = "(" + prev + " - " + stepBack->getValue() + "), " + toPrint;
        // go back Word one step
        stepBack = stepBack->getFromNode().back();
    }
    // to remove last ,:
    toPrint[toPrint.size()-2] = '}';
    toPrint = "{" + toPrint;
    output << "----------Make a Connection---------" << endl;
    output << toPrint << endl << endl;

    // resetting because send not to reset in the dfs
    for(auto& x : hashList){
        x.second->resetNode();
    }
}

template<typename T>
void graph<T>::GirvanNewman() {
    // for loop through all the nodes
    for(auto& x : hashList){
        bfs(x.first, false);
        int level = 0;
        // if no children = a leaf, set points to 1
        for(auto& k: hashList){
            if(k.second->getChildren().size() == 0){
                // updated max level
                if(level < k.second->getDis()){
                    level = k.second->getDis();
                }
                k.second->setPoints(1.0);
                vector<graphNode<T>*> parents = k.second->getFromNode();
                double edgePoints = 1.0/(double)parents.size();
                // increment all the edges points by 1 over the number of parents to that node
                for (size_t i = 0; i < parents.size(); ++i) {
                    edge<T> e(k.first,parents.at(i)->getValue());
                    edges.find(e)->second.second += edgePoints;

                }
            }
        } // end for loop of leaves
        level--;
        // start a loop level by level, until get to the root
        while(level > 0){
            for(auto& k: hashList){
                if(k.second->getDis() == level){
                    k.second->setPoints(1.0);
                    // add the sum of the edges to it
                    for(auto& e: edges){
                        if(e.first.contains(k.first)){
                            k.second->incPoints(e.second.second);
                        }
                    }
                    vector<graphNode<T>*> parents = k.second->getFromNode();
                    double edgePoints = k.second->getPoints()/(double)parents.size();
                    // increment all the edges points by the node points over the number of parents to that node
                    for (size_t i = 0; i < parents.size(); ++i) {
                        edge<T> e(k.first,parents.at(i)->getValue());
                        edges.find(e)->second.second += edgePoints;
                    }
                }// end if in this level
            }

            level--;
        } // end while loop

        // resetting the values of the edges but update the cumilative values in the object edge
        for(auto& e: edges){
            e.second.first += e.second.second;
            e.second.second = 0;
        }

        // reset all nodes
        for(auto& x : hashList){
            x.second->resetNode();
        }
    } // end outer loop

}

template<typename T>
void graph<T>::findCommunities() {
    // set all the betweenness values
    GirvanNewman();
    // i decided 40% because it make the most sense with the football data
    int edgesToRemove = edges.size() * 0.3;
    edge<T>* highestBet = new edge<T>[edgesToRemove];
    // loop for removing highest betweenness
    for (int i = 0; i < edgesToRemove; ++i) {
        double highest = 0.0;
        for(auto& x: edges){
            if(x.second.first > highest){
                highest = x.second.first;
                highestBet[i] = x.first;
            }
        }
        // remove from the list
        edges.erase(edges.find(highestBet[i]));
    } // end outer for loop

    // remove the connections from the nodes
    for(auto& x: hashList){
        vector<graphNode<T>*> connect = x.second->getConnection();
        // count the removed nodes so it wont go out of boundary
        int removedCounter = 0;
        for (size_t i = 0; i < connect.size(); ++i) {
            edge<T> e(x.first,connect.at(i)->getValue());
            // loop through the remove list
            for (int j = 0; j < edgesToRemove; ++j) {
                if(e == highestBet[j]){
                    //connect.erase(connect.begin()+i);
                    x.second->eraseConnection(i - removedCounter);
                    removedCounter++;
                }
            }
        }
    } // finish outer loop

    output << "--------Discover Communities---------" << endl;
    // now make bfs again to separate to communities:
    int comNum = 0;
    // set of printed element
    set<T> printed;
    for(auto& x: hashList){
        // if was not include in any bfs before
        if(x.second->getDis() == -1){
            output << "\nCommunity number " << ++comNum << ":" << endl;
            bfs(x.first, false);
            //print names in community:
            for(auto& k : hashList){
                // if distance is not -1 and not in the printed list, print it
                if(k.second->getDis() != -1 && printed.find(k.first) == printed.end()){
                    output << k.first << endl;
                    printed.insert(k.first);
                }
            } // end inner for loop
        }
    }
    delete [] highestBet;
}

template<typename T>
void graph<T>::setOutput(string s) {
    output.open(s);
}


#endif //INC_20S_PA02_MATANSEGAL_GRAPH_H
