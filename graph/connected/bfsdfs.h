#include <queue>
class BfsDfs {
public:
    const graph& gr; // reference to graph
    bool* vis;       // visited array

    // constructor taking a reference to a graph object
    BfsDfs(const graph& g) : gr(g) {
        vis = new bool[gr.n + 1]();
    }

    ~BfsDfs() {
        delete[] vis; 
    }

    void DFS(int a) {
        if (vis[a]) return;
        vis[a] = true;
        cout << a << "-";
        node* t = gr.arr[a];
        while (t != NULL) {
            DFS(t->data);
            t = t->next;
        }
    }

    void BFS(int a) {
        fill(vis, vis + gr.n + 1, false); // reset visited array
        queue<int> q;
        q.push(a);

        while (!q.empty()) {
            int s = q.front();
            q.pop();

            if (!vis[s]) {
                cout << s << "-";
                vis[s] = true;
            }

            node* trav = gr.arr[s];
            while (trav != NULL) {
                if (!vis[trav->data])
                    q.push(trav->data);
                trav = trav->next;
            }
        }
        cout << endl;
    }

    void cycle_check_dfs(int a) {
        if (vis[a]) return;
        vis[a] = true;
        node* t = gr.arr[a];
        while (t != NULL) {
            cycle_check_dfs(t->data);
            t = t->next;
        }
    }

    bool is_tree() {
        fill(vis, vis + gr.n + 1, false); // resetting visited array
        cycle_check_dfs(1);
        for (int i = 1; i <= gr.n; i++) {
            if (!vis[i])
                return false; // graph is not connected
        }
        return (gr.m == gr.n - 1); // checking if edges count matches tree property
    }
};

/*class BfsDfs{
  public:
  int n,ncopy;
  int m,mcopy;
  node **arr;
  
  void DFS(int a)
  {
      if (vis[a]) return;
      vis[a]=1;
      cout<<a<<"-";
      node *t=arr[a];
      while (t!=0)
      {
          DFS(t->data);
          t=t->next;
      }
      
  }
  
  void BFS(int a)
  {
      queue <int> q;
      q.push(a);
      
      while(!q.empty())
      {
          int s=q.front();
          q.pop();
          
          if (vis[s]==0)cout<<s<<"-";
          vis[s]=1;
          node *trav=arr[s];
          while(trav!=0)
          {
              if (vis[trav->data]==0) q.push(trav->data);
              trav=trav->next;
          }
          
      }
      cout<<endl;
      
  }
  
  void cycle_check_dfs(int a)
  {
     
      if (vis[a]) return ;
      vis[a]=1;
      node *t=arr[a];
      while (t!=0)
      {
          cycle_check_dfs(t->data);
          t=t->next;
      }
      return ;
      
  }
  
  
  
  bool is_tree()
  {
      cycle_check_dfs(1);
      for (int i=2;i<=n;i++) if (vis[i]==0) return 0;
      //Since whole graph is connected
      if (m==n-1) return 1;
      else return 0;
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
  
  void clear()
  {
      for (int i=1;i<=n;i++)
      {
          free(arr[i]);
      }
      free (arr);
  }
};*/