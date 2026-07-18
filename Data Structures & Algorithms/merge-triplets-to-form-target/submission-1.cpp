class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        vector<int>temp(3,0);
        for(int i=0;i<n;i++){
            int f=triplets[i][0];
            int s=triplets[i][1];
            int t=triplets[i][2];

            if(f > target[0] || s > target[1] || t > target[2]){
                continue;
            }
            else{
                temp[0]=max(temp[0],f);
                temp[1]=max(temp[1],s);
                temp[2]=max(temp[2],t);
            }

            if(temp==target) return true;
        }



        // if(triplets[0] == target) return true;
        
        // for(int i=1;i<n;i++){
           
        //     if(triplets[i] == target) return true;

        //     triplets[i][0] = max(triplets[i][0] , triplets[i-1][0]);
        //     triplets[i][1] = max(triplets[i][1] , triplets[i-1][1]);
        //     triplets[i][2] = max(triplets[i][2] , triplets[i-1][2]);

        //     if(triplets[i]==target) return true;

        // }
        return false;
    }
};
