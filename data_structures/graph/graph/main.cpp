//
//  graph.cpp
//
//  Created by Masatoshi Nishiguchi on 12/7/15.
//  Copyright © 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

class OurGraph {
public:
    std::list<int>* graph;  // C++ list

    OurGraph();
    ~OurGraph();

    void createGraph();

};


//Constructor
OurGraph::OurGraph() {

    graph = new list<int>[4];

}


// OurGraph::OurGraph(int size) {
//     maxSize = size;
//     gSize = 0;
//     graph = new unorderedLinkedList<int>[size];
// }


//Destructor
OurGraph::~OurGraph() {

    delete graph;

}


/**
 *
 */
void OurGraph::createGraph() {

    // We hardcode the each node.

    graph[ 0 ].push_back( 1 );
    graph[ 0 ].push_back( 2 );
    graph[ 0 ].push_back( 3 );
    graph[ 1 ].push_back( 4 );

    list<int>::iterator it;
    for (it = graph[ 2 ].begin(); it != graph[ 2 ].end(); it++) {

        cout << "Vertex: " << *it << endl;

    }
}


/**
 * @return
 */
int main() {

    OurGraph graph;

    graph.createGraph();


    return 0;
}
