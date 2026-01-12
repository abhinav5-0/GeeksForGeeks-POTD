class Solution {
public:
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
vector<int> result;
deque<int> dq;


for (int i = 0; i < arr.size(); i++) {
// Remove elements out of window
if (!dq.empty() && dq.front() <= i - k) {
dq.pop_front();
}


// Remove smaller elements
while (!dq.empty() && arr[dq.back()] <= arr[i]) {
dq.pop_back();
}


dq.push_back(i);


// Store maximum of window
if (i >= k - 1) {
result.push_back(arr[dq.front()]);
}
}


return result;
}
};
