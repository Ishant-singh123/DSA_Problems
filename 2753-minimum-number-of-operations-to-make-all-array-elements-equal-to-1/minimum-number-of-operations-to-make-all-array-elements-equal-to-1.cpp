class Solution {
public:
    // a>b
    int gcd(int a,int b){
        while(b>=1){
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    int minOperations(vector<int>& nums) {
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count1++;
            }
        }
        if(count1>0){
            return nums.size()-count1;
        }
        int op=INT_MAX;

        for(int i=0;i<nums.size()-1;i++){
            int g=nums[i];
            for(int j=i+1;j<nums.size();j++){
                int a=max(g,nums[j]);
                int b=min(g,nums[j]);
                g=gcd(a,b);
                if(g==1){
                    op=min(op,j-i);
                }
            }
        }
        if(op==INT_MAX){
            return -1;
        }
        return nums.size()-1+op;
    }
};