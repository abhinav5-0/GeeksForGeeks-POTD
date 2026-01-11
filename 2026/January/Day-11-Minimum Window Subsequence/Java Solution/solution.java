class Solution {
    public String minWindow(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int minLen = Integer.MAX_VALUE, start = -1;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(0)) continue;

            int p1 = i, p2 = 0;

            // forward scan
            while (p1 < n && p2 < m) {
                if (s1.charAt(p1) == s2.charAt(p2)) p2++;
                p1++;
            }

            if (p2 < m) continue;

            // backward shrink
            int end = p1 - 1;
            p2 = m - 1;
            while (p1 >= i) {
                if (s1.charAt(p1) == s2.charAt(p2)) p2--;
                if (p2 < 0) break;
                p1--;
            }

            int len = end - p1 + 1;
            if (len < minLen) {
                minLen = len;
                start = p1;
            }
        }

        return start == -1 ? "" : s1.substring(start, start + minLen);
    }
}
