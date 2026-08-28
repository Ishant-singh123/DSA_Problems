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
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int g=nums[i];
            for(int j=i;j<nums.size();j++){
                g=gcd(g,nums[j]);
                if(g==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};