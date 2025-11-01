class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Convert array to unordered_set for O(1) lookup
        unordered_set<int> toRemove(nums.begin(), nums.end());
        
        // Skip all nodes at the beginning that need to be removed
        while (head != nullptr && toRemove.count(head->val)) {
            head = head->next;
        }
        
        // If all nodes were removed (shouldn't happen per constraints)
        if (head == nullptr) return nullptr;
        
        ListNode* curr = head;
        
        // Remove nodes from the middle/end by skipping them
        while (curr != nullptr && curr->next != nullptr) {
            if (toRemove.count(curr->next->val)) {
                // Skip the next node (don't delete, just unlink)
                curr->next = curr->next->next;
            } else {
                // Move to next node
                curr = curr->next;
            }
        }
        
        return head;
    }
};

// Alternative approach with dummy node (cleaner for edge cases)
class Solution2 {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(), nums.end());
        
        // Create dummy node to handle head removal easily
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* curr = &dummy;
        
        while (curr->next != nullptr) {
            if (toRemove.count(curr->next->val)) {
                // Skip the node (unlink but don't delete)
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};