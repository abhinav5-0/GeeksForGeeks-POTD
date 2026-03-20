class Solution {
    public ArrayList<Integer> findPreSuc(Node root, int key) {
        Node pre = null, suc = null;

        while (root != null) {
            if (root.data < key) {
                pre = root;
                root = root.right;
            } else {
                suc = root;
                root = root.left;
            }
        }

        ArrayList<Integer> res = new ArrayList<>();
        res.add(pre != null ? pre.data : -1);
        res.add(suc != null ? suc.data : -1);
        return res;
    }
}
