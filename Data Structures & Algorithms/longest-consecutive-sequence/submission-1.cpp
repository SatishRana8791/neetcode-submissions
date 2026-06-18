class Solution {
public:
    int checkdepth(int value,unordered_map<int,int>& m){
        //check exists or not
        if( m.find(value-1) == m.end() ) return 0;
    
        return 1+checkdepth(value-1,m);
        
    }

    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int len=0;
        for(int i=0;i<n;i++){
            len=max(len,checkdepth(nums[i],m));
        }
        return len+1;
    }
};
