class Solution {
public:
    int bfs(vector<vector<int>>& G, vector<vector<int>>& dummy, int n){

        // dummy (back edge) -> no cost...
        // actual edge -> + 1... flip needed to reach cur node

        queue<int> q;
        q.push(0);
        int cost = 0;
        vector<bool> vis(n + 1, 0);

        while(q.size()){
            int len = q.size();
            while(len--){
                int node = q.front();
                vis[node] = 1;
                q.pop();

                for(auto cur: G[node]){
                    if(!vis[cur]){    
                        ++cost;
                        q.push(cur);
                    }
                }
                for(auto cur: dummy[node])
                    if(!vis[cur])
                        q.push(cur);
            }
        }

        return cost;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> G(n + 1);
        vector<vector<int>> dummy(n + 1);

        for(auto connection: connections){
            G[connection[0]].push_back(connection[1]);
            dummy[connection[1]].push_back(connection[0]);
        }

        return bfs(G, dummy, n);
        
    }
};