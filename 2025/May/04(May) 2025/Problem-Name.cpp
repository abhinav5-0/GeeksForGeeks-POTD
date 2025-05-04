//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        unordered_set<char> unique_chars(str.begin(), str.end());
        int distinct_char_count = unique_chars.size();
        
        unordered_map<char, int> window_count;
        int min_len = INT_MAX;
        int start = 0, count = 0;
        
        for (int end = 0; end < str.size(); end++) {
            window_count[str[end]]++;
            
            if (window_count[str[end]] == 1) {
                count++;
            }
            
            // Try to shrink the window from the left
            while (count == distinct_char_count) {
                min_len = min(min_len, end - start + 1);
                
                window_count[str[start]]--;
                if (window_count[str[start]] == 0) {
                    count--;
                }
                start++;
            }
        }
        return min_len;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
