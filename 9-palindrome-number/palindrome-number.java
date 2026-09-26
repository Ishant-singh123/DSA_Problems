class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        ArrayList<Integer>arr=new ArrayList<>();
        while(x>0){
            arr.add(x%10);
            x=x/10;
        }
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            if(arr.get(i)!=arr.get(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
}