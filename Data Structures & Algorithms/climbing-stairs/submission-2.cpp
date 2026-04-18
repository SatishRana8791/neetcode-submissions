class Solution {
public:
int reach( int n , int i , vector<int>&dp ){
    if(i==n) return 1;
    if(i>n) return 0;

    if(dp[i] != -1){
        return dp[i];
    }
    return dp[i]=reach(n,i+1,dp)+reach(n,i+2,dp);
}
    int climbStairs(int n) {
        vector<int>dp(n+2,-1);
        dp[0]=reach(n,0,dp);
        return dp[0];
    }
};
