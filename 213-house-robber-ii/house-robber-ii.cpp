class Solution {
public:
    int solver(vector<int>&nums,int indx,int end,vector<int>&dp){
        if(indx>end){
            return 0;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }
        int ans=INT_MIN;
        ans=max(ans,nums[indx]+solver(nums,indx+2,end,dp));
        ans=max(ans,solver(nums,indx+1,end,dp));
        return dp[indx]=ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        return max(solver(nums,0,nums.size()-2,dp),solver(nums,1,nums.size()-1,dp2));
    }
};