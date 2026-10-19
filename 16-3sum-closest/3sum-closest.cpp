class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MIN;
        int diff=INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(abs(nums[i]+nums[j]+nums[k]-target)<diff){
                        ans=nums[i]+nums[j]+nums[k];
                        diff=abs(nums[i]+nums[j]+nums[k]-target);
                    }
                }
            }
        }
        return ans;
    }
};