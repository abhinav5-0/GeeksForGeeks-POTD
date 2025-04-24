class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;

        // Iterate over every bit position
        for (int i = 0; i < 32; ++i) {
            int bitCount = 0;

            for (int num : arr) {
                if ((num >> i) & 1) {
                    bitCount++;
                }
            }

            // If bitCount % 3 is not zero, this bit is part of the unique number
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};
v
