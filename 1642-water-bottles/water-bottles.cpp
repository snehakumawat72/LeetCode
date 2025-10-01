class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;  // Drink all initial bottles
        int emptyBottles = numBottles; // Now we have this many empty
        
        // Keep exchanging while we can
        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;  // Full bottles from exchange
            totalDrunk += newBottles;  // Drink the new bottles
            
            // Update empty bottles: leftover + newly drunk bottles
            emptyBottles = emptyBottles % numExchange + newBottles;
        }
        
        return totalDrunk;
    }
};