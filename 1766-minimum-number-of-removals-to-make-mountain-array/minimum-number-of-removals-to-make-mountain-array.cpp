class Solution {
public:

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis(nums.size(),1);
        vector<int>lds(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],1+lis[j]);
                }
            }
        }    
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(lis[i]>1 && lds[i]>1){
                ans=min(ans,n-lis[i]-lds[i]+1);
            }
        }
        return ans;
    }
};