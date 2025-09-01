class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue to store the improvement each class would get if we add one student
        // We use a max heap, so the class with maximum improvement is at the top
        priority_queue<pair<double, int>> pq;
        
        // Calculate initial improvement for each class and add to priority queue
        for (int i = 0; i < classes.size(); i++) {
            double improvement = getImprovement(classes[i][0], classes[i][1]);
            pq.push({improvement, i});
        }
        
        // Assign extra students one by one to the class that gives maximum improvement
        for (int i = 0; i < extraStudents; i++) {
            auto top = pq.top();
            pq.pop();
            
            int classIndex = top.second;
            
            // Add one student to this class (both pass and total increase by 1)
            classes[classIndex][0]++;
            classes[classIndex][1]++;
            
            // Recalculate improvement for this class and add back to queue
            double newImprovement = getImprovement(classes[classIndex][0], classes[classIndex][1]);
            pq.push({newImprovement, classIndex});
        }
        
        // Calculate final average pass ratio
        double totalRatio = 0.0;
        for (const auto& cls : classes) {
            totalRatio += (double)cls[0] / cls[1];
        }
        
        return totalRatio / classes.size();
    }
    
private:
    // Calculate the improvement in pass ratio if we add one student to a class
    double getImprovement(int pass, int total) {
        // Current ratio: pass/total
        // New ratio after adding one student: (pass+1)/(total+1)
        // Improvement = (pass+1)/(total+1) - pass/total
        // Simplifying: (total - pass) / (total * (total + 1))
        // Use double arithmetic to avoid integer overflow
        return (double)(total - pass) / ((double)total * (total + 1));
    }
};