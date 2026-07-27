class Solution {
public:

    bool detectCycle(int node,vector<int>adj[],vector<bool> & visited,vector<bool>& path,vector<int>& ans){
        visited[node]=1;
        path[node]=1;

        for(int j=0;j<adj[node].size();j++){
            if(path[adj[node][j]]){
                return true;  // there is a cycle present so can't schedule courses
            }
            if(visited[adj[node][j]]){
                continue;    //it has been visited via other route
            }
            if(detectCycle(adj[node][j],adj,visited,path,ans)){
                return true;
            }
        }
        path[node]=0;
        ans.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<bool>visited(numCourses,0);
        vector<bool>path(numCourses,0);
        vector<int>ans;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(detectCycle(i,adj,visited,path,ans)){
                    return {};
                }
            }
        }

        //reverse the ans vector
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
