class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<char,int>mp;
        map<string,int>str;
        int i=0;
        int j=0;
        while(j<s.length()){
            mp[s[j]]++;
            while(mp['1']>=k){
                string t=s.substr(i,j-i+1);
                str[t]=t.length();
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        int len=INT_MAX;
        for(auto p:str){
            len=min(len,p.second);
        }
        for(auto p:str){
            if(p.second==len){
                return p.first;
            }
        }
        return "";
    }
};