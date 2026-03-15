class Solution {
    public ArrayList<ArrayList<Integer>> verticalOrder(Node root) {
        
        TreeMap<Integer, ArrayList<Integer>> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        
        q.add(new Pair(root, 0));
        
        while(!q.isEmpty()) {
            Pair p = q.poll();
            
            Node node = p.node;
            int hd = p.hd;
            
            map.putIfAbsent(hd, new ArrayList<>());
            map.get(hd).add(node.data);
            
            if(node.left != null)
                q.add(new Pair(node.left, hd - 1));
                
            if(node.right != null)
                q.add(new Pair(node.right, hd + 1));
        }
        
        return new ArrayList<>(map.values());
    }
}

class Pair {
    Node node;
    int hd;
    
    Pair(Node n, int h) {
        node = n;
        hd = h;
    }
}
