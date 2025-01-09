class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int, int>> q;
        int fresh=0;
        int minutes=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push({i, j});
                else if(grid[i][j]==1)
                fresh++;
            }
        }

        vector<pair<int, int>> dir={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty() && fresh>0){
            int size=q.size();
            minutes++;

            for(int i=0;i<size;i++){
                auto [x, y]=q.front();
                q.pop();

                for(auto [dx, dy]:dir){
                    int newX=x+dx;
                    int newY=y+dy;

                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                        grid[newX][newY]=2;
                        q.push({newX, newY});
                        fresh--;
                    }
                }
            }
        }
        if(fresh==0)
        return minutes;
        else 
        return -1;
    }
};