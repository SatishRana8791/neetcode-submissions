class Solution {
public:
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }

    int DFS(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&grid){

        //check first all four dir
        for(int k=0;k<4;k++){
            int n_i=i+row[k];
            int n_j=j+col[k];

            if( valid(n_i,n_j,matrix.size(),matrix[0].size()) && matrix[n_i][n_j] > matrix[i][j] ){
                if(grid[n_i][n_j] != 0){
                    grid[i][j]=max(grid[i][j],1+grid[n_i][n_j]);
                }
                else{
                    grid[i][j]=max(grid[i][j],1+DFS(n_i,n_j,matrix,grid)); 
                }
            }
        }
        return grid[i][j]==0 ? 1 : grid[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        int path=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    //check max for path
                    path=max(path,DFS(i,j,matrix,grid));
                }
                else{
                    path=max(path,grid[i][j]);
                }
            }
        }
        return path;
    }
};
