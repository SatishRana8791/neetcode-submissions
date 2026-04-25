class Solution {
public:
    int getSum(int a, int b) {
        //use xor to get the sum
        //and use & to get the carry and left shift
        while(b!=0){
            int carry= (unsigned)(a&b) <<1;  //left shift
            a=a^b;
            b=carry;
        }
        return a;
    }
};
