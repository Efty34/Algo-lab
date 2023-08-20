#include<bits/stdc++.h>
using namespace std;

//vector<vector<int>> adj;
int inf = 1000000;
int visited[5] = {0};
int dist[5];
int parent[5];

int minIndex()
{
    int mn = 1222222;
    int mnIn;
    for(int i=0; i<5; i++)
    {

        if(dist[i] < mn && visited[i] == 0)
        {
            mn = dist[i];
            mnIn = i;
        }
    }
    return mnIn;
}

void addEdge(int adj[][5], int x,int y, int cst)
{
    adj[x][y] = cst;
    adj[y][x] = cst;
}

void dijkstra(int adj[][5], int start)
{
    dist[start] = 0;
    for(int i=0; i<5; i++)
    {
        start = minIndex();
        for(int j=0; j< 5; j++)
        {
            if(adj[start][j] != inf)
            {
                if(dist[j] > dist[start] + adj[start][j])
                {
                    dist[j] = dist[start] + adj[start][j];
                    //
                    parent[j] = start;
                }
            }
        }
        visited[start] = 1;
    }
}

void path(int start, int ind){
//    while(ind!=start){
//        cout<<ind<<" <- ";
//        ind = parent[ind];
//    }
//    cout<<start;
    stack<int>st;
    while(ind!=start){
        st.push(ind);
        ind = parent[ind];
    }
    st.push(start);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    const int v = 5;
    int adj[v][v];

    for(int i=0; i<v; i++)
    {
        dist[i] = inf;
        for(int j=0; j<v; j++)
        {
            adj[i][j]=inf;
        }
    }

    addEdge(adj,0,1, 12);
    addEdge(adj,0,3, 2);
    addEdge(adj,1,4, 33);
    addEdge(adj,1,2, 33);
    addEdge(adj,3,2,5);
    addEdge(adj,2,4,8);

    dijkstra(adj, 0);

    for(int i=0; i<v; i++)
    {
        cout<<dist[i]<<" ";
    }
    int x;
    cout<<endl<<endl;
    cout<<"Enter the required Index "; cin>>x;
    path(0,x);
    return 0;
//    for(int i=0; i<5; i++)
//        cout<<parent[i]<<" ";

}