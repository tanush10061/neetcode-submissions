class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf=2^31-1;
        int n=grid[0].size();
        int m=grid.size();
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) q.push({0,{i,j}});
            }
        }
        int dr[4]={1,0,-1,0};
        int dc[4]={0,-1,0,1};
        while(!q.empty()){
            int step=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]!=-1){
                    if(grid[nr][nc]>step+1){
                        grid[nr][nc]=step+1;
                        q.push({grid[nr][nc],{nr,nc}});
                    }
                }
            }
        }
    }
};
