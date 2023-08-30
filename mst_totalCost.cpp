#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int n =1e5;
vector<pii> adj[n];
#define ss second
#define ff first
int cost;

int prims(int src)
{
    bool vis[n+1]={0};
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,src});
    int counter = 0;
    while( !pq.empty() )
    {
        pii p = pq.top();
        pq.pop();
        int u = p.ss;
        int ct=p.ff;
        //cout << u << " ";
        if(!vis[u])
        {
            vis[u] = 1 ;
            cost = cost+ct;
            for(auto v : adj[u])
            {
                if( ! vis[v.ss])
                {
                    pq.push(v);
                }
            }
        }
    }
    return cost;
}
int main()
{
    int v ,e ;
    cin >> v >>e ;
    for(int i =0 ; i<e ;i++)
    {
        int a, b , c;
        cin >> a >> b  >> c;
        adj[a].push_back( {c,b} ) ;
        adj[b].push_back({c,a }) ;
    }
    cout << prims(1);
}
