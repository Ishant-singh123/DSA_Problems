class Solution {
public:
    int gcd(int a,int b){
        while(a>=1){
            int temp=b%a;
            b=a;
            a=temp;
        }
        return b;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=0;
        int mini=INT_MAX;
        for(int i=0;i<numsDivide.size();i++){
            mini=min(mini,numsDivide[i]);
            g=gcd(g,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        for(i=0;i<nums.size();i++){
            if(g%nums[i]==0){
                break;
            }
        }
        if(i==nums.size()){
            return -1;
        }
        return i;
    }
};