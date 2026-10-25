bool cmp(pair<int,char>p1,pair<int,char>p2){
    return p1.first>p2.first;
}
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>>order;
        for(auto p:mp){
            order.push_back({p.second,p.first});
        }
        sort(order.begin(),order.end(),cmp);

        string ans="";
        for(int i=0;i<order.size();i++){
            for(int j=0;j<mp[order[i].second];j++){
                ans.push_back(order[i].second);
            }
        }
        return ans;
    }
};