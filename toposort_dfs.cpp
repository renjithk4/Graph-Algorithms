#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void toposort_dfs(int v,int e,int start,vector<int> adj[],vector<int> &visited,stack<int>& s)
{
    visited[start]=1;
    //cout<<start<<" ";
    for(auto itr:adj[start])
    {
        if(visited[itr]==0)
            dfs(v,e,itr,adj,visited,s);
    }
    //cout<<start<<" ";
    s.push(start);
    
}

int main() {
   int e,v;
   cin>>v>>e;
   vector<int> adj[v+1];
   for(int i=0;i<e;i++)
   {
       int n,m;
       cin>>n>>m;
       adj[n].push_back(m);
       //adj[m].push_back(n);
   }

   vector<int> visited(v+1);
   for(int i=0;i<v;i++)
        visited[i]=0;
   // vector<int> ans;
   stack<int> s;
   
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
            dfs(v,e,i,adj,visited,s);
    }
    
    
    cout<<endl;
    while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    
}
