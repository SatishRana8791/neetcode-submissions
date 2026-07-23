class Solution {
public:
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int count=0;
        while(!q.empty()){
            int n1=q.size();
            count++;
            while(n1--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++){
                    int n_i=i+row[k];
                    int n_j=j+col[k];
                    
                    if(valid(n_i,n_j,n,m) && grid[n_i][n_j]==2147483647){
                        q.push({n_i,n_j});
                        grid[n_i][n_j]=count;
                    }
                }
            }

        }
        return ;
    }
};
