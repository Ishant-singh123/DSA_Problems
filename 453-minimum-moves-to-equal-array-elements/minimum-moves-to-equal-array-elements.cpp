class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int op=0;
        while(i<j){
            nums[j]=nums[j]+op;
            op=op+nums[j]-nums[i];
            nums[i]=nums[j];
            j--;
        }
        return op;
    }
};