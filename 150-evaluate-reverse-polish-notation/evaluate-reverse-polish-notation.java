class Solution {
    int operation(int a,int b,char c){
        if(c=='+'){
            return a+b;
        }
        if(c=='-'){
            return a-b;
        }
        if(c=='*'){
            return a*b;
        }
        return a/b;
    }
    public int evalRPN(String[] tokens) {
        Stack<Integer>st=new Stack<>();
        int ans=0;
        for(int i=0;i<tokens.length;i++){
            if(tokens[i].equals("-") || tokens[i].equals("+") || tokens[i].equals("*") || tokens[i].equals("/")){
                int b=st.peek();
                st.pop();
                int a=st.peek();
                st.pop();
                st.push(operation(a,b,tokens[i].charAt(0)));
            }
            else{
                Integer x=Integer.valueOf(tokens[i]);
                st.push(x);
            }
        }
        return st.peek();
    }
}