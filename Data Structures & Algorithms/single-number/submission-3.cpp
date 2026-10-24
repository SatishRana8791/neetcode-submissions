class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int value=0;
        for(auto it:nums){
            value ^=it;
        }
        return value;
    }
};
