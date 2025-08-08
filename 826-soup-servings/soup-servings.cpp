class Solution {
public:
    double soupServings(int n) {
        // For large n, probability approaches 1 (A empties first)
        if (n > 4800) return 1.0;
        
        // Memoization map: key = (a << 16) | b
        unordered_map<int, double> memo;
        
        return solve(n, n, memo);
    }
    
private:
    double solve(int a, int b, unordered_map<int, double>& memo) {
        // Base cases
        if (a <= 0 && b <= 0) return 0.5; // Both empty at same time
        if (a <= 0) return 1.0;           // A empty first
        if (b <= 0) return 0.0;           // B empty first
        
        // Check memo
        int key = (a << 16) | b;
        if (memo.count(key)) return memo[key];
        
        // Calculate probability: 0.25 * sum of 4 operations
        double result = 0.25 * (
            solve(a - 100, b, memo) +      // Pour 100 from A, 0 from B
            solve(a - 75, b - 25, memo) +  // Pour 75 from A, 25 from B
            solve(a - 50, b - 50, memo) +  // Pour 50 from A, 50 from B
            solve(a - 25, b - 75, memo)    // Pour 25 from A, 75 from B
        );
        
        return memo[key] = result;
    }
};