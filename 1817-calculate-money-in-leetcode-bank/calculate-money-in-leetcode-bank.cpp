class Solution {
public:
    int totalMoney(int n) {
        int it=1;
        int sum=it,next=it;
        for(int i=2;i<=n;i++)
        {
            if(i%7==1)
            {
                it++;
                next=it;
            }
            else
            {
                next++;
            }
            sum+=next;
        }
        return sum;
    }
};