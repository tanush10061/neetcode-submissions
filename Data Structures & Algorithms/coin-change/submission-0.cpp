class Solution {
public:
    int mincoins(int ind,vector<int> &coins,int amount){
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(ind==coins.size()){
            return 1e9;
        }
        int take=1e9;
        if(amount>=coins[ind]){
            take=1+mincoins(ind,coins,amount-coins[ind]);
        }
        int skip=mincoins(ind+1,coins,amount);
        return min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(mincoins(0,coins,amount)==1e9) return -1;
        return mincoins(0,coins,amount);
    }
};
