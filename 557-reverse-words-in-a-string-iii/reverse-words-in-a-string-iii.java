class Solution {
    public String reverseWords(String s) {
        StringBuffer ans=new StringBuffer();
        StringBuffer temp=new StringBuffer();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' '){
                temp.reverse();
                ans.append(temp);
                ans.append(' ');
                temp.setLength(0);
            }
            else{
                temp.append(s.charAt(i));
            }
        }
        temp.reverse();
        ans.append(temp);
        return ans.toString();
    }
}