// bool cmp(pair<int,int>p1,pair<int,int>p2){
//     return (p1.first<p2.first)?(true):(p1.second<p2.second)?(true):(false);
// }

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int sum=0;
            while(n>0){
                sum=sum+n%10;
                n=n/10;
            }
            v.push_back({sum,nums[i]});
        }
        sort(v.begin(),v.end());
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i].second]=i;
        }
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(mp[nums[i]]!=i){
                swap(nums[i],nums[mp[nums[i]]]);
                count++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};