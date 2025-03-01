class Solution {
public:
    struct Comparator {
    bool operator()(vector<int>& a, vector<int>& b) {
        return (sqrt(a[0]*a[0] + a[1]*a[1]) > sqrt(b[0]*b[0] + b[1]*b[1])); // Max-heap based on distance
    }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
        for(vector<int> point: points){
            pq.push(point);
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top()); pq.pop();
        } 
        return res;
    }
};