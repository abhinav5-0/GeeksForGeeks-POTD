class Solution {
public:
    int countWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;

        long long same = k;               // last two same
        long long diff = k * (k - 1);     // last two different

        for (int i = 3; i <= n; i++) {
            long long newSame = diff;
            long long newDiff = (same + diff) * (k - 1);

            same = newSame;
            diff = newDiff;
        }

        return same + diff;
    }
};
