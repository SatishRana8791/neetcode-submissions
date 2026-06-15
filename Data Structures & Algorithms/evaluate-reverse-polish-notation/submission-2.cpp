class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int num1,num2;
                int len=1;
                while(!st.empty() && len--){
                    num2=st.top();
                    st.pop();
                    num1=st.top();
                    st.pop();
                }
                if(tokens[i]=="+"){
                    st.push(num1+num2);
                }
                else if(tokens[i]=="-"){
                    st.push(num1-num2);
                }
                else if(tokens[i]=="*"){
                    st.push(num1*num2);
                }
                else{
                    st.push(num1/num2);
                }
            }
            else{
                int num=stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
