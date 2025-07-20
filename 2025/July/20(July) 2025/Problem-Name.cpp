class Solution {
public:
    bool containsDigitFromArr(int num, unordered_set<int>& digitSet) {
        while (num > 0) {
            if (digitSet.count(num % 10)) return true;
            num /= 10;
        }
        return false;
    }

    int countValid(int n, vector<int>& arr) {
        unordered_set<int> digitSet(arr.begin(), arr.end());
        int start = (n == 1) ? 1 : pow(10, n - 1);
        int end = pow(10, n) - 1;
        int count = 0;

        for (int num = start; num <= end; ++num) {
            if (containsDigitFromArr(num, digitSet)) {
                count++;
            }
        }
        return count;
    }
};
