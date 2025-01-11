#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "graph.h"
#include "bfsdfs.h"
using namespace std;


class connected {
public:
    int conn=0;
    BfsDfs& b; // Reference to BfsDfs object
    graph& g;  // Reference to graph object

    // Constructor accepting BfsDfs and graph object references
    connected(BfsDfs& bobj, graph& gobj) : b(bobj), g(gobj) {}

    void find_components() {
        cout << "Following are the connected components: " << endl;
        cout << endl;

        // looping through all nodes and using DFS to find connected components
        for (int i = 1; i <= g.n; i++) {
            if (!b.vis[i]) {  // if node is not visited
                b.DFS(i);  // perform DFS
                conn++;    
                cout << endl;
            }
        }
        cout << endl;
        cout << "Total connected components are: " << conn << endl;
    }
};
