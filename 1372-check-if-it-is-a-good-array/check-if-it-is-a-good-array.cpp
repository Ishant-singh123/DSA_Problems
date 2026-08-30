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
    bool isGoodArray(vector<int>& nums) {
        int g=0;
        for(int i=0;i<nums.size();i++){
            if(g==1){
                return true;
            }
            g=gcd(g,nums[i]);
        }
        if(g==1){
            return true;
        }
        return false;
    }
};