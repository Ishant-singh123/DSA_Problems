bool cmp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}
class Solution {
public:
    #define mod 1000000007
    int power(int n){
        long long res=1;
        while(n>0){
            res=(res%mod*2%mod)%mod;
            n--;
        }
        return res%mod;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        int count=0;
        vector<vector<int>>ans;
        ans.push_back(ranges[0]);
        for(int i=1;i<ranges.size();i++){
            if(ans[ans.size()-1][1]>=ranges[i][0]){
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],ranges[i][1]);
            }
            else{
                ans.push_back(ranges[i]);
            }
        }
        long long n=ans.size();
        long long x=power(n);
        return x%mod;
    }
};