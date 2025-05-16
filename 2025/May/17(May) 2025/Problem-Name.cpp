class Solution {
public:
    int apply(int x, int A, int B, int C) {
        return A * x * x + B * x + C;
    }

    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int index = (A >= 0) ? n - 1 : 0;

        while (left <= right) {
            int valLeft = apply(arr[left], A, B, C);
            int valRight = apply(arr[right], A, B, C);

            if (A >= 0) {
                if (valLeft > valRight) {
                    result[index--] = valLeft;
                    left++;
                } else {
                    result[index--] = valRight;
                    right--;
                }
            } else {
                if (valLeft < valRight) {
                    result[index++] = valLeft;
                    left++;
                } else {
                    result[index++] = valRight;
                    right--;
                }
            }
        }
        return result;
    }
};
