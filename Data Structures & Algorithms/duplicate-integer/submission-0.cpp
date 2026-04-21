class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                return true;
            }
            m[nums[i]]++;
        }
        return false;
    }
};