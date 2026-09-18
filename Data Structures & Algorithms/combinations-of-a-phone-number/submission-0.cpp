class Solution {
public:
    void letter(string digits,int idx,vector<string>& s,string st,unordered_map<char,vector<char>>map){
        //base case here
        if(idx == digits.size()){
            s.push_back(st);
            return;
        }
        
        //now traverse all char in a particular digit in map
        for(auto x:map[digits[idx]]){
            char c=x;
            st+=c;
            letter(digits,idx+1,s,st,map);
            st.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n == 0) return {};
        unordered_map<char,vector<char>>m={ {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},
            {'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},
            {'9',{'w','x','y','z'}}
        };

        //now go for each digits
        vector<string>s;
        string st;
        //call the function
        letter(digits,0,s,st,m);
        return s;
    }
};
