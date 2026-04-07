import java.util.*;

class Solution {
    public int[] stableMarriage(int[][] men, int[][] women) {
        int n = men.length;

        int[] womanPartner = new int[n];
        int[] manNext = new int[n];
        boolean[] freeMan = new boolean[n];

        Arrays.fill(womanPartner, -1);
        Arrays.fill(freeMan, true);

        int[][] rank = new int[n][n];

        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        int freeCount = n;

        while (freeCount > 0) {
            int m = 0;
            while (!freeMan[m]) m++;

            int w = men[m][manNext[m]++];

            if (womanPartner[w] == -1) {
                womanPartner[w] = m;
                freeMan[m] = false;
                freeCount--;
            } else {
                int m1 = womanPartner[w];

                if (rank[w][m] < rank[w][m1]) {
                    womanPartner[w] = m;
                    freeMan[m] = false;
                    freeMan[m1] = true;
                }
            }
        }

        int[] result = new int[n];
        for (int w = 0; w < n; w++) {
            result[womanPartner[w]] = w;
        }

        return result;
    }
}
