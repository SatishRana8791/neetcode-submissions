class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,int>>rows(9),cols(9),grid(9);
        
        //check each cell in a board 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;

                char ch = board[i][j];
                int num=(i/3)*3 + (j/3);       //find grid number

                if(rows[i].count(ch) || cols[j].count(ch) || grid[num].count(ch) ){
                    return false;
                }
                rows[i].insert({ch,1});
                cols[j].insert({ch,1});
                grid[num].insert({ch,1});
            }
        }
        return true;
    }
};
