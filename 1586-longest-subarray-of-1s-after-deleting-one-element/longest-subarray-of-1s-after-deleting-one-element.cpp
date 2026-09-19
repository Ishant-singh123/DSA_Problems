class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen=0;
        int r=0;
        int l=0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while((r-l+1)-mp[1]>1){
                mp[nums[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l);
            r++;
        }
        return maxlen;
    }
};