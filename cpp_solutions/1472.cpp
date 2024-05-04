class BrowserHistory {
public:
    stack<string> forwardST;
    stack<string> backwardST;
    
    BrowserHistory(string homepage) {
        forwardST.push(homepage);
    }
    
    void visit(string url) {
        while (!backwardST.empty()) {
            backwardST.pop();
        }
        forwardST.push(url);
    }
    
    string back(int steps) {
        while (steps && forwardST.size() > 1) {
            string current = forwardST.top();
            forwardST.pop();
            backwardST.push(current);
            steps--;
        }
        return forwardST.top();
    }
    
    string forward(int steps) {
        while (steps && !backwardST.empty()) {
            string current = backwardST.top();
            backwardST.pop();
            forwardST.push(current);
            steps--;
        }
        return forwardST.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */