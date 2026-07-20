class Solution {
private:
    bool ispossible(int mid,vector<int> &piles,int h){
        int hour=0;
        for(int i=0;i<piles.size();i++){
            hour+=(piles[i]/mid + min(1,piles[i]%mid));
        }
        if(hour<=h) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpiles=-1e9;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxpiles=max(maxpiles,piles[i]);
        }
        int l=1;
        int r=maxpiles;
        int mid=(l+r)>>1;
        while(l<r){
            mid=(l+r)>>1;
            if(ispossible(mid,piles,h)) r=mid;
            else l=mid+1;
        }
        return r;
    }
};
