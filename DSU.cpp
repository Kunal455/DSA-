#include<bits/stdc++.h>
using namespace std;
class DisJoints{
    vector<int> rank, parents;
    public:
    DisJoints(int n){
        rank.resize(n+1, 0);
        parents.resize(n+1);

        for(int i=0;i<=n;i++){
            parents[i] = i;
        }
    }

    int find(int node){
        if(parents[node]==node) return node;

        return parents[node] = find(parents[node]);
    }

    void unionbyRank(int u, int v){
        int p1 = find(u);
        int p2 = find(v);

        if(p1==p2){
            return;
        }
        if(rank[p1] < rank[p2]){
            parents[p1] = p2;
        }
        else if(rank[p2] < rank[p1]){
            parents[p2] = p1;
        }
        else{
            parents[p1]=p2;
            rank[p1]++;
        }
    }
     
};
int main(){
    DisJoints ds(7);

    ds.unionbyRank(1,2);
    ds.unionbyRank(2,3);
    ds.unionbyRank(4,5);
    ds.unionbyRank(6,7);
    ds.unionbyRank(5,6);

    
    if(ds.find(3)==ds.find(7)){
        cout<<"same";
    }
    else{
        cout<<"not same";
    }

    ds.unionbyRank(3,7);
    
    if(ds.find(3)==ds.find(7)){
        cout<<"same";
    }
    else{
        cout<<"not same";
    }


}