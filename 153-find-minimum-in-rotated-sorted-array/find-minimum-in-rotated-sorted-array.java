class Solution {
    int peek(int []nums){
        int i=0;
        int j=nums.length-1;

        while(i<=j){
            int mid=(i+j)/2;
            if(mid-1>=0 && mid+1<nums.length && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid-1>=0 && mid+1<nums.length && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1] && nums[mid]>nums[nums.length-1]){
                i=mid+1;
            }
            else if(mid-1>=0 && mid+1<nums.length && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                j=mid-1;
            }
            else if(mid==0 && nums[mid]<nums[mid+1]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return -1;
    }
    public int findMin(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        if(peek(nums)==-1){
            if(nums[0]>nums[nums.length-1]){
                return nums[1];
            }
            else{
                return nums[0];
            }
        }
        return nums[peek(nums)+1];
    }
}