#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void toposort_bfs(int v,int e,int start,vector<int> adj[],vector<int> &visited,vector<int>& indegree)
{
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        int v=q.front();
        cout<<v<<" ";
        q.pop();
        for(auto itr:adj[v])
        {
            if(visited[itr]==0)
            {
                indegree[itr]--;
                //visited[itr]=1;
                if(indegree[itr]==0 )
                {
                    visited[itr]=1;
                    q.push(itr);
                }
            }
        }
    }
    
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
   
   vector<int> indegree(v+1);
   for(int i=0;i<v;i++)
    indegree[i]=0;
   for(int i=0;i<v;i++)
   {
       for(auto itr:adj[i])
       {
           indegree[itr]++;
       }
   }
   
  
    
    
    cout<<endl;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0 && visited[i]==0)
            toposort_bfs(v,e,i,adj,visited,indegree);
    }
    
    
    
    
}
