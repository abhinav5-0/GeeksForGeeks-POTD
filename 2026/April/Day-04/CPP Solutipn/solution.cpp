class Solution {
public:
    vector<string> graycode(int n) {
        vector<string> res;
        res.push_back("0");
        res.push_back("1");

        for (int i = 2; i <= n; i++) {
            vector<string> temp;

            // prefix 0
            for (auto &s : res)
                temp.push_back("0" + s);

            // prefix 1 (reverse order)
            for (int j = res.size() - 1; j >= 0; j--)
                temp.push_back("1" + res[j]);

            res = temp;
        }

        return res;
    }
};
