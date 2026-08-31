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
    long long countPairs(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int a=min(nums[i],k);
            int b=max(nums[i],k);
            nums[i]=gcd(a,b);
        }
        unordered_map<long long,long long>mp;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            for(auto p:mp){
                if((p.first*nums[i])%k==0){
                    ans=ans+p.second;
                }
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};