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
