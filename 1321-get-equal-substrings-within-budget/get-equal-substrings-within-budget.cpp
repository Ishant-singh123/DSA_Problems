class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=0;
        int i=0;
        int j=0;
        int cost=0;
        while(j<s.length()){
            cost=cost+abs(s[j]-t[j]);
            while(cost>maxCost){
                cost=cost-abs(s[i]-t[i]);
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};