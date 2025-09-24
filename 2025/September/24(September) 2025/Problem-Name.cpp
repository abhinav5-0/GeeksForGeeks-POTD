#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
    queue<int> q;
    deque<int> minDeque, maxDeque; // For tracking min and max

public:
    // Insert element into the queue
    void enqueue(int x) {
        q.push(x);

        // Maintain minDeque (increasing order)
        while (!minDeque.empty() && minDeque.back() > x)
            minDeque.pop_back();
        minDeque.push_back(x);

        // Maintain maxDeque (decreasing order)
        while (!maxDeque.empty() && maxDeque.back() < x)
            maxDeque.pop_back();
        maxDeque.push_back(x);
    }

    // Remove element from the queue
    void dequeue() {
        if (q.empty()) return;

        int front = q.front();
        q.pop();

        // Sync with minDeque
        if (!minDeque.empty() && minDeque.front() == front)
            minDeque.pop_front();

        // Sync with maxDeque
        if (!maxDeque.empty() && maxDeque.front() == front)
            maxDeque.pop_front();
    }

    // Get front element
    int getFront() {
        return q.front();
    }

    // Get minimum element
    int getMin() {
        return minDeque.front();
    }

    // Get maximum element
    int getMax() {
        return maxDeque.front();
    }
};
