class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long median;
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size()%2==0){
            median=(nums[n/2-1]+nums[n/2])/2;
        }
        else{
            median=nums[(n+1)/2-1];
        }
        long long op=0;
        for(int i=0;i<n;i++){
            if(nums[i]>median){
                op=op+nums[i]-median;
            }
            else{
                op=op+(median-nums[i]);
            }
        }
        return op;
    }
};