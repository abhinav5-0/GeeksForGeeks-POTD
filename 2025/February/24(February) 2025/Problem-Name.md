# Stock Span Problem

## Description
The Stock Span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. The span of the stock price on a given day is defined as the maximum number of consecutive days just before the given day for which the price of the stock on the given day is less than or equal to its price on the current day.

## Example

### Input:
```
arr[] = [100, 80, 60, 70, 60, 75, 85]
```
### Output:
```
[1, 1, 1, 2, 1, 4, 6]
```

## Constraints:
- 1 ≤ arr.size() ≤ 10^5
- 1 ≤ arr[i] ≤ 10^5

## Solution Approach
The solution is implemented using a **monotonic stack** to ensure an efficient **O(N) complexity**:

1. Maintain a **stack** that stores indices of previous prices.
2. For each new price, **pop** from the stack until a greater price is found.
3. Compute the span using `(current_index - top_index_of_stack)`.
4. If the stack is empty, the current price is the highest so far, so the span is `i + 1`.

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // Stack to store indices
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return span;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

## Usage
Clone the repository and compile the C++ file using g++:
```sh
g++ -o stock_span stock_span.cpp
./stock_span
```

## License
This project is licensed under the MIT License.

