class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int two_side_sum=nums[i]+nums[j];
                int lo=0;
                int hi=nums.size()-1;
                while(lo<=hi){
                    int mid=(lo+hi)/2;
                    if(nums[mid]<two_side_sum){
                        lo=mid+1;
                    } 
                    else{
                        hi=mid-1;
                    }
                }
                if(lo>j){
                    ans=ans+lo-j-1;
                }
                else{
                    ans=ans+0;
                }
            }
        }
        return ans;
    }
};