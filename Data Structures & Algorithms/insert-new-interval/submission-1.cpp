class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>>ans;
        int i=0;
        while(i<n){
            int second=intervals[i][1];
            int first=intervals[i][0];
            if(second < newInterval[0]){
                ans.push_back(intervals[i]);
            }
            if(second>=newInterval[0] && first>newInterval[1]){
                break;
            }
            if(second>=newInterval[0] && first<=newInterval[1]){
                //update the newInterval
                newInterval[0]=min(newInterval[0],first);
                newInterval[1]=max(newInterval[1],second);
            }
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
