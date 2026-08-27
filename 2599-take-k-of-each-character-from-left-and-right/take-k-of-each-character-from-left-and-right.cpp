class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int i=0;
        int j=0;
        int len=0;
        if(mp['a']<k || mp['b']<k || mp['c']<k){
            return -1;
        }
        while(j<s.length()){
            mp[s[j]]--;
            while(mp[s[j]]<k){
                mp[s[i]]++;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return s.length()-len;
    }
};