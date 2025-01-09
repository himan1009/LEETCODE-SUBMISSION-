class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1)
        return 0;

        grid[i][j]=0;

        int area=1;
        area=area+dfs(i-1, j, grid);
        area=area+dfs(i, j+1, grid);
        area=area+dfs(i+1, j, grid);
        area=area+dfs(i, j-1, grid);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int maxArea=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};