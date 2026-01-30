class Solution {
    public static void rearrangeQueue(Queue<Integer> q) {
        int n = q.size();
        int half = n / 2;

        Queue<Integer> firstHalf = new LinkedList<>();

        // Step 1
        for (int i = 0; i < half; i++) {
            firstHalf.add(q.poll());
        }

        // Step 2
        while (!firstHalf.isEmpty()) {
            q.add(firstHalf.poll());
            q.add(q.poll());
        }
    }
}
