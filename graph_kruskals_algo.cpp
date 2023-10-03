#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int par[N];
int sz[N]; // size

void make(int v){
    par[v] = v;
    sz[v] = 1;
}
int find(int v){
    if(v==par[v])return v;

    return par[v] = find(par[v]); // path compression 
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        // union by size
        if(sz[a]<sz[b])
            swap(a,b);

        par[b] = a;
        sz[a]+=sz[b];
    }
}
int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0;i<=n;i++)make(i);

    vector<pair<int, pair<int,int> > >edges;

    for(int i =0; i < m; ++i){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end ());
    
    int total_cost = 0;
    
    for(auto &edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u)==find(v)){
            continue;
        }
        Union(u,v);
        total_cost+=wt;
        cout<<u<<' '<<v<<endl;
    }
    cout<<total_cost;

}