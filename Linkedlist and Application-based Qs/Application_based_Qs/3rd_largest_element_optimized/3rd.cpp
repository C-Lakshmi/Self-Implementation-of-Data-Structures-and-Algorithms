#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector <int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
long int max=INT16_MIN;
long int max2=INT32_MIN;
long int max3=INT64_MIN;
for(auto el:arr){
    if(el>=max3 && el<=max2 && el<=max){
        max3=el; 
    }
    if(el>=max2 && el<=max){
        max3=max2;
        max2=el;
    }
    if(el>max){
        max3=max2;
        max2=max;
        max=el;
    }
    
}
cout<<max3<<endl;
return 0;
}