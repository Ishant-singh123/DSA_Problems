class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int count=0;
        HashMap<Integer,Integer>mp=new HashMap<>();

        mp.put(0,1);
        for(int i=1;i<nums.length;i++){
            nums[i]=nums[i-1]+nums[i];
        }

        for(int i=0;i<nums.length;i++){
            int val;
            if(nums[i]<0){
                val=(nums[i]%k+k)%k;
            }
            else{
                val=nums[i]%k;
            }
            if(mp.containsKey(val)){
                count=count+mp.get(val);
            }
            mp.put(val,mp.getOrDefault(val,0)+1);
        }
        return count;
    }
}