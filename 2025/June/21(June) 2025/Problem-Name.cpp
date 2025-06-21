class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        queue<int> police, thieves;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.push(i);
            } else if (arr[i] == 'T') {
                thieves.push(i);
            }

            // While we have both policeman and thief
            while (!police.empty() && !thieves.empty()) {
                int pol = police.front();
                int thi = thieves.front();

                if (abs(pol - thi) <= k) {
                    // Catch thief
                    count++;
                    police.pop();
                    thieves.pop();
                } else if (thi < pol) {
                    // Thief too far behind, discard thief
                    thieves.pop();
                } else {
                    // Policeman too far behind, discard policeman
                    police.pop();
                }
            }
        }
        return count;
    }
};
