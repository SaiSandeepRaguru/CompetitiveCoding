class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char c: tasks){
            mp[c]++;
        }
        priority_queue<int> pq;
        int interval = n+1; 
        //n is the time between A to A, so in one interval A,B,C => 3 => n+1
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push(i->second); //we need just frequencies
        }
        int res=0;
        int size=pq.size();
        while(!pq.empty()){
            int size=pq.size();
            queue<int> q;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top(); pq.pop();
                    if(freq>1){
                        q.push(freq-1);
                    }
                }
            }
            while(!q.empty()){
                pq.push(q.front()); q.pop();
            }
            if(pq.size()==0){
                res+=size; break;
            }
            else{
            res+=interval;
            }
        }
        return res;
    }
};