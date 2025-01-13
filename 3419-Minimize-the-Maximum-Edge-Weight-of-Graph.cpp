class Solution {
public: 

    // 1. Reverse graph to check if all nodes reachable from 0 in one bfs.
    // 2. Binary search on maximum edge weight and traverse graph
    // 3. Threshold doesn't matter
        // -> In the reversed graph incoming edge count <= threshold
        // -> While doing BFS/ DFS you will only come the node from any one path
        // -> So indegree at max will be 1 for the graph we traverse...

    int isValid(vector<vector<pair<int,int>>>& G, int max_val, int n){
        
        vector<bool> vis(n, 0);
        int visCnt = 0;

        queue<int> bfs;
        bfs.push(0);
        vis[0] = 1;
        visCnt++;

        while(bfs.size()){
            int curNode = bfs.front();
            bfs.pop();
            for(auto node: G[curNode]){
                if(!vis[node.first] && node.second <= max_val){
                    bfs.push(node.first);
                    vis[node.first] = 1;
                    visCnt++;
                }
            }            
        }
        
        if(visCnt == n)
            return true;

        return false;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        vector<vector<pair<int,int>>> G(n);

        for(auto e: edges){
            G[e[1]].push_back({e[0], e[2]});
        }

        int low = 0;
        int high = 1e6 + 5;

        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(G, mid, n)){
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};