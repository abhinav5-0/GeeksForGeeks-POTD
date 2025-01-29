class Solution {
  public:
    double power(double b, int e) {
        double result = 1.0;
        long long exponent = e; // Use long long to handle edge cases for e = -109
        
        if (exponent < 0) {
            b = 1 / b;
            exponent = -exponent;
        }
        
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result *= b;
            }
            b *= b;
            exponent /= 2;
        }
        
        return result;
    }
};
