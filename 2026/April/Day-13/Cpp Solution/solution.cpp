class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        
        // Step 1: check all 9s
        bool all9 = true;
        for (int d : num) {
            if (d != 9) {
                all9 = false;
                break;
            }
        }
        
        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = res[n] = 1;
            return res;
        }
        
        vector<int> res = num;
        
        // Step 2: mirror left to right
        int i = 0, j = n - 1;
        while (i < j) {
            res[j] = res[i];
            i++; j--;
        }
        
        // Step 3: check if result > original
        if (res > num) return res;
        
        // Step 4: increment middle
        int carry = 1;
        int mid = n / 2;
        
        if (n % 2 == 1) {
            res[mid] += carry;
            carry = res[mid] / 10;
            res[mid] %= 10;
            i = mid - 1;
            j = mid + 1;
        } else {
            i = mid - 1;
            j = mid;
        }
        
        // Step 5: propagate carry
        while (i >= 0 && carry) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
            res[j] = res[i];
            i--; j++;
        }
        
        return res;
    }
};
