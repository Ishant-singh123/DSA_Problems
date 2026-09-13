class Solution {
public:
    int solver(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i==s.length()){
            return t.length()-j;
        }
        if(j==t.length()){
            return s.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        if(s[i]==t[j]){
            ans=min(ans,solver(s,t,i+1,j+1,dp));
        }
        else{
            ans=min(ans,1+solver(s,t,i+1,j,dp));
            ans=min(ans,1+solver(s,t,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solver(word1,word2,0,0,dp);
    }
};