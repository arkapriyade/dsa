#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&visited,int src){
    cout<<src<<" ";
    visited[src]=true;
    for(int child:adj[src]){
        if(!visited[child]){
            dfs(adj,visited,child);
        }
    }
}
void bfs( unordered_map<int,vector<int>>&adj,int h){
    queue<int>q;
    unordered_map<int,bool>visited;
    q.push(h);
    visited[h]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr;
        for(int child:adj[curr]){
        if(!visited[child]){
            q.push(child);
            visited[child]=true;
        }
        }
    }
    
}

void addEdge(unordered_map<int,vector<int>>&adj,int src,int dest){
     adj[src].push_back(dest);
      adj[dest].push_back(src);
}
int main ()
{
 
    unordered_map<int,vector<int>>adj;
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);
    bfs(adj,2);
    cout<<endl;
    unordered_map<int,bool>visited;
    dfs(adj,visited,0);
  
}
