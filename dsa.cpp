#include<bits/stdc++.h>
using namespace std;
 

int main(){
    int n;
    cin>>n;
    
    int k;
    cin>>k;
    
    vector<int> arr(n);
    
   
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i] = data;
        pq.push(arr[i]);
        
    }
    
    
    
    int kth = 0;
    for(int i=1;i<=k;i++){
        kth = pq.top();
        pq.pop();
    }

    
    if(!pq.empty() && pq.top()==kth){
        cout<<"-1";
    }
    else{
        cout<<kth;
    }
    
    
    
    
    
    
    
    
    
    
   
}