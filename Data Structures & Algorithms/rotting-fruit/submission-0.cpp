class Solution {
public:
    int adjrow[4]={-1,0,1,0};
    int adjcol[4]={0,1,0,-1};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        int minut=-1;
        int ones=0;
        //push 2 into queue first
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //code here
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1){
                    ones++;
                }
            }
        }
        if(ones==0) return 0;

        //traverse adjacent 1 to 2 
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int n_i=q.front().first;
                int n_j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if( valid(n_i+adjrow[k],n_j+adjcol[k],row,col) && grid[n_i+adjrow[k]][n_j+adjcol[k]] == 1 ){
                        q.push(make_pair(n_i+adjrow[k],n_j+adjcol[k]));
                        grid[n_i+adjrow[k]][n_j+adjcol[k]]=2;
                        ones--;
                    }
                }
            }
            minut++;
        }
        //check 2 is there or not
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //code here
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minut;
    }
};