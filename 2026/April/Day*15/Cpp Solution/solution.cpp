class Solution {
    String URLify(String s) {
        StringBuilder result = new StringBuilder();
        
        for(char c : s.toCharArray()) {
            if(c == ' ') result.append("%20");
            else result.append(c);
        }
        
        return result.toString();
    }
}
