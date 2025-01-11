
/*Implementation of graph using adjacency list built using dynamic memory allocation.
Implementation of DFS and BFS after that check whether the graph is a tree or not
by cycle detection using DFS
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include "graph.h"
#include "bfsdfs.h"
using namespace std;

int main() {
    graph g;
    BfsDfs b(g);  // Pass graph to BfsDfs
    cout << "Graph initialized!" << endl;

    while (true) {
        cout << "Choose from below: " << endl;
        cout << "1. DFS" << endl;
        cout << "2. BFS" << endl;
        cout << "3. Check for Tree" << endl;
        cout << "4. Display the graph" << endl;
        cout << "5. Exit" << endl;

        int k;
        cin >> k;

        if (k == 1) {
            cout << "Enter vertex: ";
            int a;
            cin >> a;
            b.DFS(a);
            cout << endl;
            fill(b.vis, b.vis + g.n + 1, false); // Reset visited array
        }

        if (k == 2) {
            cout << "Enter vertex: ";
            int a;
            cin >> a;
            b.BFS(a);
            fill(b.vis, b.vis + g.n + 1, false); // Reset visited array
        }

        if (k == 3) {
            if (b.is_tree())
                cout << "YES, the graph is a tree." << endl;
            else
                cout << "NO, the graph is not a tree." << endl;
            fill(b.vis, b.vis + g.n + 1, false); // Reset visited array
        }

        if (k == 4) {
            g.display_graph();
        }

        if (k == 5) break;
    }

    cout << "BFS DFS, tree check done!" << endl;

    // Memory clear at end
    g.clear();

    return 0;
}
