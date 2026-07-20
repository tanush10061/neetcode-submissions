class Solution {
private:
    void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis,int n,int m){
        vis[row][col]=1;
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]=='1'&&!vis[nr][nc]){
                dfs(nr,nc,grid,vis,n,m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
