class Solution {
public:
    int row[4]={-1, 0 , 1 , 0};
    int col[4]={ 0, 1 , 0 ,-1};
    int r,c;

    bool valid(int i, int j){
        return i>=0 && i<r && j>=0 && j<c;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        r=m,c=n;
        int total=0;
        queue<pair<int,int>>q;
        //traverse the whole grid
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;  //count number of 1's
                if(grid[i][j]==1){
                    q.push(make_pair(i,j));
                    grid[i][j]=0;
                    count++;
                }
                while(!q.empty()){
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();

                    //now check each neighbour in 4 direction
                    for(int k=0;k<4;k++){
                        if( valid( new_i+row[k] , new_j+col[k] ) && grid[new_i+row[k]][new_j+col[k]] == 1){
                            q.push(make_pair(new_i+row[k],new_j+col[k]));
                            grid[new_i+row[k]][new_j+col[k]] = 0;
                            count++;
                        }
                    }
                }
                total=max(total,count);
            }
        }
        return total;
    }
};
