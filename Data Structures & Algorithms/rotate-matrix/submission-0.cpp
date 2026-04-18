class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);  //transpose the matrix along the diagonal
            }
        }
        //reverse the array in row wise
        for(int i=0;i<n;i++){
            int left=0,right=n-1;
            while(left < right){
                swap(matrix[i][left],matrix[i][right]);
                left++,right--;
            }
        }
        
    }
};
