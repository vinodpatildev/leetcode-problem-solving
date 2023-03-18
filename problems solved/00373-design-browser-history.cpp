class BrowserHistory {
    vector<string> bucket;
    int it = -1;
public:
    BrowserHistory(string homepage) {
        bucket.clear();
        bucket.push_back(homepage);
        it = 0;
    }
    
    void visit(string url) {
        while(it+1<bucket.size()) bucket.pop_back();
        bucket.push_back(url);
        it++;
    }
    
    string back(int steps) {
        it = max(0,it-steps);
        return bucket[it];
    }
    
    string forward(int steps) {
        it = min((int)bucket.size()-1,it+steps);
        return bucket[it];
    }
};
// ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
// [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]

// it = 2
// ["leetcode.com"], ["google.com"],["facebook.com"],["youtube.com"]