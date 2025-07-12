class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // Use memoization to avoid recomputing the same states
        map<vector<int>, pair<int, int>> memo;
        
        vector<int> initial;
        for (int i = 1; i <= n; i++) {
            initial.push_back(i);
        }
        
        auto result = solve(initial, firstPlayer, secondPlayer, memo);
        return {result.first, result.second};
    }
    
private:
    pair<int, int> solve(vector<int>& players, int fp, int sp, map<vector<int>, pair<int, int>>& memo) {
        if (memo.count(players)) {
            return memo[players];
        }
        
        int n = players.size();
        
        // Check if fp and sp will compete in this round
        bool willCompete = false;
        for (int i = 0; i < n / 2; i++) {
            int left = players[i];
            int right = players[n - 1 - i];
            if ((left == fp && right == sp) || (left == sp && right == fp)) {
                willCompete = true;
                break;
            }
        }
        
        if (willCompete) {
            memo[players] = {1, 1};
            return {1, 1};
        }
        
        // Simulate all possible outcomes for this round
        vector<vector<int>> nextRounds;
        generateNextRounds(players, fp, sp, 0, vector<int>(), nextRounds);
        
        int minRound = INT_MAX, maxRound = INT_MIN;
        
        for (auto& nextPlayers : nextRounds) {
            auto result = solve(nextPlayers, fp, sp, memo);
            minRound = min(minRound, result.first + 1);
            maxRound = max(maxRound, result.second + 1);
        }
        
        memo[players] = {minRound, maxRound};
        return {minRound, maxRound};
    }
    
    void generateNextRounds(vector<int>& players, int fp, int sp, int pos, vector<int> current, vector<vector<int>>& results) {
        int n = players.size();
        
        if (pos == n / 2) {
            // Add middle player if odd number of players
            if (n % 2 == 1) {
                current.push_back(players[n / 2]);
            }
            // Sort by original position
            sort(current.begin(), current.end());
            results.push_back(current);
            return;
        }
        
        int left = players[pos];
        int right = players[n - 1 - pos];
        
        // Determine who can win
        if (left == fp || left == sp) {
            // fp or sp always wins against others
            current.push_back(left);
            generateNextRounds(players, fp, sp, pos + 1, current, results);
            current.pop_back();
        } else if (right == fp || right == sp) {
            // fp or sp always wins against others
            current.push_back(right);
            generateNextRounds(players, fp, sp, pos + 1, current, results);
            current.pop_back();
        } else {
            // Either can win - try both possibilities
            current.push_back(left);
            generateNextRounds(players, fp, sp, pos + 1, current, results);
            current.pop_back();
            
            current.push_back(right);
            generateNextRounds(players, fp, sp, pos + 1, current, results);
            current.pop_back();
        }
    }
};