class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x: stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            if(first!=second){
                pq.push(first-second);
            }
        }
        return (pq.size()==0)?0:pq.top();
    }
};