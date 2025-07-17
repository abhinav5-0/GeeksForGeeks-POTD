class Solution {
public:
    // Helper function to get the exponent of a prime in n!
    int countFactorInFactorial(int n, int p) {
        int count = 0;
        while (n > 0) {
            n /= p;
            count += n;
        }
        return count;
    }

    int maxKPower(int n, int k) {
        // Step 1: Prime factorization of k
        unordered_map<int, int> primeFactors;
        for (int i = 2; i * i <= k; ++i) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            primeFactors[k]++;
        }

        // Step 2: Use Legendre’s formula for each prime
        int result = INT_MAX;
        for (auto [prime, powerInK] : primeFactors) {
            int countInFactorial = countFactorInFactorial(n, prime);
            result = min(result, countInFactorial / powerInK);
        }
        return result;
    }
};
