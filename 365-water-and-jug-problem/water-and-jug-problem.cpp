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
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target){
            return false;
        }
        int g=gcd(x,y);
        if(target%g==0){
            return true;
        }
        return false;
    }
};