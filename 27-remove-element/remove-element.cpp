class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
         if(nums[left]==val){
            if(nums[right]!=val){
            swap(nums[left],nums[right]);
            left++;
         }
         else {right--;}
    }
    else {left++;}
        }
  
    int k=left;
    return k;}
};