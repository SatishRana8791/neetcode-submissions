class Solution {
public:
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};

    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }

    void DFS(int key,vector<vector<int>>& heights,unordered_set<int>& set){
        int i=key/heights[0].size();  //row
        int j=key%heights[0].size();  //col

        for(int k=0;k<4;k++){
            int n_i=i+row[k];
            int n_j=j+col[k];

            if(valid(n_i,n_j,heights.size(),heights[0].size()) && heights[n_i][n_j] >= heights[i][j]){
                int key2=n_i*heights[0].size()+n_j;
                if(set.count(key2)){
                    continue;
                }
                else{
                    set.insert(key2);
                    DFS(key2,heights,set);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        unordered_set<int>Pacific,Atlantic;
        vector<int>PacificStart,AtlanticStart;
        for(int i=0;i<m;i++){   //first row push into map
            int cell=0*m+i;
            Pacific.insert(cell);
            PacificStart.push_back(cell);
        }
        for(int i=1;i<n;i++){   //first col
            int cell=i*m+0;
            Pacific.insert(cell);
            PacificStart.push_back(cell);
        }

        for(int i=0;i<m;i++){   //last row push into map
            int cell=(n-1)*m+i;
            Atlantic.insert(cell);
            AtlanticStart.push_back(cell);
        }
        for(int i=0;i<n-1;i++){   //last col
            int cell=i*m+m-1;
            Atlantic.insert(cell);
            AtlanticStart.push_back(cell);
        }

        for(auto it:PacificStart){
            int key=it;
            DFS(key,heights,Pacific);
        }
        for(auto it:AtlanticStart){
            int key=it;
            DFS(key,heights,Atlantic);
        }
        
        //now traverse the grid
        vector<vector<int>>final;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cell=i*m+j;
                if(Pacific.count(cell) && Atlantic.count(cell)){
                    vector<int>temp={i,j};
                    final.push_back(temp);
                }
            }
        }
        return final;
    }
};





