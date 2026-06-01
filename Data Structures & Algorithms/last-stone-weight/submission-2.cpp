class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;  //max heap 
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(abs(first-second) != 0){
                pq.push(abs(first-second));
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
