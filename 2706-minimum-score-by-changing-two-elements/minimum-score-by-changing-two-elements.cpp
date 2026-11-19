class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ele=nums[2];
        int ele2=nums[nums.size()-3];
        int ans3=nums[nums.size()-2]-nums[1];
        int ans1=nums[nums.size()-1]-ele;
        int ans2=ele2-nums[0];
        return min(ans1,min(ans2,ans3));
    }
};