class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        vector<int> result;
        int m = pat.size();
        int n = txt.size();
        
        if (m > n) return result;

        int d = 26; // Number of characters in alphabet
        int q = 101; // A prime number for modulus (can use larger to reduce collisions)
        int h = 1;

        // Precompute h = pow(d, m-1) % q
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }

        int p = 0; // Hash value for pattern
        int t = 0; // Hash value for text window

        // Calculate hash value of pattern and first window
        for (int i = 0; i < m; i++) {
            p = (d * p + (pat[i] - 'a')) % q;
            t = (d * t + (txt[i] - 'a')) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check hash values
            if (p == t) {
                // Check characters one by one
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) result.push_back(i + 1); // 1-based index
            }

            // Calculate hash for next window
            if (i < n - m) {
                t = (d * (t - (txt[i] - 'a') * h) + (txt[i + m] - 'a')) % q;
                if (t < 0) t += q;
            }
        }

        return result;
    }
};
