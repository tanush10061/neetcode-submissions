class Solution {
private:
   void dfs(int row,int col,vector<vector<int>> grid,vector<vector<int>> &vis,int &area){
    vis[row][col]=1;
    area++;
    int dr[4]={0,-1,0,1};
    int dc[4]={1,0,-1,0};
    for(int i=0;i<4;i++){
        int nr=row+dr[i];
        int nc=col+dc[i];
        if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&grid[nr][nc]==1&&!vis[nr][nc]){
            dfs(nr,nc,grid,vis,area);
        }
    }
   }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area=0;
                if(!vis[i][j]&&grid[i][j]==1){
                    dfs(i,j,grid,vis,area);
                }
                maxarea=max(maxarea,area);
            }
        }
        return maxarea;
    }
};
