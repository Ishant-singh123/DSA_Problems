class Solution {
public:
    vector<int> nse(vector<int>nums){
        vector<int>ans(nums.size());
        stack<int>st;
        st.push(nums.size()-1);
        ans[ans.size()-1]=nums.size();
        for(int i=nums.size()-2;i>=0;i--){
            while(st.size()>0 && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.size()==0){
                ans[i]=nums.size();
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int>nums){
        vector<int>ans(nums.size());
        stack<int>st;
        st.push(0);
        ans[0]=-1;
        for(int i=1;i<nums.size();i++){
            while(st.size()>0 && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.size()==0){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int maxSumMinProduct(vector<int>& nums) {
        vector<long long>pre(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            pre[i+1]=(pre[i]+nums[i]);
        }
        vector<int>right=nse(nums);
        vector<int>left=pse(nums);
        long long ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int r=right[i];
            int l=left[i];
            long long sum=(pre[r]-pre[l+1]);
            ans=max(ans,sum*nums[i]);
        }
        return ans%1000000007;
    }
};