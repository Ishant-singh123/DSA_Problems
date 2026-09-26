class Solution {
    int solver(int n,int []arr){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(arr[n]!=-1){
            return arr[n];
        }
        return arr[n]=solver(n-1,arr)+solver(n-2,arr);
    }
    public int fib(int n) {
        int []arr=new int[31];
        for(int i=0;i<31;i++){
            arr[i]=-1;
        }
        return solver(n,arr);
    }
}