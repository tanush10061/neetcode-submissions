class Solution {
public:
    int mincoins(int ind,vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(ind==coins.size()){
            return 1e9;
        }
        if(dp[amount][ind]!=-1) return dp[amount][ind];
        int take=1e9;
        if(amount>=coins[ind]){
            take=1+mincoins(ind,coins,amount-coins[ind],dp);
        }
        int skip=mincoins(ind+1,coins,amount,dp);
        return dp[amount][ind]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        if(mincoins(0,coins,amount,dp)==1e9) return -1;
        return mincoins(0,coins,amount,dp);
    }
};
