class Solution {
public:
    string expand(int mid1,int mid2,string s,int n){
        int start=mid1;
        int end=mid2;
        int len=1;
        while(start>=0&&end<n){
            if(s[start]==s[end]){
                len=end-start+1;
                start--;
                end++;
            }
            else break;
        }
        return s.substr(start+1,len);
    }
    string longestPalindrome(string s) {
        int n=s.length();
        // vector<vector<bool>> dp(n,vector<bool>(n,false));
        // int start=0;
        // int maxlen=1;
        // for(int i=0;i<n;i++){
        //     dp[i][i]=true;
        // }
        // for(int len=2;len<=n;len++){
        //     for(int i=0;i<=n-len;i++){
        //         int j=i+len-1;
        //         if(s[i]==s[j]){
        //             if(len==2) dp[i][j]=true;
        //             else{
        //                 dp[i][j]=dp[i+1][j-1];
        //             }
        //         }
        //         if(dp[i][j]&&(j-i+1)>maxlen){
        //             start=i;
        //             maxlen=j-i+1;
        //         }
        //     }
        // }
        // return s.substr(start,maxlen);
        string ans="";
        for(int i=0;i<n;i++){
            if(expand(i,i,s,n).length()>ans.length()) ans=expand(i,i,s,n);
            if(expand(i,i+1,s,n).length()>ans.length()) ans=expand(i,i+1,s,n);
        }
        return ans;
    }
};
