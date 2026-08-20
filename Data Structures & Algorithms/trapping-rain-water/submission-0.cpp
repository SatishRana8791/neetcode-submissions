class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>RSL(n,-1),LSL(n,-1);  //RightSideLargest, LeftSideLargest

        int Leftmax=-1;
        for(int i=0;i<n;i++){
            LSL[i]=Leftmax;
            Leftmax=max(Leftmax,height[i]);    //for left largest first
        }
        int Rightmax=-1;
        for(int i=n-1;i>=0;i--){
            RSL[i]=Rightmax;
            Rightmax=max(Rightmax,height[i]);
        }
        
        int water=0;
        for(int i=0;i<n;i++){
            int minHeight=min(LSL[i],RSL[i]);
            if(minHeight < height[i]){
                continue;
            }
            else{
                water += (minHeight - height[i]);
            }
        }
        return water;
    }
};
