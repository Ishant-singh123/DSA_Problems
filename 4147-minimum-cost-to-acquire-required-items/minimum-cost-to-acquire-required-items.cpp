class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int common_quantity=min(need1,need2);
        int common_cost=min(costBoth,cost1+cost2);
        long long ans=0;
        ans=ans+(long long)common_quantity*common_cost;
        if(need1>need2){
            ans=ans+(long long)(need1-need2)*min(costBoth,cost1);
        }
        if(need2>need1){
            ans=ans+(long long)(need2-need1)*min(costBoth,cost2);
        }
        return ans;
    }
};