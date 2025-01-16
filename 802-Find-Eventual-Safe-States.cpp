class Solution {
public:

    // Cycle detection algorithm using DFS for directed graphs...
    // While doing cycle detection mark all the nodes not part of cycle as true... 

    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& pathVis,
    vector<bool>& good){

        vis[node] = 1;
        pathVis[node] = 1;

        bool isCycle = false;
        for(auto cur: graph[node]){
            if(!vis[cur]){
                if(dfs(cur, graph, vis, pathVis, good)){
                    // good[cur] = false;
                    return true;
                }
            }
            else{
                if(pathVis[cur]){
                    // good[cur] = false;
                    return true;
                }
            }
        }
        
        pathVis[node] = 0;
        good[node] = true;
        return isCycle;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> vis(n + 1, 0);
        vector<bool> pathVis(n + 1, 0);
        vector<bool> good(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(i, graph, vis, pathVis, good);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(good[i])
                ans.push_back(i);
        }


        return ans;
    }
};