class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr=0;
        int countzeros=0;
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
            if(nums[i]==0){
                countzeros++;
            }
        }
        if(xorr!=0){
            return nums.size();
        }
        if(countzeros==nums.size()){
            return 0;
        }
        return nums.size()-1;
    }
};