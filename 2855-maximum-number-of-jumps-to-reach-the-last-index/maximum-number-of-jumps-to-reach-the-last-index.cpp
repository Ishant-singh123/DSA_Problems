class Solution {
public:
    int solver(vector<int>&nums,int indx,int target,vector<int>&dp){
        if(indx>=nums.size()){
            return INT_MIN;
        }
        if(indx==nums.size()-1){
            return 0;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }
        int ans=INT_MIN;
        for(int i=indx+1;i<nums.size();i++){
            if((long long)nums[i]+(long long)target>=nums[indx] && (long long)nums[i]-(long long)target<=nums[indx]){
                ans=max(ans,1+solver(nums,i,target,dp));
            }
        }
        return dp[indx]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-1);
        int ans=solver(nums,0,target,dp);
        cout<<INT_MIN;
        if(ans<0){
            return -1;
        }
        return ans;
    }
};