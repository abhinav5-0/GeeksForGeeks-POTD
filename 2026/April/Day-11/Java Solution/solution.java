class Solution {
    public int countIncreasing(int[] arr) {
        long count = 0;
        long len = 1;

        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > arr[i - 1]) {
                len++;
            } else {
                count += (len * (len - 1)) / 2;
                len = 1;
            }
        }

        count += (len * (len - 1)) / 2;
        return (int)count;
    }
}
