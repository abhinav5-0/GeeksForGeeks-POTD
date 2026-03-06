class Solution {
    public String minWindow(String s, String p) {

        int[] freq = new int[256];

        for(char c : p.toCharArray())
            freq[c]++;

        int start = 0;
        int startIndex = -1;
        int minLen = Integer.MAX_VALUE;
        int count = p.length();

        for(int end = 0; end < s.length(); end++) {

            if(freq[s.charAt(end)] > 0)
                count--;

            freq[s.charAt(end)]--;

            while(count == 0) {

                int len = end - start + 1;

                if(len < minLen) {
                    minLen = len;
                    startIndex = start;
                }

                freq[s.charAt(start)]++;

                if(freq[s.charAt(start)] > 0)
                    count++;

                start++;
            }
        }

        if(startIndex == -1)
            return "";

        return s.substring(startIndex, startIndex + minLen);
    }
}
