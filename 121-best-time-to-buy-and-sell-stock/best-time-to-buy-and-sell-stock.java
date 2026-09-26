class Solution {
    public int maxProfit(int[] prices) {
        int mini=1000001;
        int ans=-1;
        for(int i=0;i<prices.length;i++){
            mini=Math.min(mini,prices[i]);
            ans=Math.max(ans,prices[i]-mini);
        }
        return ans;
    }
}