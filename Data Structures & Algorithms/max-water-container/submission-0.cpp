class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;
        int i=0,j=n-1;
        while(i<j){
            int wide=j-i;
            int area=wide * min(heights[i],heights[j]);
            maxarea=max(area,maxarea);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return maxarea;
    }
};
