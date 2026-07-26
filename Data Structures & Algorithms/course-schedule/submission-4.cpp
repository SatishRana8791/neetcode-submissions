class Solution {
public:

    bool DFS(int node,vector<int>adj[],vector<bool>& visited,vector<bool>&path){
        visited[node]=1;
        path[node]=1;

        for(int i=0;i<adj[node].size();i++){
            if(path[adj[node][i]]){
                return true;   //cycle detect
            }
            if(visited[adj[node][i]]){
                continue;
            }
            if(DFS(adj[node][i],adj,visited,path)){
                return true;
            }
        }
        path[node]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int>adj[numCourses];
        vector<bool>visited(numCourses,0);
        vector<bool>path(numCourses,0);

        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }

        //traverse dfs for non- visited
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(DFS(i,adj,visited,path)){
                    return false;
                }
            }
        }
        return true;
    }
};
