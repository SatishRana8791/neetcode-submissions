class Solution {
public:
void makepermut(vector<int>& nums,vector<vector<int>>&final,vector<int>&temp,vector<int>&visited){
    //base case
    if(temp.size() == visited.size()){
        final.push_back(temp);
        return ;
    }

    for(int i=0;i<nums.size();i++){
        if(!visited[i]){
            visited[i]=1;
            temp.push_back(nums[i]);
            makepermut(nums,final,temp,visited);
            visited[i]=0;
            temp.pop_back();
        }
    }
    
}

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>final;
        vector<int>visited(n,0);
        vector<int>ans;
        makepermut(nums,final,ans,visited);
        return final;
    }
};
