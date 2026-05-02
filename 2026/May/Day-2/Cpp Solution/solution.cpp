class Solution {
  public:
    int findPosition(int n) {
        // Check if exactly one set bit exists
        if (n <= 0 || (n & (n - 1)) != 0)
            return -1;

        int pos = 1;
        while (n > 1) {
            n = n >> 1;
            pos++;
        }
        return pos;
    }
};
