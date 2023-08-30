ll Prims(int src)
{
    ll cost=0;
    bool vis[n+5]={0};
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        pii p=pq.top();
        pq.pop();
        int u=p.ss;
        int ct=p.ff;
        if(!vis[u])
        {

            vis[u]=1;
            cost+=ct;
            for(auto v:adj[u])
            {
                if(!vis[v.ss])
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

