class Solution {
public:

    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }

    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    void solve(vector<vector<char>>& board) {
        int n=board.size();  //rows
        int m=board[0].size();   //cols
        queue<int>q;

        // check boundary side
        for(int i=0;i<m;i++){     //first row
            if(board[0][i]=='O'){
                int cell=0*m+i;
                board[0][i]='#';
                q.push(cell);
            }
        }
        for(int i=0;i<m;i++){      //last row
            if(board[n-1][i]=='O'){
                int cell=(n-1)*m+i;
                board[n-1][i]='#';
                q.push(cell);
            }
        }
        for(int i=1;i<n-1;i++){     //first col
            if(board[i][0]=='O'){
                board[i][0]='#';
                int cell=i*m+0;
                q.push(cell);
            }
        }
        for(int i=1;i<n-1;i++){     //last col
            if(board[i][m-1]=='O'){
                int cell=i*m+m-1;
                board[i][m-1]='#';
                q.push(cell);
            }
        }
        while(!q.empty()){
            int i=q.front()/m;
            int j=q.front()%m;
            q.pop();

            for(int k=0;k<4;k++){
                int n_i=i+row[k];
                int n_j=j+col[k];

                if(valid(n_i,n_j,n,m) && board[n_i][n_j]=='O'){
                    board[n_i][n_j]='#';
                    q.push(n_i*m+n_j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        return;
    }
};
