class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0, j = 0;
        int n1 = s1.size(), n2 = s2.size();

        while (i < n1 && j < n2) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }

        return (i == n1); // true if all characters of s1 are matched
    }
};
