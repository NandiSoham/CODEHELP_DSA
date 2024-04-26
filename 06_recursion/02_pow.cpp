#include <iostream>
using namespace std;

class Solution {
public:
    double solve(double x, long n) {
        if (n == 0)
            return 1;
        if (n < 0) {
            return solve(1 / x, -n);
        }
        if (n % 2 == 0) {
            return solve(x * x, n / 2);
        } else {
            return x * solve(x * x, (n - 1) / 2);
        }
    }

    double myPow(double x, int n) { 
        return solve(x, n); 
    }
};

int main() {
    Solution solution;
    double x;
    int n;
    
    std::cout << "Enter the base (x): ";
    std::cin >> x;
    
    std::cout << "Enter the exponent (n): ";
    std::cin >> n;
    
    double result = solution.myPow(x, n);
    std::cout << "Result of " << x << " raised to the power of " << n << " is: " << result << std::endl;
    
    return 0;
}
