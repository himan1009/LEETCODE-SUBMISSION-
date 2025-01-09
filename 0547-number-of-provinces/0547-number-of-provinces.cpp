class Solution {
public:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis){
        vis[node]=1;
        for(auto it:adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConn) {
        int N=isConn.size();
        vector<int> adjLs[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(isConn[i][j]==1){
                    adjLs[i].push_back(j);
                }
            }
        }
        vector<int> vis(N, 0);
        int count=0;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;
    }
};