class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            if(s.contains(nums[i])){
                s.erase(nums[i]);
            }
            else{
                s.insert(nums[i]);
            }
            
        }
        return *s.begin();
    }
};


