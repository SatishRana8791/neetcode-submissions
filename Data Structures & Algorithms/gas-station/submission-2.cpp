class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int total_cost=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
        }

        if(total_gas < total_cost) return -1;

        int idx=-1;
        int stock=0;
        for(int i=0;i<n;i++){
            if(stock + gas[i] >= cost[i]){
                stock+=gas[i]-cost[i];
            }
            else{
                idx=i+1;
                stock=0;
            }
        }
        return idx == -1 ? idx+1 : idx ;
    }
};
