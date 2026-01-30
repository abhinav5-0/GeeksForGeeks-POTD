class Solution {
public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        int half = n / 2;

        queue<int> firstHalf;

        // Step 1: store first half
        for (int i = 0; i < half; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Step 2: interleave
        while (!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
