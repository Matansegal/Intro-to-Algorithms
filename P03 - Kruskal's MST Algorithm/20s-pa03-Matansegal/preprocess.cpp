//
// Created by matan on 4/10/2020.
//

#include "preprocess.h"
#include <chrono>

preprocess::preprocess(string file) {
    ifstream input;
    input.open(file);

    if(!input.is_open()){
        cout << "Could not open " << file << endl;
        return;
    }

    // reading num of elements from the file
    input >> numOfelm;

    string index;

    // reading all elements
    for (int i = 0; i < numOfelm; ++i) {
        input >> index;
        indexList.insert(index);
    }

    string idx1, idx2;
    int weight;

    // reading edges
    while(!input.eof()){
        input >> idx1 >> weight >> idx2;
        // for handeling extra spaces
        if(input.eof()) break;

        edge<string> e = edge<string>(idx1, weight, idx2);
        edgesList.insert(e);
    }

    input.close();

    // open output file
    ofstream output;
    string out = file.substr(11);
    out = out.substr(0, out.size()-4);
    output.open( out + "_out.txt"); // "outputFiles/" +
    if(!output.is_open()){
        cout << "Could not open output " << out << endl;
        return;
    }

    utilities utilTree("TREE",numOfelm);
    utilities utilList("LIST",numOfelm);

    output << "============= " << out << " =============" <<endl;
    // strings that will return from the kruskal
    string s1,s2;

    auto t1 = chrono::high_resolution_clock::now();
    utilTree.kruskals(edgesList, s1);
    auto t2 = chrono::high_resolution_clock::now();
    auto totTime =chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    output << "Took: " << totTime << " microsec" << endl;
    output << s1 << endl;

    cout << file << "\n  Tree: " << totTime << endl;


    t1 = chrono::high_resolution_clock::now();
    utilList.kruskals(edgesList, s2);
    t2 = chrono::high_resolution_clock::now();
    totTime =chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    output << "Took: " << totTime << " microsec" << endl;
    output << s2 << endl;

    cout << "  List: " << totTime << endl;

    output.close();
}
