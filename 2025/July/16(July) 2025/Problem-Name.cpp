class Solution {
public:
    int countNumbers(int n) {
        int limit = sqrt(n) + 1;
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        // Sieve of Eratosthenes
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= limit; j += i)
                    isPrime[j] = false;
            }
        }

        int count = 0;

        // Case 1: p^8
        for (int p : primes) {
            long long val = 1;
            for (int i = 0; i < 8; ++i)
                val *= p;
            if (val <= n) count++;
            else break;  // as p increases, p^8 increases rapidly
        }

        // Case 2: p1^2 * p2^2 = (p1 * p2)^2
        int sz = primes.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (val <= n) count++;
                else break; // no point in checking larger j
            }
        }

        return count;
    }
};
