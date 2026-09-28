class Solution {
    public List<Integer> majorityElement(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        ArrayList<Integer>arr=new ArrayList<>();
        for(Integer key : mp.keySet()){
            if(3*(mp.get(key))>nums.length){
                arr.add(key);
            }
        }
        return arr;
    }
}