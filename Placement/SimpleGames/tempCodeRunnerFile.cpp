#include<bits/stdc++.h>
using namespace std;
int main(){
    int edge, vertex;
    cin>>vertex>>edge;

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(vertex, -1);
    


    queue<int> q;
    dist[0] = 0;
    
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        

        for(int neigh: adj[node]){
            if(dist[neigh]==-1){
                
                dist[neigh]=dist[node]+1;
                q.push(neigh);
            }
        }

        

    }

    for(int i=0;i<vertex;i++){
        cout<<dist[i]<<" ";
    }

    
}