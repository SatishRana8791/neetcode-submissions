class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int>adj[numCourses];
        vector<int>Indeg(numCourses,0);
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            Indeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(Indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int i=0;i<adj[node].size();i++){
                int neigh=adj[node][i];
                Indeg[neigh]--;
                if(Indeg[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        
        //check that indeg of all becomes zero
        for(int i=0;i<numCourses;i++){
            if(Indeg[i]!=0){
                return false;
            }
        }
        return true;
    }
};


