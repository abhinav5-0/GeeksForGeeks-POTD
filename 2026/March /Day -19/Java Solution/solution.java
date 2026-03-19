class NodeInfo {
    int min, max, size;
    boolean isBST;

    NodeInfo(int min, int max, int size, boolean isBST) {
        this.min = min;
        this.max = max;
        this.size = size;
        this.isBST = isBST;
    }
}

class Solution {
    int maxSize = 0;

    NodeInfo solve(Node root) {
        if (root == null)
            return new NodeInfo(Integer.MAX_VALUE, Integer.MIN_VALUE, 0, true);

        NodeInfo left = solve(root.left);
        NodeInfo right = solve(root.right);

        if (left.isBST && right.isBST &&
            root.data > left.max && root.data < right.min) {

            int size = left.size + right.size + 1;
            maxSize = Math.max(maxSize, size);

            return new NodeInfo(
                Math.min(root.data, left.min),
                Math.max(root.data, right.max),
                size,
                true
            );
        }

        return new NodeInfo(Integer.MIN_VALUE, Integer.MAX_VALUE,
                            Math.max(left.size, right.size), false);
    }

    int largestBst(Node root) {
        solve(root);
        return maxSize;
    }
}
