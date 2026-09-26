class Solution {
    public void moveZeroes(int[] nums) {
        ArrayList<Integer>list=new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                list.add(nums[i]);
            }
        }
        int i=0;
        for(i=0;i<list.size();i++){
            nums[i]=list.get(i);
        }
        while(i<nums.length){
            nums[i]=0;
            i++;
        }
    }
}