class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        for(auto it:m){
            int first=it.first;
            int second=it.second;
            pq.push({second,first});
        }
        
        vector<int>ans;
        while(!pq.empty() && k--){
            
            ans.push_back(pq.top().second);
            pq.pop();

        }
        

        return ans;
    }
};
