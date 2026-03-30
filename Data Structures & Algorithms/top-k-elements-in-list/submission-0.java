


class Pair{
    int x;
    int y;
    Pair(int key, int value){
        this.x = key;
        this.y = value;
    } 
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> count = new HashMap<>();
        PriorityQueue<Pair>freq = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.y, a.y)
            );

        for(int i=0; i<nums.length; i++){
            if(count.containsKey(nums[i])){
                count.put(nums[i], count.get(nums[i]) + 1);
            }else{
                count.put(nums[i], 1);
            }
        }

        count.forEach((key, value)->{
            freq.add(new Pair(key, value));
        });

        int[] res = new int[k];

        for(int i=0;i<k;i++){
            res[i]= freq.poll().x;
        }

        return res;

    }
}
