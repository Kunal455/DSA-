
//Undirect Unweighted Graph
//Adjancency matric 
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex, edge;
    cin>>vertex;
    cin>>edge;
    vector<vector<bool>> AdjMat(vertex, vector<bool> (vertex, 0));
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        AdjMat[u][v]=1;
        AdjMat[v][u]=1;

    }

    for(int i=0;i<vertex;i++){
        
        for(int j=0;j<vertex;j++){
            cout<<AdjMat[i][j]<<" ";

        }
        cout<<endl;

    }
}






//Undirect weighted Graph
//Adjancency matric 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex, edge;
    cin>>vertex;
    cin>>edge;
    vector<vector<int>> AdjMat(vertex, vector<int> (vertex, 0));
    for(int i=0;i<edge;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        AdjMat[u][v]=weight;
        AdjMat[v][u]=weight;

    }

    for(int i=0;i<vertex;i++){
        
        for(int j=0;j<vertex;j++){
            cout<<AdjMat[i][j]<<" ";

        }
        cout<<endl;

    }
}





//Directed unweighted graph

#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex, edge;
    cin>>vertex;
    cin>>edge;
    vector<vector<bool>> AdjMat(vertex, vector<bool> (vertex, 0));
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        AdjMat[u][v]=1;
       

    }

    for(int i=0;i<vertex;i++){
        
        for(int j=0;j<vertex;j++){
            cout<<AdjMat[i][j]<<" ";

        }
        cout<<endl;

    }
}


//Directed Weighted Graph
#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex, edge;
    cin>>vertex;
    cin>>edge;
    vector<vector<int>> AdjMat(vertex, vector<int> (vertex, 0));
    for(int i=0;i<edge;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        AdjMat[u][v]=weight;
        

    }

    for(int i=0;i<vertex;i++){
        
        for(int j=0;j<vertex;j++){
            cout<<AdjMat[i][j]<<" ";

        }
        cout<<endl;

    }
}




//Undirected unweighted Adjacency List
#include<bits/stdc++.h>
using namespace std;
int main(){
    int edge, vertex;
    cin>>vertex>>edge;


    vector<int> AdjL[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        AdjL[u].push_back(v);
        AdjL[v].push_back(u);


    }

    for(int i=0;i<vertex;i++){
        cout<<i<< "-->"<<" ";
        for(int j=0;j<AdjL[i].size();j++){
            cout<<AdjL[i][j]<<" ";
        }
        cout<<endl;
    }




}




//Undirected weighted Adjacency List
#include<bits/stdc++.h>
using namespace std;
int main(){
    int edge, vertex;
    cin>>vertex>>edge;

    vector<pair<int,int>> AdjL[vertex];

    for(int i=0;i<vertex;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        AdjL[u].push_back({v,weight});
        AdjL[v].push_back({u,weight});
        
    }


    for(int i=0;i<vertex;i++){
        cout<<i<<"--> ";
        for(int j=0;j<AdjL[i].size();j++){
            cout<<"["<<AdjL[i][j].first<<","<<AdjL[i][j].second<<"], ";
        }
        cout<<endl;
    }

}



#include<bits/stdc++.h>
using namespace std;
int main(){
    int edge, vertex;
    cin>>vertex>>edge;
    vector<int> AdjL[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        AdjL[u].push_back(v);
        AdjL[v].push_back(u);
    }


    vector<bool> vis(vertex);
    queue<int> q;
    vector<int> ans;

    q.push(0);
    vis[0]=1;
    
    while(!q.empty()){
        int node =q.front();
        q.pop();
        ans.push_back(node);

        for(int j=0;j<AdjL[node].size();j++){
            if(!vis[AdjL[node][j]]){
                vis[AdjL[node][j]]=1;
                q.push(AdjL[node][j]);
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}


//DFS
#include<bits/stdc++.h>
using namespace std;
void DFS(int node, vector<int>& ans, vector<bool>& visited, vector<int> ADJ[]){
    ans.push_back(node);
    visited[node] =true;

    for(int i=0;i<ADJ[node].size();i++){
        if(!visited[ADJ[node][i]]){
            DFS(ADJ[node][i], ans, visited, ADJ);
        }
    }
}
int main(){
    int edge, vertex;
    cin>>edge>>vertex;

    vector<int> ADJ[vertex];
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
    }

    vector<int> ans;
    vector<bool> visited(vertex, false);

    DFS(0, ans, visited, ADJ);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}



#include<bits/stdc++.h>
using namespace std;
bool dfs(int parent, int node, vector<int> adj[], vector<bool>& visited){
    visited[node] = 1;

    for(auto neigh: adj[node]){
        if(!visited[neigh]){
            if(dfs(node, neigh, adj, visited)){
                return true;
            }
        }
        else if(parent!=neigh){
            return true;
        }

    }

    return false;
}
int main(){
    int edge, vertex;
    cin>>edge>>vertex;

    vector<int> adj[vertex];
    for (int i = 0; i < edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }


    vector<bool> visited(vertex);

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            if(dfs(-1,0,adj,visited)){
                cout<<"true";
                return 0;
            }
        }
    }
    cout<<"false";  
}





#include<bits/stdc++.h>
using namespace std;
bool bfs(int start, vector<int> adj[], vector<bool>& vis){
    queue<pair<int,int>> q;
    vis[start]=true;

    q.push({start, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto neigh: adj[node]){
            if(!vis[neigh]){
                vis[neigh]=true;
                q.push({neigh, node});
            }
            else if(parent!=neigh){
                return true;
            }
        }

        
    }

    return false;

}



int main(){
    int edge, vertex;
    cin>>edge>>vertex;

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(vertex, false);

    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            if(bfs(i, adj, vis)){
                cout<<"true";
                return 0;
            }
        }
    }

    cout<<"false";
}






//Topological sortm (DFS)
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, 
         vector<bool>& vis, stack<int>& st){

    vis[node] = true;

    for(auto neigh: adj[node]){
        if(!vis[neigh]){  // ✅ FIXED
            dfs(neigh, adj, vis, st);
        }
    }

    st.push(node);
}

int main(){
    int vertex, edge;
    cin >> vertex >> edge; // ✅ FIXED ORDER

    vector<vector<int>> adj(vertex);

    for(int i=0;i<edge;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v); // ✅ DIRECTED ONLY
    }

    vector<bool> vis(vertex,false);
    stack<int> st;

    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}


//Topological sort (BFS KAHN'S ALGO)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex,edge;
    cin>>vertex>>edge;

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
    }


    vector<int> InDegree(vertex, 0);

    for(int i=0;i<vertex;i++){
        for(auto neigh: adj[i]){
            InDegree[neigh]++;
        }
    }

    queue<int> q;

    for(int i=0;i<vertex;i++){
        if(InDegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto neigh: adj[node]){
            InDegree[neigh]--;
            if(InDegree[neigh]==0){
                q.push(neigh);
            }
        }


    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}



//detect sycle in directed graph dfs

#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<bool>& vis, vector<bool>& path, vector<int> adj[]){
    vis[node] = 1;
    path[node] = 1;

    for(auto neigh: adj[node]){
        if(path[neigh]) return true;

        if(!vis[neigh]){
            if(dfs(neigh, vis, path, adj)) return true;
        }
    }

    path[node] = 0;
    return false;
}

int main(){
    int vertex, edge;
    cin >> vertex >> edge;

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> vis(vertex,false);
    vector<bool> path(vertex,false);

    bool ans = false;

    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            if(dfs(i, vis, path, adj)){
                ans = true;
                break;
            }
        }
    }

    cout << ans;
}


//detect sycle in directed graph using bfs kan algo
#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex,edge;
    cin>>vertex>>edge;

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
    }


    vector<int> InDegree(vertex, 0);

    for(int i=0;i<vertex;i++){
        for(auto neigh: adj[i]){
            InDegree[neigh]++;
        }
    }

    queue<int> q;

    for(int i=0;i<vertex;i++){
        if(InDegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto neigh: adj[node]){
            InDegree[neigh]--;
            if(InDegree[neigh]==0){
                q.push(neigh);
            }
        }


    }
    int count = ans.size();
    if(count!=vertex){
        cout<<"cycle";
    }
    else{
        cout<<"no cycle";
    }
    
}

*/

//Bipartite using bfs
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int vertex, edge;
    cin>>vertex>>edge;

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> color(vertex, -1);
    queue<int> q;
    q.push(0);
    color[0] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neigh: adj[node]){
            if(color[neigh]==-1){
                color[neigh] = (color[node]+1)%2;
                q.push(neigh);
            }
            else{
                if(color[node]==color[neigh]){
                    cout<<"false";
                    return 0;
                }
            }
        }

    }
    cout<<"True";
}
    


//bipartite using bfs
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int>& color, vector<int> adj[]){
    
    for(int neigh: adj[node]){
        if(color[neigh]==-1){
            color[neigh] = (color[node]+1)%2;
            if(!dfs(neigh, color, adj)){
                return false;
            }
        }
        else{
            if(color[node]==color[neigh]){
                return false;
            }
        }
    }

    return true;
}
int main(){
    int vertex, edge;
    cin>>vertex>>edge;

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> color(vertex, -1);
    

    for(int i=0;i<vertex;i++){
         if(color[i]==-1){
            color[i]=0;
            if(!dfs(i, color, adj)){
                cout<<"false";
                return 0;
            }
        }
    }
    cout<<"True";
}


//shortest path in undirected graph
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




//print parent in shortest path in undirected graph
#include<bits/stdc++.h>
using namespace std;
int main(){
    int edge, vertex;
    cin>>vertex>>edge;
    int src,dest;
    cin>>src>>dest;
    

    //if 1index base src-- des--

    vector<int> adj[vertex];

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(vertex, -1);
    
    vector<int> parent(vertex,-1);


    queue<int> q;
    dist[src] = 0;
    
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        

        for(int neigh: adj[node]){
            if(dist[neigh]==-1){
                
                dist[neigh]=dist[node]+1;
                q.push(neigh);
                parent[neigh] = node;
            }
        }

        

    }

    vector<int> path;
    while(dest!=-1){
    path.push_back(dest);
    dest = parent[dest];
    }

    reverse(path.begin(), path.end());

    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }

    
}
    */




#include<bits/stdc++.h>
using namespace std;
void dfs(int node,  vector<pair<int,int>> adj[], stack<int>& st, vector<int>& vis){
    vis[node]=1;

    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v]){
            dfs(v, adj, st, vis);
        }
    }

    st.push(node);
}
int main(){
    int vertex, edge;
    cin>>vertex>>edge;


    vector<pair<int, int>> adj[vertex];


    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        
    }


    //step 1. topological sort
    vector<int> vis(vertex,0);
    stack<int> st;

    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            dfs(i, adj, st, vis);

        }
    }

    

    //step 2. distnace array
    vector<int> dist(vertex, 1e9);
    int src = 0;
    dist[src] = 0;

    //step 3. find distances
    while(!st.empty()){
        int u = st.top();
        st.pop();

        if(dist[u]!=1e9){
            for(auto it: adj[u]){

                int v = it.first;
                int w = it.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }

    }
    for(int i=0;i<vertex;i++){
        if(dist[i]==1e9){
            cout<<"inf";
        }
        else{
            cout<<dist[i]<<" ";
        }
    }   

}