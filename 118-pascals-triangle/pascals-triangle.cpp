class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; i++) {
            // Create a new row with (i+1) elements, all initialized to 1
            vector<int> row(i + 1, 1);
            
            // Fill the middle elements (first and last are always 1)
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            
            triangle.push_back(row);
        }
        
        return triangle;
    }
};