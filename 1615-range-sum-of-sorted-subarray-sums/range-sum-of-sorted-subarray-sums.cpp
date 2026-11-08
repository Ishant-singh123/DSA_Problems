class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>v;
        v.push_back(0);
        for(int i=0;i<nums.size();i++){
            long long sum=0;
            for(int j=i;j<nums.size();j++){
                sum=sum+nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        for(int i=2;i<v.size();i++){
            v[i]=v[i]+v[i-1];
        }
        return (v[right]%1000000007-v[left-1]%1000000007)%1000000007;
    }
};