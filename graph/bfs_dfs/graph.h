#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
  };
class graph{
  public:
  int n,ncopy;
  int m,mcopy;
  node **arr;
  
  void add_edge (int a,int b){
    if (a < 1 || a > n || b < 1 || b > n) {
    cout << "Invalid edge: " << a << " - " << b << endl;
    return;
    }

      //check for already existing
      node *tr=arr[a];
      while(tr!=0)
      {
          if (tr->data==b) return;
          tr=tr->next;
      }
      
        
        node *t1=arr[a],*t2=arr[b];
        node *t11=new node,*t22=new node;
        t11->next=NULL;
        t11->data=b;
        
        t22->next=NULL;
        t22->data=a;
        
        if (t1==NULL) arr[a]=t11;
        else {
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=t11;
        }
        
        if (t2==NULL) arr[b]=t22;
        else {
        while(t2->next!=NULL)
        {
            t2=t2->next;
        }
        t2->next=t22;
        }
    }
  
    graph(){
      cout<<"Enter number of nodes: ";
      cin>>n;
      cout<<"Enter number of edges: ";
      cin>>m;
      arr =new node *[n+4];
      ncopy=n;
      mcopy=m;
      for (int i=1;i<=n;i++)
      {
          arr[i]=NULL;
          
      }
      cout<<"Start entering edge pairs: "<<endl;
      for (int i=0;i<m;i++)
      {
          int x,y;
          cin>>x>>y;
          add_edge(x,y);
          cout<<i+1<<"th edge entered"<<endl;
      }
    }
  
    void remove_edge (int a,int b){
      
       node *t1=arr[a],*t2=arr[b];
       
       node *tail=arr[a];
        
        while(t1!=NULL)
        {
            if (t1->data==b)
            {
                if (tail==arr[a]) {arr[a]=tail->next;break;}
                tail->next=t1->next;
                
                break;
            }
            tail=t1;
            t1=t1->next;
        }
           
       tail=arr[b];
        while(t2!=NULL)
        {
            if (t2->data==a)
            {
                if (tail==arr[b]) {arr[b]=tail->next;break;}
                tail->next=t2->next;
                
                break;
            }
            tail=t2;
            t2=t2->next;
        }
        mcopy--;
        
        
        
  }
  
  void remove_vertex(int a) {
    if (a < 1 || a > n) return; // invalid node rejected

    // removing all edges to this vertex
    for (int i = 1; i <= n; i++) {
        if (i == a) continue;
        node *t = arr[i], *tail = nullptr;
        while (t != nullptr) {
            if (t->data == a) {
                if (tail == nullptr) { // removing head of the list
                    arr[i] = t->next;
                } else {
                    tail->next = t->next;
                }
                delete t; // free memory of the removed node
                break;
            }
            tail = t;
            t = t->next;
        }
    }

    // remove the vertex itself
    node *ver = arr[a];
    while (ver != nullptr) {
        node *nextNode = ver->next;
        delete ver; // Free memory of the vertex's linked list
        ver = nextNode;
    }
    arr[a] = nullptr;
    ncopy--; // Update node count
}
  
  void planarity()
  {
      if (mcopy > 3 * ncopy - 6) cout<<"Definately Non-Planar"<<endl;
      else cout<<"Maybe Planar"<<endl;
  }
  
  void display_graph()
  {
      for (int i=1;i<=n;i++) if (arr[i]!=NULL) {
          node *trav=arr[i];
          cout<<i<<": ";
          while(trav!=0) {cout<<trav->data<<" ";trav=trav->next;}
          cout<<endl;
          
         }
     
  }
    
    void clear() {
    for (int i = 1; i <= n; i++) {
        node *current = arr[i];
        while (current != nullptr) {
            node *next = current->next;
            delete current; 
            current = next;
        }
    }
    delete[] arr; 
    arr = nullptr;
}

};
