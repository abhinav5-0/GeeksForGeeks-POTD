# Get Min from Stack

## Problem Statement
Given `q` queries, implement a stack with the following operations:

1. `push(x)`: Insert an integer `x` onto the stack.
2. `pop()`: Remove the top element from the stack.
3. `peek()`: Return the top element from the stack. If the stack is empty, return `-1`.
4. `getMin()`: Retrieve the minimum element from the stack in `O(1)` time. If the stack is empty, return `-1`.

### Query Types
Each query follows one of these formats:
- `1 x` : Push `x` onto the stack.
- `2` : Pop the top element from the stack.
- `3` : Return the top element from the stack.
- `4` : Return the minimum element from the stack.

## Examples

### Example 1
**Input:**
```
q = 7
queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
```
**Output:**
```
[3, 2, 1]
```
**Explanation:**
- `push(2)`: Stack is `[2]`
- `push(3)`: Stack is `[2, 3]`
- `peek()`: Top element is `3`
- `pop()`: Removes `3`, stack is `[2]`
- `getMin()`: Minimum element is `2`
- `push(1)`: Stack is `[2, 1]`
- `getMin()`: Minimum element is `1`

### Example 2
**Input:**
```
q = 4
queries = [[1, 4], [1, 2], [4], [3]]
```
**Output:**
```
[2, 2]
```
**Explanation:**
- `push(4)`: Stack is `[4]`
- `push(2)`: Stack is `[4, 2]`
- `getMin()`: Minimum element is `2`
- `peek()`: Top element is `2`

## Constraints
- `1 <= q <= 10^5`
- `0 <= values on the stack <= 10^9`

## Optimized Approach
### **Using an Auxiliary Stack**
- Maintain two stacks: `mainStack` for regular operations and `minStack` to keep track of the minimum value at each step.
- Push operation ensures that `minStack` stores the minimum value at each level.
- `getMin()` retrieves the top of `minStack` in `O(1)`.

## Implementation (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    stack<int> mainStack, minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int peek() {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;
            if (qt == 1) {
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                ob.pop();
            } else if (qt == 3) {
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
```

## Explanation of the Code
1. **Using an Auxiliary Stack (`minStack`)**:
   - Ensures `getMin()` runs in `O(1)` time.
   - Updates when an element is pushed or popped.
2. **Efficient Operations**:
   - Push, Pop, Peek: `O(1)`
   - GetMin: `O(1)`

## Edge Cases Considered
✔ Stack is empty (checking `-1` returns).  
✔ Multiple `getMin()` calls after pops.  
✔ Large values of `q`.  
✔ All elements being equal.  

🚀 **This approach ensures an efficient stack with constant time `getMin()`.**

