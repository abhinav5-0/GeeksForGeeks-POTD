class Solution {
    public List<String> graycode(int n) {
        List<String> res = new ArrayList<>();
        res.add("0");
        res.add("1");

        for (int i = 2; i <= n; i++) {
            List<String> temp = new ArrayList<>();

            // prefix 0
            for (String s : res)
                temp.add("0" + s);

            // prefix 1 (reverse order)
            for (int j = res.size() - 1; j >= 0; j--)
                temp.add("1" + res.get(j));

            res = temp;
        }

        return res;
    }
}
