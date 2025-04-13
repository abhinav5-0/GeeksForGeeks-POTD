class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        std::unordered_map<Node*, Node*> clones;
        std::queue<Node*> q;

        clones[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                if (clones.find(neighbor) == clones.end()) {
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                clones[current]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};
