# Problem: Prime List (Linked List)

## Difficulty:

Medium

## Accuracy:

53.68%

## Submissions:

33,000+

## Points:

4

## Problem Statement:

You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

## Examples:

### Input:

```
head = 2 -> 6 -> 10
```

### Output:

```
2 -> 5 -> 11
```

### Explanation:

* Nearest prime of 2 is 2 itself.
* Nearest primes of 6 are 5 and 7. Choose 5 (smaller).
* Nearest prime of 10 is 11.

### Input:

```
head = 1 -> 15 -> 20
```

### Output:

```
2 -> 13 -> 19
```

### Explanation:

* Nearest prime of 1 is 2.
* Nearest primes of 15 are 13 and 17. Choose 13 (smaller).
* Nearest prime of 20 is 19.

## Constraints:

* 1 <= no. of Nodes <= 10^4
* 1 <= node.val <= 10^4

## Approach:

1. Use the Sieve of Eratosthenes to generate all prime numbers up to 20000.
2. Store the primes in a sorted list.
3. For each node in the linked list:

   * Use binary search to find the nearest prime.
   * If two primes are equally distant, choose the smaller one.
4. Replace the node's value with the selected prime.

## Code Snippet:

```cpp
class Solution {
  public:
    int getNearestPrime(int val, const vector<int> &primes) {
        auto it = lower_bound(primes.begin(), primes.end(), val);
        if (it == primes.begin()) return *it;
        if (it == primes.end()) return primes.back();

        int upper = *it;
        int lower = *(it - 1);

        return (abs(val - lower) <= abs(upper - val)) ? lower : upper;
    }

    Node *primeList(Node *head) {
        int MAX = 20000;
        vector<bool> isPrime(MAX + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = 2; i <= MAX; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }

        Node* curr = head;
        while (curr != NULL) {
            curr->val = getNearestPrime(curr->val, primes);
            curr = curr->next;
        }

        return head;
    }
};
```

## Tags:

* Linked List
* Prime Numbers
* Binary Search
* Sieve of Eratosthenes
* Optimization
