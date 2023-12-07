class Solution {
public:
    string largestOddNumber(string num) {
        string news = "";
        int len=num.size();
        len--;
        int temp=-1;
        for(int i=len;i>=0;i--)
        {
            int x = num[i]-'0';
            if(x%2==1)
            {temp=i; break;}
        }
        if(temp==-1)
         return "";
        return num.substr(0,temp+1);
    }
};