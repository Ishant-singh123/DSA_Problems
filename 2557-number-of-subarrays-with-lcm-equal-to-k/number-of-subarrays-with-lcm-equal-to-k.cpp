class Solution {
public:
    long long gcd(long long a,long long b){
        while(a>=1){
            long long temp=b%a;
            b=a;
            a=temp;
        }
        return b;
    }
    int subarrayLCM(vector<int>& nums, int k) {
       int cnt=0;
        for(int i=0;i<nums.size();i++){
            long long l=1;
            for(int j=i;j<nums.size();j++){
                l=l*nums[j]/(gcd(nums[j],l));
                if(l==k){
                    cnt++;
                }
                if(l>k){
                    break;
                }
            }
        } 
        return cnt;
    }
};