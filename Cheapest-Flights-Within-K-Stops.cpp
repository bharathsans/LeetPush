using ti = tuple<int, int, int>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue< ti, vector<ti>, greater<ti>> pq;
        vector<int> stopc(n + 1, INT_MAX);
        vector<pair<int,int>> adj[n+1];
        for(auto x: flights){
            adj[x[0]].push_back({x[1], x[2]}); 
        }
        vector<int> dist(n+5, 1e9 + 5);
        dist[src] = 0;
        pq.push({0, src, 0});
        while(pq.size()){
            auto [d, prev, stops] = pq.top();
            pq.pop();
            if(stops > k || stops > stopc[prev])
                continue;
            stopc[prev] = stops;
            for(auto [cur, nd]: adj[prev]){
                if(dist[cur] > d + nd){
                    dist[cur] = d + nd;
                }
                pq.push({d + nd, cur, stops + 1});
            }
        }
        if(dist[dst] == (1e9 + 5))
            return -1;
        return dist[dst];
    }
};