/*

 The code should maintain the following invariant:

 All elements before the slow pointer (lastNonZeroFoundAt) are non-zeroes.
 All elements between the current and slow pointer are zeroes.

Note:
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.

 ------------------------------------------------------------------------------

 Approach #2 (Space Optimal, Operation Sub-Optimal) [Accepted]
 void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found.
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 	// After we have finished processing new elements,
 	// all the non-zero elements are already at beginning of array.
 	// We just need to fill remaining array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

 ------------------------------------------------------------------------------

 Approach #3 (Optimal) [Accepted]
 void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}

 ------------------------------------------------------------------------------

*/