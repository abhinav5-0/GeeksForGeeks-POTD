class Solution {
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int pour(int from, int to, int d) {
        int fromJug = from;
        int toJug = 0;
        int steps = 1;

        while (fromJug != d && toJug != d) {
            int temp = Math.min(fromJug, to - toJug);

            toJug += temp;
            fromJug -= temp;
            steps++;

            if (fromJug == d || toJug == d)
                break;

            if (fromJug == 0) {
                fromJug = from;
                steps++;
            }

            if (toJug == to) {
                toJug = 0;
                steps++;
            }
        }
        return steps;
    }

    public int minSteps(int m, int n, int d) {
        if (d > Math.max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;

        return Math.min(pour(m, n, d), pour(n, m, d));
    }
}
