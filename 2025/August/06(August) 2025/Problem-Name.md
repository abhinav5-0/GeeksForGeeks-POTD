# Roman Number to Integer

## Problem Statement
Given a string `s` in Roman numeral format, convert it to its integer equivalent.

### Roman Symbols and Values:
```
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
```

### Rules:
- If a smaller symbol appears before a larger symbol, subtract the smaller.
- Otherwise, add the value.

### Constraints:
- 1 ≤ value of Roman numeral ≤ 3999
- Characters in the string belong to: ['I', 'V', 'X', 'L', 'C', 'D', 'M']

## Examples
```
Input: s = "IX"
Output: 9
Explanation: IX = 10 - 1 = 9

Input: s = "XL"
Output: 40
Explanation: XL = 50 - 10 = 40

Input: s = "MCMIV"
Output: 1904
Explanation: M + CM (1000 - 100) + IV (5 - 1) = 1000 + 900 + 4 = 1904
```

## C++ Code
```cpp
class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            int curr = roman[s[i]];
            int next = (i + 1 < n) ? roman[s[i + 1]] : 0;

            if (curr < next) {
                total -= curr;
            } else {
                total += curr;
            }
        }

        return total;
    }
};
```

## Time & Space Complexity
- **Time Complexity:** O(n), where n is the length of the string
- **Space Complexity:** O(1), as the map size is constant
