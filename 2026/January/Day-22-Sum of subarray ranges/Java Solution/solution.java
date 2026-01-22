class Solution {
    public int subarrayRanges(int[] arr) {
        int n = arr.length;
        int[] pge = new int[n], nge = new int[n];
        int[] pse = new int[n], nse = new int[n];
        Stack<Integer> st = new Stack<>();

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] <= arr[i]) st.pop();
            pge[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }
        st.clear();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peek()] < arr[i]) st.pop();
            nge[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }
        st.clear();

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] >= arr[i]) st.pop();
            pse[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }
        st.clear();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peek()] > arr[i]) st.pop();
            nse[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }

        long maxSum = 0, minSum = 0;

        for (int i = 0; i < n; i++) {
            long maxCnt = (long)(i - pge[i]) * (nge[i] - i);
            long minCnt = (long)(i - pse[i]) * (nse[i] - i);
            maxSum += arr[i] * maxCnt;
            minSum += arr[i] * minCnt;
        }

        return (int)(maxSum - minSum);
    }
}
