class Solution {
public:
  
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }

    void DFS(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='0';

        for(int k=0;k<4;k++){
            int n_i=i+row[k];
            int n_j=j+col[k];

            if(valid(n_i,n_j,grid.size(),grid[0].size()) && grid[n_i][n_j]=='1'){
                DFS(n_i,n_j,grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();     //rows
        int m=grid[0].size();  //cols

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0') continue;
                else{
                    DFS(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
