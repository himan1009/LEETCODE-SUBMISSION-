class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& isConn){
        vis[node]=1;
        for(int i=0;i<isConn.size();i++){
            if(isConn[node][i]==1 && vis[i]==0){
                dfs(i, vis, isConn);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConn) {
        int N=isConn.size();
        vector<int> vis(N, 0);
        int count=0;
        for(int i=0;i<N;i++){
            if(vis[i]==0){
                count++;
                dfs(i, vis, isConn);
            }
        }
        return count;
    }
};