class Solution {
public:
// Remember this pattern
// Whenever you see:
// Choose a value → gain points → cannot choose adjacent values

// Think:
// Group duplicates
//       ↓
// points[x] = total gain from x
//       ↓
// Take x → solver(x-2)
// Skip x → solver(x-1)
//       ↓
// dp[x] = max(skip, take)

    int solver(vector<int>&points,int indx,vector<int>&dp){
        if(indx<=0){
            return 0;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }
        int skip=solver(points,indx-1,dp);
        int taken=points[indx]+solver(points,indx-2,dp);
        return dp[indx]=max(skip,taken);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int>points(maxi+1,0);
        for(int i=0;i<nums.size();i++){
            points[nums[i]]=points[nums[i]]+nums[i];
        }
        vector<int>dp(points.size()+1,-1);
        return solver(points,maxi,dp);
    }
};