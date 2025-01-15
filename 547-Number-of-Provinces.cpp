class Solution {
public:
    
    void initialize(int n, vector<int>& root){
        for(int i=0;i<n;i++){
            root[i] = i;
        }
    }
    
    int find(int city, vector<int>& root){
        if(root[city] == city)
            return city;
        
        return root[city] = find(root[city], root);
    }

    void merge(int city1,int city2, vector<int>& root){
        int rootCity1 = find(city1, root);
        int rootCity2 = find(city2, root);
        root[rootCity1] = rootCity2;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int> root(n+1);
        initialize(n,root);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int connect = isConnected[i][j];
                if(connect == 1){
                    merge(i,j,root);
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(root[i] == i)
                ++ans;
            
        }
        return ans;
    }
};