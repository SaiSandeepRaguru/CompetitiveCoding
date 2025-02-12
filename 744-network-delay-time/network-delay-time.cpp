#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int node, distance;
    Pair(int n, int d) : node(n), distance(d) {}

    // Define comparison operator for priority_queue (min-heap)
    bool operator>(const Pair& p) const {
        return distance > p.distance;
    }
};

class Solution {
public:
    void dijkstraUsingTreeSet(vector<int>& distance, vector<bool>& visited, int src, unordered_map<int, vector<Pair>>& adj) {
        set<int, function<bool(int, int)>> treeSet([&distance](int p1, int p2) {
            if (distance[p1] == distance[p2]) return p1 < p2;
            return distance[p1] < distance[p2];
        });

        int n = visited.size();
        fill(distance.begin(), distance.end(), INT_MAX);
        distance[src] = 0;
        treeSet.insert(src);

        while (!treeSet.empty()) {
            int node = *treeSet.begin();
            treeSet.erase(treeSet.begin());

            for (Pair& nextNodePair : adj[node]) {
                if (distance[node] + nextNodePair.distance < distance[nextNodePair.node]) {
                    treeSet.erase(nextNodePair.node);
                    distance[nextNodePair.node] = distance[node] + nextNodePair.distance;
                    treeSet.insert(nextNodePair.node);
                }
            }
        }
    }

    void dijkstra(vector<int>& distance, vector<bool>& visited, int src, unordered_map<int, vector<Pair>>& adj) {
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        int n = visited.size();
        fill(distance.begin(), distance.end(), INT_MAX);
        distance[src] = 0;
        pq.push({src, 0});

        int visitedNodes = 0;
        while (!pq.empty() && visitedNodes < (n - 1)) {
            Pair pair = pq.top();
            pq.pop();
            if (visited[pair.node]) continue;
            visited[pair.node] = true;
            visitedNodes++;

            for (Pair& nextNodePair : adj[pair.node]) {
                if (pair.distance + nextNodePair.distance < distance[nextNodePair.node]) {
                    distance[nextNodePair.node] = pair.distance + nextNodePair.distance;
                    pq.push({nextNodePair.node, distance[nextNodePair.node]});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<int> distance(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);

        unordered_map<int, vector<Pair>> adj;
        for (vector<int>& edge : times)
            adj[edge[0]].emplace_back(edge[1], edge[2]);

        dijkstraUsingTreeSet(distance, visited, src, adj);

        int maxTime = 0;
        for (int i = 1; i <= n; i++)
            if (distance[i] == INT_MAX)
                return -1;
            else
                maxTime = max(distance[i], maxTime);

        return maxTime;
    }
};
