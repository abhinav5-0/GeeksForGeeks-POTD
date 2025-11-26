class Solution {
  public:
    int andInRange(int l, int r) {
        int shift = 0;
        
        // Keep shifting until both are equal
        while(l != r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }
        
        // Shift back to restore the common prefix
        return l << shift;
    }
};
