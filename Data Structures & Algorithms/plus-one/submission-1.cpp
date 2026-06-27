class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1] != 9){
            digits[n-1]+=1;
            return digits;
        }
        else{
            vector<int>ans;
            int carry=1;
            int carry0;
            for(int i=n-1;i>=0;i--){
                int val=digits[i]+carry;
                carry=val/10;
                int digit=val%10;
                ans.push_back(digit);
            }
            if(carry){
                ans.push_back(carry);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};
