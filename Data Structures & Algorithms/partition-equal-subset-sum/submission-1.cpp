class Solution {
public:

    bool findsum(vector<int>&nums,int idx,int sum,int &total){
        if(idx>=nums.size()) return false;
        if(sum==total) return true;
        if(sum>total) return false;

        
        
        //add value in sum                                //without adding the value
        return findsum(nums,idx+1,sum+nums[idx],total) || findsum(nums,idx+1,sum,total);
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        if(total_sum%2 != 0) return false;
        total_sum/=2;
        return findsum(nums,0,0,total_sum);
    }
};
