class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<List<Integer>>arr=new ArrayList<>();
        for(int i=0;i<intervals.length;i++){
            ArrayList<Integer>temp=new ArrayList<>();
            for(int j=0;j<intervals[i].length;j++){
                temp.add(intervals[i][j]);
            }
            arr.add(temp);
        }
        ArrayList<Integer>temp=new ArrayList<>();
        temp.add(newInterval[0]);
        temp.add(newInterval[1]);
        arr.add(temp);
        List<List<Integer>>res=new ArrayList<>();
        Collections.sort(arr,(a,b)->Integer.compare(a.get(0),b.get(0)));
        res.add(arr.get(0));
        for(int i=1;i<arr.size();i++){
            if(res.get(res.size()-1).get(1)>=arr.get(i).get(0)){
                res.get(res.size()-1).set(1,Math.max(res.get(res.size()-1).get(1),arr.get(i).get(1)));
            }
            else{
                res.add(arr.get(i));
            }
        }
        int [][] ans=new int[res.size()][2];
        for(int i=0;i<res.size();i++){
            ans[i][0]=res.get(i).get(0);
            ans[i][1]=res.get(i).get(1);
        }
        return ans;
    }
}