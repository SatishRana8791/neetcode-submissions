class Solution {
public:
void TotalValid(int n,int close,int open,string temp,vector<string>& ans){
    //base case
    if(close+open==2*n){
        ans.push_back(temp);
        return;
    }

    if(open<n){
        temp+='(';
        open++;
        TotalValid(n,close,open,temp,ans);
        temp.pop_back();
        open--;
    }

    if(close<open){
        temp+=')';
        close++;
        TotalValid(n,close,open,temp,ans);
        temp.pop_back();
        close--;
    }

    
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        TotalValid(n,0,0,temp,ans);
        return ans;
    }
};
