class Solution {
public:
    int solver(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(j==t.length()){
            return 1;
        }
        if(i==s.length()) return 0;
        if(j==t.length()) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            ans=ans+solver(s,t,i+1,j+1,dp);
        }
            ans=ans+solver(s,t,i+1,j,dp);
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        if(t.length()>s.length()) return 0;
        vector<vector<int>>dp1(s.length()+1,vector<int>(t.length()+1,-1));
        // if(s.length()>t.length()){
            return solver(s,t,0,0,dp1);
        // }
    }
};