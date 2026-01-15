class Solution {
    public int minCandy(int[] arr) {
        int n = arr.length;
        int[] candy = new int[n];

        // Step 1: every child gets 1
        Arrays.fill(candy, 1);

        // Step 2: Left to Right
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // Step 3: Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candy[i] = Math.max(candy[i], candy[i + 1] + 1);
            }
        }

        // Step 4: Sum
        int total = 0;
        for (int c : candy) total += c;

        return total;
    }
}
