class Solution {
    string doc;
    stack<char> redoStack;

public:
    void append(char x) {
        doc.push_back(x);
        while (!redoStack.empty()) redoStack.pop(); // clear redo history
    }

    void undo() {
        if (!doc.empty()) {
            redoStack.push(doc.back());
            doc.pop_back();
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            doc.push_back(redoStack.top());
            redoStack.pop();
        }
    }

    string read() {
        return doc;
    }
};
