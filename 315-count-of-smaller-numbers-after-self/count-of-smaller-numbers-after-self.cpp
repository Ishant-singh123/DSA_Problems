class Solution {
public:
    int n;
    vector<int>bit;
    int sum(int idx){
        int sum=0;
        while(idx>0){
            sum=sum+bit[idx];
            idx=idx-(idx&(-idx));
        }
        return sum;
    }
    void update(int idx,int val){
        while(idx<=n){
            bit[idx]=bit[idx]+val;
            idx=idx+(idx&(-idx));
        }
    }
    vector<int> inv(vector<int>a){
        vector<int>ans;
        vector<int>sorted=a;
        sort(sorted.begin(),sorted.end());
        sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
        n=sorted.size();
        bit=vector<int>(n+1);
        for(int i=a.size()-1;i>=0;i--){
            int rank=lower_bound(sorted.begin(),sorted.end(),a[i])-sorted.begin()+1;
            ans.push_back(sum(rank-1));  // sum(rank-1) bcz it will provide strictly less then the current element
            update(rank,1);
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans=inv(nums);
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};