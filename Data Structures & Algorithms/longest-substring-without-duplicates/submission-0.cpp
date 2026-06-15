class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        int len=0;
        int i=0;
        for(int j=0;j<n;j++){
            m[s[j]]++;
            while(m[s[j]] > 1){
                m[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);
        }
        return len;
    }
};
