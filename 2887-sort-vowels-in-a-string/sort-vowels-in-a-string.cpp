class Solution {
public:
    string sortVowels(string s) {
        vector<int> pos;
        vector<char> ch={'A','E','I','O','U','a','e','i','o','u'};
        map<char,int> mp;
        mp['A']=0;
        mp['E']=0;
        mp['I']=0;
        mp['O']=0;
        mp['U']=0;
        mp['a']=0;
        mp['e']=0;
        mp['i']=0;
        mp['o']=0;
        mp['u']=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if(mp.find(c)!=mp.end())
            {
                mp[c]++; count++;
                pos.push_back(i);
            }             
        }
        int k=0;
        for(int i: pos)
        {
            while(mp[ch[k]]==0)
            {
                k++;
            }
            s[i]=ch[k];
            mp[ch[k]]--;
        }
        return s;
    }
};