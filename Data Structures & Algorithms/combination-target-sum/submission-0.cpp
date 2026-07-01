class Solution {
public:
void BackTrack(vector<int>& nums,vector<vector<int>>& final,vector<int>ans,int idx,int sum,int target){
    //base case
    if(idx>=nums.size() || sum > target ){
        return;
    }
    if(sum==target){
        final.push_back(ans);
        return;
    }



    //not included
    BackTrack(nums,final,ans,idx+1,sum,target);
    //included nums[idx]
    ans.push_back(nums[idx]);
    BackTrack(nums,final,ans,idx,sum+nums[idx],target);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>final;
        BackTrack(nums,final,ans,0,0,target);
        return final;
    }
};
