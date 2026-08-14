class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;

        vector<int>freq1(26,0);
        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
        }

        vector<int>freq2(26,0);
        int j=0;
        for(int i=0;i<=n2-n1;i++){
            
            while(j-i+1 <= n1){
                freq2[s2[j]-'a']++;
                j++;
            }
            if(freq1 ==freq2) return true;
            freq2[s2[i]-'a']--;
        }
        return false;

    }
};
