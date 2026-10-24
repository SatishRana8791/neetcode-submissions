/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        vector<int>start(n),end(n);
        for(int i=0;i<n;i++){
            start[i]=intervals[i].start;
            end[i]=intervals[i].end;
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int s=0,e=0;
        int maxrooms=0,count=0;
        while(s<n && e<n){
            while(s<n && e<n && start[s] < end[e]){
                count++;
                s++;
            }
            maxrooms=max(maxrooms,count);
            if(s<n && e<n && end[e] <= start[s]){
                e++;
                count--;
            }
        }
        return maxrooms;
    }
};
