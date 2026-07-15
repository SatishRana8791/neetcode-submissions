class Solution {
public:
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    bool valid(int i,int j,int rows,int cols){
        return i>=0 && i<rows && j>=0 && j<cols;
    }

    bool CheckNext(int i,int j, int idx,vector<vector<char>>& board, string word,unordered_set<int>&st){
        //code here
        st.insert(i*board[0].size()+j);

        //edge case
        if(idx==word.size()-1){
            return true;
        }


        for(int k=0;k<4;k++){
            int n_i=i+row[k];
            int n_j=j+col[k];
            int cell=n_i*board[0].size()+n_j;
            
            if(valid(n_i,n_j,board.size(),board[0].size())&& !st.count(cell) && board[n_i][n_j]==word[idx+1]){
                if(CheckNext(n_i,n_j,idx+1,board,word,st)) return true;
            }

        }
        st.erase(i*board[0].size()+j);
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();  //rows
        int m=board[0].size();  //columns
        int idx=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                unordered_set<int>s;
                if(board[i][j]==word[idx] && CheckNext(i,j,idx,board,word,s) ){
                    return true;
                }
            }
        }
        return false;
    }
};
