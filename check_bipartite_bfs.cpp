#include <bits/stdc++.h>
using namespace std;
bool check_bipartite_bfs(int v,int e, vector<int> adj[],int src,int parent,vector<int>& color)
{
   
   queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return true; 
            }
        }
    }
    return false; 
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
    vector<int> color(v+1);
    for(int i=0;i<v;i++)
        color[i]=-1;
        int count=0;
    int flag=0;
    for(int i=0;i<v;i++)
    {
        if(color[i]==-1)
        {
            if(check_bipartite_bfs(v,e,adj,i,-1,color))
                {
                    cout<<"Not Bipartite";
                    flag=1;
                    break;
                }
            
        }
    }
    if(flag==0)
        cout<<"Bipartite graph";
}