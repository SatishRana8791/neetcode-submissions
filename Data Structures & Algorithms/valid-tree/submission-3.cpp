class Solution {
public:

    bool DFS(int node,int parent,vector<int>adj[],vector<bool>&visited){
        visited[node]=1;

        //traverse the neighbour
        for(int j=0;j<adj[node].size();j++){
            if(adj[node][j] == parent ){
                continue;
            }
            if(visited[adj[node][j]]){
                return true;   //there is cycle
            }
            if(DFS(adj[node][j],node,adj,visited)){
                return true;
            }
            
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(u==v) return false;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n);
        bool cycle=DFS(0,-1,adj,visited);
        //check disconnected or not 
        bool connected=true;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                connected=false;
                break;
            }
        }
        return connected ? !cycle : false ;
    }
};
