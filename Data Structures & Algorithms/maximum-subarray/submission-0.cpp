class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int l=0;
        int r=0;
        int n=nums.size();
        int maxsum=INT_MIN;
        while(r<n){
            sum+=nums[r];
            maxsum=max(maxsum,sum);
            while(sum<0){
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return maxsum;
    }
};
