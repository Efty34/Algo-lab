#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int degree[10];

vector< pair<int,int> >adj[10];
ll Prims(int src)
{
    ll cost=0;
    bool vis[10]={0};
    priority_queue< pair<int, pair<int,int> >,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>>pq;

    pq.push({0,{src,src}});

    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        int u=p.second.second;
        int v = p.second.first;
        int ct=p.first;
        if(!vis[u] && degree[u]<2 and degree[v]<2)
        {
            vis[u]=1;
            cost+=ct;
            if(u!=v){
                degree[u]++;
                degree[v]++;
                cout<<u<<' '<<v<<endl;
            }
            for(auto v:adj[u])
            {
                if(!vis[v.second])
                {
                    pq.push({v.first,{u,v.second}});
                }
            }
        }
    }
    return cost;
}
#define pb push_back
int main()
{
    int n,m;
   cin>>n>>m;
    while(m--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }
    cout<<Prims(1)<<endl;
}


/*
7 12
1 2 1
1 3 3
1 4 2
2 3 5
2 5 8
3 5 4
3 6 5
3 7 6
4 7 7
3 4 6
6 7 8
5 6 9
*/
