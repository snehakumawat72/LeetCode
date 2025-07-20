#include <vector>
#include <string>
#include <map>
#include <unordered_map>

// Using declarations for clarity
using std::vector;
using std::string;
using std::map;
using std::unordered_map;

class Solution {
private:
    // TrieNode structure to represent the file system hierarchy.
    struct TrieNode {
        // Children are stored in a map to keep them sorted alphabetically by name.
        // This is crucial for creating a canonical signature for each folder's structure.
        map<string, TrieNode*> children;
        
        // A flag to mark a node for deletion.
        bool isMarked = false;
        
        // A string to store the unique signature of the sub-tree rooted at this node.
        string signature = "";
    };

    /**
     * @brief Performs a post-order DFS traversal to generate a unique signature for each folder's structure.
     * * The signature is a string representation of the folder's immediate subfolders and their structures.
     * This function also populates a map to count occurrences of each unique signature.
     * * @param node The current TrieNode in the traversal.
     * @param counts A map to store the frequency of each generated signature.
     * @return The signature string for the sub-tree at `node`.
     */
    string generateSignatures(TrieNode* node, unordered_map<string, int>& counts) {
        // A leaf node (empty folder) has an empty structure.
        if (node->children.empty()) {
            return "";
        }

        string currentSignature = "";
        // The map `children` iterates in alphabetical order of keys (folder names).
        for (auto const& [name, child] : node->children) {
            currentSignature += name + "(" + generateSignatures(child, counts) + ")";
        }

        // Store the computed signature in the node for later access.
        node->signature = currentSignature;

        // According to the problem, only non-empty folder structures are considered for duplication.
        counts[currentSignature]++;

        return currentSignature;
    }

    /**
     * @brief Performs a pre-order DFS traversal to mark folders for deletion.
     * * A folder is marked if its structure (signature) is a duplicate.
     * If a folder is marked, all of its subfolders are also marked.
     * * @param node The current TrieNode in the traversal.
     * @param counts The map containing signature frequencies.
     * @param parentIsMarked A boolean indicating if the parent of the current node was marked.
     */
    void markForDeletion(TrieNode* node, const unordered_map<string, int>& counts, bool parentIsMarked) {
        // A folder must be marked if its parent is marked.
        bool shouldMark = parentIsMarked;

        // Additionally, a folder is marked if its own structure is a duplicate.
        if (!node->signature.empty() && counts.count(node->signature) && counts.at(node->signature) > 1) {
            shouldMark = true;
        }

        node->isMarked = shouldMark;

        // Propagate the marking decision down to all children.
        for (auto const& [name, child] : node->children) {
            markForDeletion(child, counts, shouldMark);
        }
    }

    /**
     * @brief Performs a final pre-order DFS traversal to collect the paths of all non-marked folders.
     * * @param node The current TrieNode in the traversal.
     * @param currentPath The path from the root to the parent of the current node.
     * @param result The 2D vector to store the final, non-deleted paths.
     */
    void collectPaths(TrieNode* node, vector<string>& currentPath, vector<vector<string>>& result) {
        for (auto const& [name, child] : node->children) {
            if (!child->isMarked) {
                // Construct the full path to the non-deleted child.
                currentPath.push_back(name);
                // Add this path to our answer set.
                result.push_back(currentPath);
                // Recursively explore the subfolders of this non-deleted folder.
                collectPaths(child, currentPath, result);
                // Backtrack to explore siblings.
                currentPath.pop_back();
            }
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();

        // Step 1: Build the Trie from the input paths.
        for (const auto& path : paths) {
            TrieNode* curr = root;
            for (const string& folderName : path) {
                if (curr->children.find(folderName) == curr->children.end()) {
                    curr->children[folderName] = new TrieNode();
                }
                curr = curr->children[folderName];
            }
        }

        // Step 2: Generate signatures for all folders and count their frequencies.
        unordered_map<string, int> signatureCounts;
        generateSignatures(root, signatureCounts);

        // Step 3: Mark all duplicate folders and their subfolders.
        markForDeletion(root, signatureCounts, false);

        // Step 4: Collect the paths of all folders that were not marked.
        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result);

        // Note: Memory for TrieNodes is not deallocated, which is acceptable on platforms
        // like LeetCode but would be a memory leak in a real application.

        return result;
    }
};