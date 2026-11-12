class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        vector<int>pre(nums.size(),1);
        vector<int>suff(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                pre[i]=pre[i-1]+1;
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                suff[i]=suff[i+1]+1;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<pre.size();i++){
            ans=max(ans,pre[i]);
        }
        cout<<endl;
        for(int i=0;i<pre.size();i++){
            ans=max(ans,suff[i]);
        }
        return ans;
    }
};