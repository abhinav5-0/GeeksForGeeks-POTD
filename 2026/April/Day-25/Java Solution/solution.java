class Solution {
    public int[] reducePairs(int[] arr) {
        Stack<Integer> st = new Stack<>();
        
        for (int x : arr) {
            while (!st.isEmpty() && st.peek() * x < 0) {
                if (Math.abs(st.peek()) > Math.abs(x)) {
                    x = st.pop();
                } else if (Math.abs(st.peek()) < Math.abs(x)) {
                    st.pop();
                } else {
                    st.pop();
                    x = 0;
                    break;
                }
            }
            if (x != 0) st.push(x);
        }
        
        return st.stream().mapToInt(i -> i).toArray();
    }
}
