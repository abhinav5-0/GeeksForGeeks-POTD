import java.util.*;

class Solution {
    public ArrayList<Integer> kthLargest(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        ArrayList<Integer> result = new ArrayList<>();

        for(int x : arr) {
            pq.offer(x);

            if(pq.size() > k)
                pq.poll();

            if(pq.size() < k)
                result.add(-1);
            else
                result.add(pq.peek());
        }

        return result;
    }
}
