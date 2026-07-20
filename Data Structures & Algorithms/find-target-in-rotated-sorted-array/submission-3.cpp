class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid=(l+r)>>1;
        while(l<=r){
            mid=(l+r)>>1;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[l]){
                if(target>=nums[l]&&target<nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else if(nums[mid]<=nums[r]){
                if(target>nums[mid]&&target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
