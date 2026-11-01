class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int num;
            if(nums[i]<0){
                num=(k-(abs(nums[i])%k))%k;
            }
            else{
                num=nums[i]%k;
            }
            if(mp.find(num)!=mp.end()){
                count=count+mp[num];
            }
            mp[num]++;
        }
        return count;
    }
};