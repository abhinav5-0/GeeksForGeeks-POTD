class Solution {
    public String removeKdig(String s, int k) {
        StringBuilder st = new StringBuilder();

        for (char c : s.toCharArray()) {
            while (st.length() > 0 && k > 0 && st.charAt(st.length() - 1) > c) {
                st.deleteCharAt(st.length() - 1);
                k--;
            }
            st.append(c);
        }

        // Remove remaining digits from end
        while (k > 0 && st.length() > 0) {
            st.deleteCharAt(st.length() - 1);
            k--;
        }

        // Remove leading zeros
        int idx = 0;
        while (idx < st.length() && st.charAt(idx) == '0') idx++;

        String res = st.substring(idx);
        return res.length() == 0 ? "0" : res;
    }
}
