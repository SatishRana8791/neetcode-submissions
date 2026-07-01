class Solution {
public:
void BackTrack(vector<int>& nums,vector<int>ans,vector<vector<int>>&final,int idx){
    //base case
    if(idx==nums.size()){
        final.push_back(ans);
        return;
    }

    //not included nums[idx]
    BackTrack(nums,ans,final,idx+1);
    //included nums[idx]
    ans.push_back(nums[idx]);
    BackTrack(nums,ans,final,idx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>final;
        BackTrack(nums,ans,final,0);
        return final;
    }
};
