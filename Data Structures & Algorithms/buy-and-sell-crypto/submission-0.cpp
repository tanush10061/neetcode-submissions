class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=0;
        int r=0;
        int maxprofit=0;
        while(r<n){
            int buy=prices[l];
            if(prices[r]>buy){
                maxprofit=max(maxprofit,prices[r]-buy);
            }
            else{
                l=r;                
            }
            r++;
        }
        return maxprofit;
    }
};
