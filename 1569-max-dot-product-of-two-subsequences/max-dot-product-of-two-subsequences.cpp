class Solution {
public:
    int solver(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res=INT_MIN;
        res=max(res,nums1[i]*nums2[j]+solver(nums1,nums2,i+1,j+1,dp));
        res=max(res,0+solver(nums1,nums2,i+1,j,dp));
        res=max(res,0+solver(nums1,nums2,i,j+1,dp));
        return dp[i][j]=res;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        bool check=false;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            maxi=max(maxi,nums1[i]);
            mini=min(mini,nums1[i]);
            if(nums1[i]>=0){
                check=true;
            }
        }
        int maxi2=INT_MIN;
        int mini2=INT_MAX;
        bool check2=false;
        for(int i=0;i<nums2.size();i++){
            maxi2=max(maxi2,nums2[i]);
            mini2=min(mini2,nums2[i]);
            if(nums2[i]>=0){
                check2=true;
            }
        }
        int res=solver(nums1,nums2,0,0,dp);
        if(check==false && check2==false){
            return res;
        }
        if(check==false){
            return maxi*mini2;
        }
        if(check2==false){
            return mini*maxi2;
        }
        return res;
    }
};