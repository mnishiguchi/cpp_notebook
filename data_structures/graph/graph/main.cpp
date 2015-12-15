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
    void depthFirstTraversal();
    void dft(int v, bool visited[]);

    int gSize;

};


//Constructor
OurGraph::OurGraph() {

    graph = new list<int>[7];

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

    gSize = 7;

    graph[ 0 ].push_back( 1 ); // node 2
    graph[ 0 ].push_back( 2 ); // node 3
    graph[ 0 ].push_back( 3 ); // node 4

    graph[ 1 ].push_back( 3 ); // node 4
    graph[ 1 ].push_back( 4 ); // node 5

    graph[ 2 ].push_back( 5 ); // node 6

    graph[ 3 ].push_back( 2 ); // node 3
    graph[ 3 ].push_back( 4 ); // node 5
    graph[ 3 ].push_back( 5 ); // node 6

    graph[ 4 ].push_back( 6 ); // node 7

    graph[ 3 ].push_back( 2 ); // node 5

    // Nothing at node 6 (index 5)

    graph[ 6 ].push_back( 3 ); // node 4
    graph[ 6 ].push_back( 5 ); // node 6



    list<int>::iterator it;
    for (it = graph[ 2 ].begin(); it != graph[ 2 ].end(); it++) {

        cout << "Vertex: " << *it << endl;

    }
}


void OurGraph::depthFirstTraversal() {

    bool* visited; //pointer to create the array to keep //track of the visited vertices
    visited = new bool[gSize];
    int index;
    for (index = 0; index < gSize; index++) {

        visited[index] = false;

    }

    //For each vertex that is not visited, do a depth
    //first traverssal
    for (index = 0; index < gSize; index++) {

        if (!visited[index]) {

            dft(index,visited);

        }

        delete[] visited;
    }
}


void OurGraph::dft(int v, bool visited[]) {

    visited[ v ] = true;

    cout << "" << v + 1 << ""; //visitthevertex

    list<int>::iterator graphIt;
            //for each vertex adjacent to v
    for (graphIt = graph[v].begin();
        graphIt != graph[v].end();
        ++graphIt) {

        int w = *graphIt;
        if ( !visited[w] ) {

            dft(w, visited);

        }

    } //end while
} //end dft


/**
 * @return
 */
int main() {

    OurGraph graph;

    graph.createGraph();

    graph.depthFirstTraversal();


    return 0;
}
