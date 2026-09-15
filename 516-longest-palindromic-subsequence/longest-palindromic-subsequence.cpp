class Solution {
public:
    int solver(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i==s.length() || j==t.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(s[i]==t[j]){
            ans=max(ans,1+solver(s,t,i+1,j+1,dp));
        }
        ans=max(ans,solver(s,t,i+1,j,dp));
        ans=max(ans,solver(s,t,i,j+1,dp));
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        string t=s;
        reverse(t.begin(),t.end());
        return solver(s,t,0,0,dp);
    }
};