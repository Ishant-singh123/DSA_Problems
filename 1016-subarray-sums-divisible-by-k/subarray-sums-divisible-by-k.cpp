class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        mp[0]=1;
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            int val;
            if(nums[i]<0){
                val=(nums[i]%k+k)%k;
            }
            else{
                val=nums[i]%k;
            }
            if(mp.find(val)!=mp.end()){
                count=count+mp[val];
            }
            mp[val]++;
        }
        return count;
    }
};