class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>Left(n,1),Right(n,1);
        for(int i=1;i<n;i++){
            Left[i]=Left[i-1]*nums[i-1];
            int j=n-i-1;
            Right[j]=Right[j+1]*nums[j+1];
        }
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=Left[i]*Right[i];
        }
        return temp;
    }
};
