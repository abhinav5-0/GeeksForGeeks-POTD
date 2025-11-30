class Solution {
public:
    struct State {
        int len, link;
        int next[26];
        State() : len(0), link(-1) {
            memset(next, -1, sizeof(next));
        }
    };

    vector<State> st;
    int last;

    void sa_init() {
        st.clear();
        st.push_back(State());
        last = 0;
    }

    void sa_extend(char c) {
        int cur = st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        int p = last;
        int letter = c - 'a';

        while (p != -1 && st[p].next[letter] == -1) {
            st[p].next[letter] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[letter];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;

                while (p != -1 && st[p].next[letter] == q) {
                    st[p].next[letter] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    int countSubs(string& s) {
        sa_init();
        for (char c : s) sa_extend(c);

        long long ans = 0;
        for (int i = 1; i < (int)st.size(); i++) {
            ans += st[i].len - st[st[i].link].len;
        }
        return ans;
    }
};
