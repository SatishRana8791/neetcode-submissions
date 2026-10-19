class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int top=st.top();
                st.pop();
                if(!st.empty()){
                    int area=heights[top]*(i-st.top()-1);
                    maxArea=max(maxArea,area);
                }
                else{
                    int area=heights[top]*i;
                    maxArea=max(maxArea,area);
                }
                
            }
            st.push(i);
        }
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(!st.empty()){
                int area=heights[top]*(n-st.top()-1);
                maxArea=max(maxArea,area);
            }
            else{
                int area=heights[top]*n;
                maxArea=max(maxArea,area);
            }
        }
        return maxArea;
    }
};
