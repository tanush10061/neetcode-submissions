class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        int cnt=0;
        int ucl=n-1;
        int url=m-1;
        int lcl=0;
        int lrl=0;
        while(cnt<m*n){
            for(int i=lcl;i<=ucl;i++){
                ans.push_back(matrix[lrl][i]);
                cnt++;
            }
            lrl++;
            if(cnt>=m*n) break;
            for(int i=lrl;i<=url;i++){
                ans.push_back(matrix[i][ucl]);
                cnt++;
            }
            ucl--;
            if(cnt>=m*n) break;
            for(int i=ucl;i>=lcl;i--){
                ans.push_back(matrix[url][i]);
                cnt++;
            }
            url--;
            if(cnt>=m*n) break;
            for(int i=url;i>=lrl;i--){
                ans.push_back(matrix[i][lcl]);
                cnt++;
            }
            lcl++;
        }
        return ans;
    }
};
