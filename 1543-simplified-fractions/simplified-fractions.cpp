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
    vector<string> simplifiedFractions(int n) {
        vector<string>v;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(gcd(i,j)==1){
                    string s=to_string(i)+"/"+to_string(j);
                    v.push_back(s);
                }
            }
        }   
        return v;
    }
};