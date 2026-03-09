class Solution {
    public String largestSwap(String s) {
        int n = s.length();
        int[] last = new int[10];

        for (int i = 0; i < n; i++) {
            last[s.charAt(i) - '0'] = i;
        }

        char[] arr = s.toCharArray();

        for (int i = 0; i < n; i++) {
            for (int d = 9; d > arr[i] - '0'; d--) {
                if (last[d] > i) {
                    char temp = arr[i];
                    arr[i] = arr[last[d]];
                    arr[last[d]] = temp;
                    return new String(arr);
                }
            }
        }

        return s;
    }
}
