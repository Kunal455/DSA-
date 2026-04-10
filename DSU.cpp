// #include<bits/stdc++.h>
// using namespace std;
// class DisJoints{
//     vector<int> rank, parents;
//     public:
//     DisJoints(int n){
//         rank.resize(n+1, 0);
//         parents.resize(n+1);

//         for(int i=0;i<=n;i++){
//             parents[i] = i;
//         }
//     }

//     int find(int node){
//         if(parents[node]==node) return node;

//         return parents[node] = find(parents[node]);
//     }

//     void unionbyRank(int u, int v){
//         int p1 = find(u);
//         int p2 = find(v);

//         if(p1==p2){
//             return;
//         }
//         if(rank[p1] < rank[p2]){
//             parents[p1] = p2;
//         }
//         else if(rank[p2] < rank[p1]){
//             parents[p2] = p1;
//         }
//         else{
//             parents[p1]=p2;
//             rank[p1]++;
//         }
//     }
     
// };
// int main(){
//     DisJoints ds(7);

//     ds.unionbyRank(1,2);
//     ds.unionbyRank(2,3);
//     ds.unionbyRank(4,5);
//     ds.unionbyRank(6,7);
//     ds.unionbyRank(5,6);

    
//     if(ds.find(3)==ds.find(7)){
//         cout<<"same";
//     }
//     else{
//         cout<<"not same";
//     }

//     ds.unionbyRank(3,7);
    
//     if(ds.find(3)==ds.find(7)){
//         cout<<"same";
//     }
//     else{
//         cout<<"not same";
//     }


// }


// #include<bits/stdc++.h>
// using namespace std;

// class DisJoints {
//     vector<int> size, parents;

// public:
//     DisJoints(int n) {
//         size.resize(n + 1, 1);   // each node has size 1
//         parents.resize(n + 1);

//         for(int i = 0; i <= n; i++) {
//             parents[i] = i;
//         }
//     }

//     int find(int node) {
//         if(parents[node] == node) return node;

//         return parents[node] = find(parents[node]);
//     }

//     void unionbySize(int u, int v) {
//         int p1 = find(u);
//         int p2 = find(v);

//         if(p1 == p2) return;

//         if(size[p1] < size[p2]) {
//             parents[p1] = p2;
//             size[p2] += size[p1];
//         }
//         else {
//             parents[p2] = p1;
//             size[p1] += size[p2];
//         }
//     }
// };

// int main() {
//     DisJoints ds(7);

//     ds.unionbySize(1,2);
//     ds.unionbySize(2,3);
//     ds.unionbySize(4,5);
//     ds.unionbySize(6,7);
//     ds.unionbySize(5,6);

//     if(ds.find(3) == ds.find(7)) {
//         cout << "same\n";
//     }
//     else {
//         cout << "not same\n";
//     }

//     ds.unionbySize(3,7);

//     if(ds.find(3) == ds.find(7)) {
//         cout << "same\n";
//     }
//     else {
//         cout << "not same\n";
//     }
// }



// #include<bits/stdc++.h>
// using namespace std;
// class DSU{
// public:
//     vector<int> parent, rank;

//     DSU(int n){
//         parent.resize(n);
//         rank.resize(n, 0);

//         for(int i=0;i<n;i++){
//             parent[i]=i;
//         }
//     }

//     int find(int node){
//         if(parent[node]==node) return node;

//         return parent[node] = find(parent[node]);
//     }

//     bool unions(int x, int y){
//         int p1 = find(x);
//         int p2 = find(y);

//         if(p1==p2) return false;

//         if(rank[p1]<rank[p2]){
//             parent[p1]=p2;
//         }
//         else if(rank[p2]<rank[p1]){
//             parent[p2] = p1;
//         }
//         else{
//             parent[p1] = p2;
//             rank[p2] += 1;
//         }
//         return true;
//     }



// };
// int main(){
//     int n,m;
//     cin>>n;
//     cin>>m;
    


//     vector<vector<int>> isconnected(m, vector<int>(m));


//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>isconnected[i][j];
//         }
//     }

//     DSU dsu(n);

//     int c = 0;
//     for(auto it: isconnected){
//         if(dsu.unions(it[0], it[1])){
//             c++;
//         }
//     }

    
//     for(int i=0;i<n;i++){
//         if(dsu.find(i)==i) c++;
//     }

//     cout<<c;

//     int co = 0;
//     for(int i=0;i<n;i++){
//         if(dsu.find(i)==i) co++;
//     }

//     int need = co-1;

//     if(c>=need) cout<<need;
//     else cout<<-1;

// }



#include<bits/stdc++.h>
using namespace std;
class DSU{
public:

    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(parent[node]==node) return node;

        return parent[node] = find(parent[node]);
    }

    bool unions(int x, int y){
        int p1 = find(x);
        int p2 = find(y);

        if(p1==p2) return true;

        if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        }
        else if(rank[p2]<rank[p1]){
            parent[p2]=p1;
        }
        else {
            parent[p2] = p1;
            rank[p1]++;
        }

        return false;
    }
};


int main(){
    int n;
    cin>>n;

    DSU dsu(n);
    vector<vector<int>> v(n, vector<int> (2));

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>v[i][j];
        }
    }


    for(auto it: v){
        if(dsu.unions(it[0], it[1])){
            cout<<"["<< it[0]<<","<<it[1]<<"]";
        }
    }
}