class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=0;
        //sort the 2-D array
        sort(intervals.begin(),intervals.end());
        int prev=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0] < intervals[prev][1]){
                count++;
                if(intervals[i][1] < intervals[prev][1]){
                    prev = i;
                }
                
            }
            else{
                prev=i;
            }
        }
        return count;
    }
};
