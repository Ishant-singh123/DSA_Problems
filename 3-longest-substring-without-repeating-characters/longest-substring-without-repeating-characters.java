class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer>mp=new HashMap<>();
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<s.length()){
            mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)+1);
            while(mp.get(s.charAt(j))>1){
                mp.put(s.charAt(i),mp.get(s.charAt(i))-1);
                i++;
            }
            maxlen=Math.max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
}