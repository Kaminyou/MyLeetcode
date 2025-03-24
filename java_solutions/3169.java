class Solution {
    public int countDays(int days, int[][] meetings) {
        int meetingCnt = 0;
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        int start = Integer.MAX_VALUE;
        int end = -1;
        for (int[] meeting : meetings) {
            if (meeting[0] > end) {
                if (end != -1) meetingCnt += end - start + 1;
                start = meeting[0];
                end = meeting[1];
            }
            else {
                start = Integer.min(start, meeting[0]);
                end = Integer.max(end, meeting[1]);
            }
        }
        meetingCnt += end - start + 1;
        return days - meetingCnt;
    }
}
