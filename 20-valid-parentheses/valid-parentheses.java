class Solution {
    public boolean isValid(String s) {
        Stack<Character>st=new Stack<>();
        char []str=s.toCharArray();
        for(int i=0;i<str.length;i++){
            if(str[i]=='('){
                st.push(str[i]);
            }
            else if(str[i]=='{'){
                st.push(str[i]);
            }
            else if(str[i]=='['){
                st.push(str[i]);
            }
            else if(st.size()>0 && str[i]==')' && st.peek()=='('){
                st.pop();
            }
            else if(st.size()>0 && str[i]=='}' && st.peek()=='{'){
                st.pop();
            }
            else if(st.size()>0 && str[i]==']' && st.peek()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.size()>0){
            return false;
        }
        return true;
    }
}