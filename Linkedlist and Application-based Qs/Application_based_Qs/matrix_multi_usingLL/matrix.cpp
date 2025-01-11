#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    double data;
    Node* next;
};

Node* createLL(double * arr, ll n) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    Node* curr = head;
    for (ll i = 1; i < n; i++) {
        Node* newptr = (Node*)malloc(sizeof(Node));
        newptr->data = arr[i];
        newptr->next = nullptr;
        curr->next = newptr;
        curr = curr->next;
    }
    return head;
}
void printLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    ll n, m, p;
    cin>>n>>m>>p; 

    
double a[n][m], b[m][p];
for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
        ll x=rand();
        ll y=rand();
         if(y!=0) a[i][j]=double(x)/y;
         else a[i][j]=x;
    }
}
for(ll i=0;i<m;i++){
    for(ll j=0;j<p;j++){
        ll w=rand();
        ll z=rand();
         if(z!=0) b[i][j]=double(w)/z;
         else b[i][j]=w;
    }
}

    vector<Node*> matrixB(p); 
    vector<Node*> matrixA(n); 
    vector<Node*> matrixC(n);

    for (ll i = 0; i < n; i++) {
        double rowArray[m];
        for (ll j = 0; j < m; j++) {
            rowArray[j] = a[i][j];
        }
        matrixA[i]=createLL(rowArray, m);
    }
    for (ll j = 0; j < p; j++) {
        double colArray[m];
        for (ll i = 0; i < m; i++) {
            colArray[i] = b[i][j];
        }
        matrixB[j] = createLL(colArray, m);
    }
    cout<<endl;
    double numA,numB;
    vector<Node*> HEADA(matrixA);
    vector<Node*> HEADB(matrixB);
    for(ll i=0;i<n;i++){
        double row[p];
        for(ll j=0;j<p;j++){
            matrixA[i]=HEADA[i];
            matrixB[j]=HEADB[j];
            double sum=0;
            while(matrixA[i]!=nullptr && matrixB[j]!=nullptr){
            numA=(matrixA[i])->data;
            numB=(matrixB[j])->data;
            sum+=numA*numB;
            (matrixA[i])=(matrixA[i])->next;
            (matrixB[j])=(matrixB[j])->next;
            }
            row[j]=sum;
            }
            matrixC[i]=createLL(row, p);
    }
cout<<"Matrix C=A*B (n*p) is:"<<endl;  
    for (ll j = 0; j < n; j++) {
        printLL(matrixC[j]);
    }
    
  return 0;
}