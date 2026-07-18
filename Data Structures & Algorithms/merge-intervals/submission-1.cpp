class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>final;
        final.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>&temp=final.back();
            int first=temp[0];
            int second=temp[1];
            if(second>=intervals[i][0]){
                int mini=min(first,intervals[i][0]);
                int maxi=max(second,intervals[i][1]);
                final.back()[0]=mini;
                final.back()[1]=maxi;
            }
            else{
                final.push_back(intervals[i]);
            }
        }
        return final;
    }
};
