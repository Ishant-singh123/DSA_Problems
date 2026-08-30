class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIndx=-1;
        int minIndx=-1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                maxIndx=i;
            }
            if(mini>nums[i]){
                mini=nums[i];
                minIndx=i;
            }
        }
        
        int count=INT_MAX;
        //max
        int distMF=maxIndx-0+1;
        int distMB=nums.size()-maxIndx;
        //min
        int distmF=minIndx-0+1;
        int distmB=nums.size()-minIndx;
        int ans=INT_MAX;
                count=min(count,max(distMF,distmF));
                count=min(count,(distMF+distmB));
                count=min(count,(distMB+distmF));
                count=min(count,max(distMB,distmB));
        return count;
    }
};