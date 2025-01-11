
//Implementation of graph using adjacency list with dynamic memory allocation.

/*By Euler's Theorem, if edges > 3*vertices-6, the graph is certainly non-planar,
else we can't give a guarantee of non-Planarity.
For that, we will need advanced techniques like Kuratowski's Theorem or C++ Boost libraries*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "graph.h"


using namespace std;

int main()
{
    graph g;
    cout<<"Graph initialized!"<<endl;
    
    while(1)
    {
        cout<<"Choose a number from below: "<<endl;
        cout<<"1. Add an edge"<<endl;
        cout<<"2. Remove an edge"<<endl;
        cout<<"3. Remove a vertex"<<endl;
        cout<<"4. Display the graph"<<endl;
        cout<<"5. Check for Planarity (Euler's Theorem)"<<endl;
        cout<<"6. Exit"<<endl;
        int k;
        cin>>k;
        if (k==1)
        {
        cout<<"Enter edge pair: ";
        int a,b;
        cin>>a>>b;
        g.add_edge(a,b);
        }
        if (k==2)
        {
        cout<<"Enter edge pair: ";
        int a,b;
        cin>>a>>b;
        g.remove_edge(a,b);
        }
        if (k==3)
        {
        cout<<"Enter vertex: ";
        int a;
        cin>>a;
        g.remove_vertex(a);
        }
        if (k==4)
        {
            g.display_graph();
        }
        if (k==5)
        {
            g.planarity();
        }
            
        if (k==6) break;
        

    }
    
    cout<<"Graph implementation done!"<<endl;

    //to clear memory
    g.clear();
    
    
    return 0;
}
