class Solution {
    public int subarraySum(int[] nums, int k) {
        int []prefix=new int[nums.length];
        prefix[0]=nums[0];
        for(int i=1;i<prefix.length;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        HashMap<Integer,Integer>mp=new HashMap<>();
        mp.put(0,1);
        int count=0;
        for(int i=0;i<prefix.length;i++){
            if(mp.containsKey(prefix[i]-k)){
                count=count+mp.get(prefix[i]-k);
            }
            mp.put(prefix[i],mp.getOrDefault(prefix[i],0)+1);
        }
        return count;
    }
}