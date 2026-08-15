class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1<n2) return "";
        
        unordered_map<char,int>m;
        for(int i=0;i<n2;i++){
            m[t[i]]++;
        }

        int len=n1;
        int r=0;int l=0;int startIdx=-1;
        int count=0;
    
        while(r<n1){
            if(m[s[r]]>0){
                count++;
            }
            m[s[r]]-=1;

            while(l<=r && count==n2){
                if(len >= r-l+1){
                    len = r-l+1;
                    startIdx=l;
                }
                m[s[l]]+=1;
                if(m[s[l]]>0){
                    count-=1;
                }
                l++;
            }
            r++;
        }
        return startIdx==-1 ? "" : s.substr(startIdx,len);
    }
};
