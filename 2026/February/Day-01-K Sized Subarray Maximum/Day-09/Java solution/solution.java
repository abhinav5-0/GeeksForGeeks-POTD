class Solution {
    int findKRotation(int arr[]) {
        int n = arr.length;
        int minIndex = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }
}
