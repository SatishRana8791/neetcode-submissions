class Solution {
public:
    void DFS(int node,int parent,vector<int>adj[],vector<bool>&visited){
        visited[node]=1;

        for(int j=0;j<adj[node].size();j++){
            if(parent==adj[node][j] || visited[adj[node][j]]){
                continue;
            }
            DFS(adj[node][j],node,adj,visited);
        }
       return; 
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,0);
        int connected=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                connected++;
                DFS(i,-1,adj,visited);
            }
        }
        return connected;
    }
};
