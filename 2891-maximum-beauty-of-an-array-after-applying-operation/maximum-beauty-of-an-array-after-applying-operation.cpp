class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int>ans(1000000,0);
        int grt=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int mini=nums[i]-k;
            int maxi=nums[i]+k;
            grt=max(grt,maxi);
            if(mini<=0){
                ans[0]=ans[0]+1;
                ans[maxi+1]=ans[maxi+1]-1;
            }
            else{
                ans[mini]=ans[mini]+1;
                ans[maxi+1]=ans[maxi+1]-1;
            }
        }
        int res=0;
        for(int i=1;i<=grt;i++){
            ans[i]=ans[i]+ans[i-1];
            res=max(res,ans[i]);
        }
        return res;
    }
};