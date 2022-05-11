#include <bits/stdc++.h>
using namespace std;


void shortestdistance_unweighted(int v,int e,vector<int> adj[],vector<int>& visited,vector<int>& distance)
{
    queue<int> q;
    q.push(0);
    visited[0]=1;
    distance[0]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto itr:adj[a])
        {
            if(visited[itr]==0)
            {
                if(distance[itr]>distance[a]+1)
                    distance[itr]=distance[a]+1;
                q.push(itr);
                visited[itr]=1;
            }
        }
    }
}


int main() {
    
	// your code goes here
	
	int v,e;
	cin>>v>>e;
	vector<int> adj[v+1];
	for(int i=0;i<e;i++)
	{
	    int n,m;
	    cin>>n>>m;
	    adj[n].push_back(m);
	    adj[m].push_back(n);
	    
	}
	
	vector<int> visited(v+1);
	for(int i=0;i<v;i++)
	{
	    visited[i]=0;
	}
	vector<int> distance(v+1);
	for(int i=0;i<v;i++)
	{
	    distance[i]=INT_MAX;
	}
	shortestdistance_unweighted(v,e,adj,visited,distance);
	for(int i=0;i<v;i++)
	    cout<<distance[i]<<" ";
	

	
	return 0;
}
