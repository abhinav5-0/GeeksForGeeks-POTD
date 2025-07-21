### Problem: Count the Coprimes

**Difficulty:** Hard  
**Accuracy:** 40.52%  
**Submissions:** 8K+  
**Points:** 8

---

### Problem Statement:

You are given an array `arr[]` of positive integers. Your task is to count the number of **unordered** pairs `(i, j)` such that:
- `0 ≤ i < j ≤ n - 1`
- `gcd(arr[i], arr[j]) = 1`

In other words, count how many unordered pairs of indices `(i, j)` point to co-prime numbers.

---

### Examples:

**Input:** `arr[] = [1, 2, 3]`  
**Output:** `3`  
**Explanation:** Pairs (0,1), (0,2), (1,2) are co-prime.

**Input:** `arr[] = [4, 8, 3, 9]`  
**Output:** `4`  
**Explanation:** Pairs (0,2), (0,3), (1,2), (1,3) are co-prime.

---

### Constraints:
- `2 ≤ arr.size() ≤ 10^4`
- `1 ≤ arr[i] ≤ 10^4`

---

### Optimal C++ Solution (Using Sieve + Möbius Function):

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        const int MAX = 10001;
        vector<int> freq(MAX, 0);

        for (int num : arr) {
            freq[num]++;
        }

        // Count number of elements divisible by i
        vector<int> count_divisible(MAX, 0);
        for (int i = 1; i < MAX; ++i) {
            for (int j = i; j < MAX; j += i) {
                count_divisible[i] += freq[j];
            }
        }

        // Möbius function
        vector<int> mu(MAX, 1);
        vector<bool> is_prime(MAX, true);
        for (int i = 2; i < MAX; ++i) {
            if (is_prime[i]) {
                for (int j = i; j < MAX; j += i) {
                    mu[j] *= -1;
                    is_prime[j] = false;
                }
                for (int j = i * i; j < MAX; j += i * i) {
                    mu[j] = 0;
                }
            }
        }

        // Inclusion-Exclusion using Möbius function
        long long coprime_pairs = 0;
        for (int i = 1; i < MAX; ++i) {
            long long c = count_divisible[i];
            if (c >= 2) {
                coprime_pairs += mu[i] * (c * (c - 1) / 2);
            }
        }

        return (int)coprime_pairs;
    }
};
```

---

### Time Complexity:
- **O(N log N)** — Efficient for `n ≤ 10^4`

---

### Usage Example:

```cpp
int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 3};
    cout << sol.cntCoprime(arr1) << endl;  // Output: 3

    vector<int> arr2 = {4, 8, 3, 9};
    cout << sol.cntCoprime(arr2) << endl;  // Output: 4

    return 0;
}
```

---

### Notes:
- Brute-force solution would be O(n^2) and not pass for large input sizes.
- The use of Möbius function and inclusion-exclusion principle helps count co-prime pairs efficiently.
