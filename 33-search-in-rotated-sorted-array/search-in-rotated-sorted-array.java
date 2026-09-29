class Solution {
    int peek(int []nums){
        int i=0;
        int j=nums.length-1;
        while(i<j){
            int mid=(i+j)/2;
            if(mid-1>=0 && mid+1<nums.length && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid-1>=0 && mid+1<nums.length && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1] && nums[mid]>nums[nums.length-1]){
                i=mid;
            }
            else if(mid-1>=0 && mid+1<nums.length && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                j=mid;
            } 
            else if(mid-1>=0 && mid+1<nums.length && nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                return mid-1;
            }
            else if(mid-1<0){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return 0; 
    }
    int search(int []nums,int start,int end,int target){
        int i=start;
        int j=end;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return -1;
    }
    public int search(int[] nums, int target) {
        int indx=peek(nums);
        return Math.max(search(nums,0,indx,target),search(nums,indx+1,nums.length-1,target));
    }
}