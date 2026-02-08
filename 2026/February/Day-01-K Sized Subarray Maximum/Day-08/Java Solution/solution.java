class Solution {
    public int maxProduct(int[] arr) {
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < 0) {
                int temp = maxEndingHere;
                maxEndingHere = minEndingHere;
                minEndingHere = temp;
            }

            maxEndingHere = Math.max(arr[i], maxEndingHere * arr[i]);
            minEndingHere = Math.min(arr[i], minEndingHere * arr[i]);

            ans = Math.max(ans, maxEndingHere);
        }
        return ans;
    }
}
