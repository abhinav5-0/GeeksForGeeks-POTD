class Solution {
    
    class Node {
        int freq;
        Node left, right;
        
        Node(int f) {
            freq = f;
            left = right = null;
        }
    }
    
    public ArrayList<String> huffmanCodes(String s, int f[]) {
        
        PriorityQueue<Node> pq = new PriorityQueue<>(
            (a, b) -> a.freq - b.freq
        );
        
        for (int i = 0; i < f.length; i++) {
            pq.add(new Node(f[i]));
        }
        
        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();
            
            Node newNode = new Node(left.freq + right.freq);
            newNode.left = left;
            newNode.right = right;
            
            pq.add(newNode);
        }
        
        Node root = pq.poll();
        ArrayList<String> result = new ArrayList<>();
        
        generate(root, "", result);
        return result;
    }
    
    void generate(Node root, String str, ArrayList<String> res) {
        if (root == null) return;
        
        if (root.left == null && root.right == null) {
            res.add(str);
        }
        
        generate(root.left, str + "0", res);
        generate(root.right, str + "1", res);
    }
}
