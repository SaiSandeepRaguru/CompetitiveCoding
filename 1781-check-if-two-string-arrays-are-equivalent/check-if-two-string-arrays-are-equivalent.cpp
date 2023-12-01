class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x="";
        string y="";
        for(string s1: word1)
        {
            x= x+s1;
        }

        for(string s1: word2)
        {
            y= y+s1;
        }
        return x.compare(y)==0?true:false;
    }
};