class Solution {
public:
    // int minCost(vector<int>cost , int n){
    //     if(n<=1) return 0;

    //     return min (cost[n-1]+minCost(cost,n-1),cost[n-2]+minCost(cost,n-2));
    // }
    int minStairCost(vector<int>cost,int n,vector<int>& dp){
        if(n<=1)
        return 0;

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n]=min(cost[n-1]+minStairCost(cost,n-1,dp), cost[n-2]+minStairCost(cost,n-2,dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // return minCost(cost,n);
        vector<int>dp(n+1,-1);
        return minStairCost(cost , n, dp);
    }
};
