class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && st.top().first < temperatures[i]){
                int idx=st.top().second;
                temperatures[idx]=i-idx;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        while(!st.empty()){
            int idx=st.top().second;
            temperatures[idx]=0;
            st.pop();
        }
        return temperatures;
    }
};
