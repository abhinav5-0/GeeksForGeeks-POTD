class Solution {
public:
    int lcmTriplets(int n) {
        return n < 3 ? n : n & 1 ? n * (n - 1) * (n - 2) : 
              n % 3 ? n * (n - 1) * (n - 3) : (n - 1) * (n - 2) * (n - 3);
    }
};
