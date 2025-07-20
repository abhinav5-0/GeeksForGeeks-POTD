class Solution {
public:
    int countValid(int n, std::vector<int>& arr) {
        // Step 1 & 2: Mark digits present in arr
        std::set<int> arr_digits_set;
        for (int digit : arr) {
            arr_digits_set.insert(digit);
        }

        // Step 3 & 4: Calculate k and k_non_zero
        long long k = 0;           // Count of digits NOT in arr
        long long k_non_zero = 0;  // Count of non-zero digits NOT in arr

        for (int i = 0; i <= 9; ++i) {
            if (arr_digits_set.find(i) == arr_digits_set.end()) { // If digit i is NOT in arr
                k++;
                if (i != 0) {
                    k_non_zero++;
                }
            }
        }

        // Step 5: Calculate total n-digit numbers
        // For n=1, 9 * 10^0 = 9
        // For n>1, 9 * 10^(n-1)
        long long total_n_digit_numbers;
        if (n == 1) {
            total_n_digit_numbers = 9;
        } else {
            total_n_digit_numbers = 9 * static_cast<long long>(std::pow(10, n - 1));
        }

        // Step 6: Calculate numbers without arr digits
        long long numbers_without_arr_digits;
        if (k == 0) { // If all digits 0-9 are in arr, then no number can be formed without arr digits
            numbers_without_arr_digits = 0;
        } else {
            // If n=1, first digit cannot be 0, so it's k_non_zero choices
            // If n>1, first digit k_non_zero choices, subsequent (n-1) digits k choices
            if (n == 1) {
                numbers_without_arr_digits = k_non_zero;
            } else {
                numbers_without_arr_digits = k_non_zero * static_cast<long long>(std::pow(k, n - 1));
            }
        }
        
        // Step 7: Result
        return static_cast<int>(total_n_digit_numbers - numbers_without_arr_digits);
    }
};
