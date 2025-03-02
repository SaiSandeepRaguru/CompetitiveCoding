class Solution {
public:
    int climbStairs(int n) {
        int first=1;
        int second=2;
        if(n<=2){
            return n;
        }
        int i=3;
        while(i<=n){
            int temp = first + second;
            first=second;
            second = temp;
            i++;
        }
        return second;
    }
};