class Solution {
    public int[] productExceptSelf(int[] nums) {
        int []prefix=new int[nums.length];
        int []suffix=new int[nums.length];
        prefix[0]=1;
        // prefix[prefix.length-1]=1;
        for(int i=0;i<nums.length-1;i++){
            prefix[i+1]=prefix[i]*nums[i];
        }
        suffix[suffix.length-1]=1;
        for(int i=nums.length-1;i>0;i--){
            suffix[i-1]=suffix[i]*nums[i];
        }
        int []ans=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
}