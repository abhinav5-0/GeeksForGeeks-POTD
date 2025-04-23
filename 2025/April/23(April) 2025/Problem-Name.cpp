class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xorAll = 0;
        for (int num : arr) {
            xorAll ^= num;
        }

        // Find rightmost set bit (differs in the two unique numbers)
        int rightmostSetBit = xorAll & -xorAll;

        int num1 = 0, num2 = 0;
        for (int num : arr) {
            if (num & rightmostSetBit)
                num1 ^= num;
            else
                num2 ^= num;
        }

        if (num1 > num2)
            swap(num1, num2);
        return {num1, num2};
    }
};
