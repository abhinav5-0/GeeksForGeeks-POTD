class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>>& men, vector<vector<int>>& women) {
        int n = men.size();

        vector<int> womanPartner(n, -1);
        vector<int> manNext(n, 0);
        vector<bool> freeMan(n, true);

        vector<vector<int>> rank(n, vector<int>(n));

        // Ranking of men for each woman
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        int freeCount = n;

        while (freeCount > 0) {
            int m;
            for (m = 0; m < n; m++)
                if (freeMan[m]) break;

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

        vector<int> result(n);
        for (int w = 0; w < n; w++) {
            result[womanPartner[w]] = w;
        }

        return result;
    }
};
