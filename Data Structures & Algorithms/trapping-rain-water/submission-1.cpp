class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        //method 2 using maxheight find
        int idx=-1;
        int maxHeight=-1;
        for(int i=0;i<n;i++){
            if(maxHeight <= height[i]){
                maxHeight = height[i];
                idx = i;
            }
        }

        //now calculate water till idx
        int water=0;
        int leftMax=-1;
        for(int i=0;i<=idx;i++){
            int minheight=min(leftMax,maxHeight);
            leftMax=max(leftMax,height[i]);
            if(minheight < height[i]){
                continue;
            }
            else{
                water+=(minheight-height[i]);
            }
        }
        //now index to n
        int rightmax=-1;
        for(int i=n-1;i>idx;i--){
            int minheight=min(rightmax,maxHeight);
            rightmax=max(rightmax,height[i]);
            if(minheight < height[i]){
                continue;
            }
            else{
                water+=(minheight-height[i]);
            }
        }
        return water;
    }
};
