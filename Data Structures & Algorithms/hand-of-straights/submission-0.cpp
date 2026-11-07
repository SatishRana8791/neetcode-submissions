class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if( n % groupSize != 0 ) return 0;
        sort(hand.begin(),hand.end());

        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[hand[i]]++;
        }

        int i=0;
        while(i<n ){
            int k=groupSize;
            if( m[hand[i]] == 0 ){
                i=i+1;
                continue;
            } 

            int val=hand[i];
            while(k>0 && m[val] >0 ){
                m[val]--;
                val++;
                k--;
            }
            if(k!=0){
                return 0;
            }
        }
        return 1;
    }
};
