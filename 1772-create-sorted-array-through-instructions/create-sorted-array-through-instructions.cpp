class Solution {
public:
    #define mod 1000000007
    
    int n;
    vector<int>bit;
    int sum(int idx){
        int ans=0;
        while(idx>0){
            ans=ans+bit[idx];
            idx=idx-(idx&(-idx));
        }
        return ans;
    }
    void update(int idx,int val){
        while(idx<=n){
            bit[idx]=bit[idx]+val;
            idx=idx+(idx&(-idx));
        }
    }
    int inv(vector<int>&a){
        vector<int>sorted=a;
        sort(sorted.begin(),sorted.end());
        sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
        n=sorted.size();
        bit=vector<int>(n+1,0);
        
        int seen=0;
        long long ans=0;
        for(int i=0;i<a.size();i++){
            int rank=lower_bound(sorted.begin(),sorted.end(),a[i])-sorted.begin()+1;
            int less=sum(rank-1);
            int greater=seen-sum(rank);
            update(rank,1);
            seen++;
            ans=(ans%mod+min(greater,less)%mod)%mod;
        }
        return ans;
    }
    int createSortedArray(vector<int>& instructions) {
        return inv(instructions);
    }
};