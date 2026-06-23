class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<int,vector<int>>mp;
        //let travel wholetable and check 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    mp[i].push_back(j);
                }
            }
        }
        //lets travel map
        for(auto it=mp.begin();it!=mp.end();it++){
            int row=it->first;
            vector<int>p = it->second;
            //first make row to 0
            for(int i=0;i<n;i++){
                matrix[row][i]=0;
            }
            for(int i=0;i<p.size();i++){
                int col=p[i];
                for(int j=0;j<m;j++){
                    matrix[j][col]=0;
                }
            }
        }
    }
};
