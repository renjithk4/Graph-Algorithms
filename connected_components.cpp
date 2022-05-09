#include <bits/stdc++.h>
using namespace std;
void dfs(int v,int e, vector<int> adj[],int start,vector<int> visited)
{
    visited[start]=1;
    for(auto itr:adj[start])
    {
        if(visited[itr]==0)
            dfs(v,e,adj,itr,visited);
    }
}

int main() {
    int e,v;
    cin>>v>>e;
    vector<int> adj[v+1];
    for (int i=0;i<e;i++)
    {
        int n,m;
        cin>>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    vector<int> visited(v+1);
    for(itn i=0;i<v;i++)
        visited[i]=0;
        int count=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            count++;
            dfs(v,e,adj,i,visited);
        }
    }
    cout<<"Number of connected components:"<<count;
}
