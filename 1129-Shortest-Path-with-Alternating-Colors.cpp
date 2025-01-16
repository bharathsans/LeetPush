#define f first
#define s second

class Solution {
public:
    vector<int> bfs(vector<vector<pair<int,char>>> &G, int n, map<pair<int,char>, bool>& vis){
        
        queue<pair<int,char>> q;
        q.push({0, 'X'});
        int level = 0;
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;

        while(q.size()){
            int len = q.size();
            ++level;

            while(len--){
                auto node = q.front();
                q.pop();
                vis[node] = 1;

                for(auto cur: G[node.f]){
                    if(!vis[cur]){
                        if(cur.s != node.s){
                            ans[cur.f] = min(ans[cur.f], level);
                            q.push(cur);
                        }
                    }
                }
            }
        }

        for(auto &x: ans)
            if(x == INT_MAX)
                x = -1;


        return ans;

    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,char>>> G(n + 1);
        map<pair<int,char>, bool> vis;

        for(auto red: redEdges){
            G[red[0]].push_back({red[1], 'R'});
        }

        for(auto blue: blueEdges){
            G[blue[0]].push_back({blue[1], 'B'});
        }

        return bfs(G, n, vis);
    }
};