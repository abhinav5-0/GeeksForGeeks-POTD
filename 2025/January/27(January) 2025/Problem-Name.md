# LRU Cache Implementation

This repository contains the implementation of an **LRU (Least Recently Used) Cache** using C++. The cache supports the following operations in O(1) time:

- **GET**: Retrieve the value associated with a key.
- **PUT**: Insert or update a key-value pair in the cache. If the cache is full, the least recently used item is removed.

## Problem Statement
Design a data structure that simulates the behavior of an LRU Cache with the following features:

1. `GET(key)`:
   - Returns the value of the key if it exists in the cache.
   - Returns `-1` if the key is not present in the cache.

2. `PUT(key, value)`:
   - Adds or updates the key-value pair in the cache.
   - If the cache exceeds its capacity, removes the least recently used item.

The cache is initialized with a fixed capacity.

## Code Overview
The solution uses the following data structures:

1. **Doubly Linked List**:
   - To maintain the order of usage.
   - The most recently used item is at the front.
   - The least recently used item is at the back.

2. **Hash Map**:
   - For O(1) access to the key-value pairs.
   - Maps each key to its corresponding node in the doubly linked list.

### Class: `LRUCache`

#### Methods:

- **`LRUCache(int capacity)`**:
  Constructor to initialize the cache with the given capacity.

- **`int get(int key)`**:
  Returns the value of the key if present, otherwise `-1`.

- **`void put(int key, int value)`**:
  Inserts or updates the key-value pair. Removes the least recently used item if the cache is full.

### Example Usage

#### Input
```plaintext
cap = 2, Q = 8
Queries = [
    ["PUT", 1, 2],
    ["PUT", 2, 3],
    ["PUT", 1, 5],
    ["PUT", 4, 5],
    ["PUT", 6, 7],
    ["GET", 4],
    ["PUT", 1, 2],
    ["GET", 3]
]
```

#### Output
```plaintext
5 -1
```

#### Explanation
1. `PUT 1 2`: Inserts (1, 2).
2. `PUT 2 3`: Inserts (2, 3). Cache: `{1->2, 2->3}`
3. `PUT 1 5`: Updates key 1 to (1, 5). Cache: `{2->3, 1->5}`
4. `PUT 4 5`: Inserts (4, 5), removes least recently used (2, 3). Cache: `{1->5, 4->5}`
5. `PUT 6 7`: Inserts (6, 7), removes least recently used (1, 5). Cache: `{4->5, 6->7}`
6. `GET 4`: Returns `5`. Cache: `{6->7, 4->5}`
7. `PUT 1 2`: Inserts (1, 2), removes least recently used (6, 7). Cache: `{4->5, 1->2}`
8. `GET 3`: Returns `-1` (not found).


## Constraints

- `1 <= cap <= 10^3`
- `1 <= Q <= 10^5`
- `1 <= x, y <= 10^4`


