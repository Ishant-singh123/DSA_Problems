class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int anotherNum=target-nums[i];
            if(m.find(anotherNum)!=m.end()){
                v.push_back(m[anotherNum]);
                v.push_back(i);
                break;
            }
            else{
                m[nums[i]]=i;
            }
        }
        return v;
    }
};