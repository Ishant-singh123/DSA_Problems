class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,ArrayList<String>>mp=new HashMap<>();
        for(int i=0;i<strs.length;i++){
            char[] c=strs[i].toCharArray();
            Arrays.sort(c);
            String sorted=new String(c);
            if(!mp.containsKey(sorted)){
                mp.put(sorted,new ArrayList<>());
            }
            mp.get(sorted).add(strs[i]);
        }
        List<List<String>>ans=new ArrayList<>();
        for(String key:mp.keySet()){
            ans.add(mp.get(key));
        }
        return ans;
    }
}