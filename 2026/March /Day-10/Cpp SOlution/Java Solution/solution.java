import java.util.*;

class Solution {
    public int countSubarrays(int[] arr) {
        int n = arr.length;
        Stack<Integer> stack = new Stack<>();
        int[] nextSmaller = new int[n];

        Arrays.fill(nextSmaller, n);

        for(int i = n - 1; i >= 0; i--) {
            while(!stack.isEmpty() && arr[stack.peek()] >= arr[i])
                stack.pop();

            if(!stack.isEmpty())
                nextSmaller[i] = stack.peek();

            stack.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += nextSmaller[i] - i;

        return ans;
    }
}
