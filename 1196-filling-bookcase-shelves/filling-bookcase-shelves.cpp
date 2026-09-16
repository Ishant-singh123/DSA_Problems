class Solution {
public:
    int totalwidth;
    int solver(vector<vector<int>>&books,int indx,int remwidth,int maxh,vector<vector<int>>&dp){
        if(indx==books.size()){
            return maxh;
        }
        if(dp[indx][remwidth]!=-1){
            return dp[indx][remwidth];
        }
        int keep=INT_MAX;
        int skip=INT_MAX;
        if(books[indx][0]<=remwidth){
            keep=solver(books,indx+1,remwidth-books[indx][0],max(maxh,books[indx][1]),dp);
        }
        skip=maxh+solver(books,indx+1,totalwidth-books[indx][0],books[indx][1],dp);
        return dp[indx][remwidth]=min(keep,skip); 
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        totalwidth=shelfWidth;
        vector<vector<int>>dp(books.size()+1,vector<int>(shelfWidth+1,-1));
        return solver(books,0,shelfWidth,0,dp);
    }
};