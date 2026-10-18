public class Solution {
    public int[] Shuffle(int[] nums, int n) {
        int[] newNums = new int[nums.Length];
        int newNumsIndex = 0;
        for(int i = 0; i < n; i++){
            newNums[newNumsIndex] = nums[i];
            newNums[newNumsIndex + 1] = nums[n + i];
            newNumsIndex = newNumsIndex + 2;
        }
        return newNums;
    }
}