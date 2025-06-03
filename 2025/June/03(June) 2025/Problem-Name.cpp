#include <unordered_map>
using namespace std;

class Solution {
public:
    int countSubstr(string& s, int k) {
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }

private:
    int atMostKDistinct(const string& s, int k) {
        if (k == 0) return 0;

        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                ++left;
            }

            count += (right - left + 1);  // Count all substrings ending at right
        }

        return count;
    }
};
