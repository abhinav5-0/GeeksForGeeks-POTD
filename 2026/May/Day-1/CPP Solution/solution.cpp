class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> result;
        
        for(int x : arr) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
            
            if(pq.size() < k)
                result.push_back(-1);
            else
                result.push_back(pq.top());
        }
        
        return result;
    }
};
