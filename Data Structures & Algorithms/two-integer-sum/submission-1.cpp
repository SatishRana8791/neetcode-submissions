class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(m.count(rem)){
                return {m[rem],i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};
