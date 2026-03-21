class Solution {
    public int[] findPreSuc(Node root, int key) {
        Node temp = root;
        int pre = -1, suc = -1;

        // Predecessor
        while (temp != null) {
            if (key > temp.data) {
                pre = temp.data;
                temp = temp.right;
            } else {
                temp = temp.left;
            }
        }

        temp = root;

        // Successor
        while (temp != null) {
            if (key < temp.data) {
                suc = temp.data;
                temp = temp.left;
            } else {
                temp = temp.right;
            }
        }

        return new int[]{pre, suc};
    }
}
