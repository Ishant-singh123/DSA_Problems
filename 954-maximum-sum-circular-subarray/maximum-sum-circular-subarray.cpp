class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum=totalsum+nums[i];
        }
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int currsum_maxi=0;
        int currsum_mini=0;

        for(int i=0;i<nums.size();i++){
            currsum_maxi=currsum_maxi+nums[i];
            if(currsum_maxi>maxsum){
                maxsum=currsum_maxi;
            }
            if(currsum_maxi<0){
                currsum_maxi=0;
            }
            currsum_mini=currsum_mini+nums[i];
            if(currsum_mini<minsum){
                minsum=currsum_mini;
            }
            if(currsum_mini>0){
                currsum_mini=0;
            }
        }
        if(maxsum<0){
            return maxsum;
        }
        return max(maxsum,totalsum-minsum);
    }
};