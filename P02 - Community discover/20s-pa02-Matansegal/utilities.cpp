//
// Created by matan on 3/1/2020.
//

#include "utilities.h"
#include <string>

utilities::utilities() {

}

utilities::~utilities() {

}

void utilities::readCommands(string s) {
    ifstream input;
    input.open(s);

    if(!input.is_open()){
        cout << "Could not open command file!" << endl;
        return;
    }

    string command,val1,val2;
    bool dcOff = true;

    while(!input.eof()){
        input >> command;

        if(command == "or"){
            input >> val1;
            makeGraph(val1);
        }
        else if(command == "ow"){
            input >> val1;
            g.setOutput(val1);
        }
        else if(command == "dfs"){
            input >> val1;
            g.dfs(val1);
        } else if (command == "bfs"){
            input >> val1;
            g.bfs(val1);
        } else if (command == "mc"){
            input >> val1 >> val2;
            g.makeConnection(val1,val2);
        } else if (command == "dc" && dcOff){
            g.findCommunities();
            dcOff = false;
        } else {
            continue;
        }

    }

    input.close();

}

void utilities::makeGraph(string s) {
    ifstream input;
    input.open(s);

    if(!input.is_open()){
        cout << "Could not open graph file!" << endl;
        return;
    }

    // reading num of elements from the file
    string attributes;
    getline(input,attributes);
    int numOfelm = atoi(attributes.substr(1,attributes.size()-2).c_str());

    // reading all elements
    for (int i = 0; i < numOfelm; ++i) {
        getline(input,attributes);
        g.insertKey(attributes);
    }

    // reading king of the graph - directed/undirected
    string graphKind;
    bool undirected = false;
    getline(input,graphKind);
    if(graphKind == "[undirected]"){
        undirected = true;
    }

    string key, val, dash;

    // reading connections
    while(!input.eof()){
        input >> key >> dash >> val;
        // for handeling extra spaces
        if(input.eof()){
            break;
        }
        g.insertVal(key,val);
        if(undirected){
            g.insertVal(val,key);
        }
    }


    input.close();
}


