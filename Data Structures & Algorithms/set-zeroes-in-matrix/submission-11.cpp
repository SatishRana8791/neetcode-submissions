class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();    //row
        int n=matrix[0].size();  //col
        //traverse the matrix
        bool rowCheck=false;
        bool colCheck=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && matrix[i][j]==0) rowCheck=true;
                if(j==0 && matrix[i][j]==0) colCheck=true;
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //now make cell 0 while check corresponding row and col
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(rowCheck){   //top row traverse and make 0 each cell
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(colCheck){   //left col traverse and make 0 each cell
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
