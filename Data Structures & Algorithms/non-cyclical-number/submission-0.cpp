class Solution {
public:
    bool checkNonCyclical(int num, map<int,int>& m){
        int ans=0;
        while(num!=0){
            int mod=num%10;
            ans+=(mod*mod);
            num/=10;
        }
        if(m[ans] >=1) return false;
        if(ans == 1) return true;

        m[ans]++;
        return checkNonCyclical(ans,m);
    }
    bool isHappy(int n) {
        map<int,int>m;
        return checkNonCyclical(n,m);
    }
};

