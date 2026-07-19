class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> numscopy=nums;
        sort(numscopy.begin(),numscopy.end());
        int n=nums.size();
        int sum=0;
        int l=0;
        int r=n-1;
        pair<int,int> ans;
        while(l<r){
            sum=numscopy[l]+numscopy[r];
            if(sum>target){
                r--;
            }
            else if(sum<target){
                l++;
            }
            else{
                ans={numscopy[l],numscopy[r]};
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==ans.first){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==ans.second){
                r=i;
                break;
            }
        }
        if(r<l) return {r,l};
        return {l,r};
    }
};
