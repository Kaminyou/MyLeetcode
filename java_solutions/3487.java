class Solution {
    public int maxSum(int[] nums) {
        Set<Integer> st = new HashSet();
        int res = 0;
        int used = 0;
        int maxVal = Integer.MIN_VALUE;
        for (int num : nums) {
            maxVal = Integer.max(maxVal, num);
            if (num > 0) {
                if (!st.contains(num)) {
                    res += num;
                    st.add(num);
                    used += 1;
                }
            }
        }
        if (used == 0) {
            return maxVal;
        }
        return res;
    }
}
