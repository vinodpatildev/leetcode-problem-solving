class StockSpanner {
public:
    stack<pair<int,int>> todo;
    StockSpanner() {}    
    int next(int price) {
        int count = 1;
        while(!todo.empty() && price>=todo.top().first) count += todo.top().second, todo.pop();
        todo.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */