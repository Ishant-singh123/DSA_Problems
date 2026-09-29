class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=5000;
        while(l<=r){
            int mid=(l+r)/2;
            // left sorted
            if(nums[mid]>=nums[l]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};