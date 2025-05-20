class Solution {
  public:
    // Step 1: Create parent mapping and locate target node
    void createParentMapping(Node* root, unordered_map<Node*, Node*>& parent, Node*& targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->data == target) {
                targetNode = current;
            }
            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }

    // Step 2: Burn the tree using BFS and track time
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parent) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false; // check if any node is burned in this second
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                // Check left child
                if (current->left && !visited[current->left]) {
                    flag = true;
                    visited[current->left] = true;
                    q.push(current->left);
                }

                // Check right child
                if (current->right && !visited[current->right]) {
                    flag = true;
                    visited[current->right] = true;
                    q.push(current->right);
                }

                // Check parent
                if (parent[current] && !visited[parent[current]]) {
                    flag = true;
                    visited[parent[current]] = true;
                    q.push(parent[current]);
                }
            }

            if (flag) time++;
        }

        return time;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = NULL;
        createParentMapping(root, parent, targetNode, target);
        return burnTree(targetNode, parent);
    }
};
