class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.size();i++){
            if(mp.find(order[i])!=mp.end()){
                for(int j=0;j<mp[order[i]];j++){
                    ans.push_back(order[i]);
                }
                mp.erase(order[i]);
            }
        }
        for(auto p:mp){
            for(int j=0;j<p.second;j++){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};