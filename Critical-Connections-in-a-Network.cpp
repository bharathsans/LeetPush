class Solution {
public:
    int T = 1;
    vector<vector<int>> bridges;
    void dfs(int cur, int par, vector<int>& time, vector<int>& low, 
            vector<vector<int>>& adj){
        time[cur] = low[cur] = T;
        T++;
        for(auto nei: adj[cur]){
            if(nei == par) continue;
            if(time[nei] > 0){ // Already visisted...
                // Via different path -> Cannot be a bridge, just update low...
                low[cur] = min(low[cur], low[nei]);
            }
            else{ // Not visited...
                dfs(nei, cur, time, low, adj);
                low[cur] = min(low[cur], low[nei]);
                // Bridge if lowest possible time of nei is greater than cur..
                if(low[nei] > time[cur])
                    bridges.push_back({cur, nei});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n + 1);
        for(auto connection: connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        vector<int> time(n, 0);
        vector<int> low(n);
        dfs(0, -1, time, low, adj);
        return bridges;
    }
};  