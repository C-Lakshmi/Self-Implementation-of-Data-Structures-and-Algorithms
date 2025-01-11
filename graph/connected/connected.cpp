/*Implementation of graph using adjacency list built using dynamic memory allocation.
Using DFS I am finding all the connected components of the
graph
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "connected.h"
using namespace std;

int main() {
    graph g; 
    BfsDfs b(g); 
    connected conn(b, g);

    cout << "Graph initialized successfully!" << endl;

    while (true) {
        cout << "Choose from below:" << endl;
        cout << "1. Find all the connected components" << endl;
        cout << "2. Display the graph" << endl;
        cout << "3. Exit" << endl;
        int k;
        cin >> k;

        if (k == 1) {
            conn.find_components();
            cout << endl;
            fill(b.vis, b.vis + g.n + 1, false); //reseting visited array
        }

        if (k == 2) {
            g.display_graph(); 
        }

        if (k == 3) break;
    }

    cout << "Found all connected components!!" << endl;

    // Memory clear at end
    g.clear();

    return 0;
}
