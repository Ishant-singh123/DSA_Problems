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
    int nthMagicalNumber(int n, int a, int b) {
        long long lo=min(a,b);
        long long hi=(long long)n*min(a,b);
        int mini=min(a,b);
        int maxi=max(a,b);
        int lcm=(a*b)/gcd(mini,maxi);
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            long long count=mid/a+mid/b-mid/lcm;
            if(count>=n){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo%1000000007;
    }
};