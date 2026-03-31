class Solution {
    public int maxProfit(int[] arr, int k) {
        int hold = -arr[0];
        int cash = 0;

        for(int i = 1; i < arr.length; i++) {
            hold = Math.max(hold, cash - arr[i]);
            cash = Math.max(cash, hold + arr[i] - k);
        }

        return cash;
    }
}
