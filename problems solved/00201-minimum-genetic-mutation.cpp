class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        string geneConstant = "ACGT";
        queue<string> todo;
        unordered_set<string> bankSet;
        todo.push(start);
        bankSet.insert(start);
        
        int steps = 0;
        while(!todo.empty()){
            int size = todo.size();
            for(int i=0; i<size; i++){
                string curr = todo.front(); todo.pop();
                if(curr==end){ return steps; }
                for(int i=0; i<curr.size(); i++){
                    char ch = curr[i];
                    for(int j=0; j<geneConstant.size(); j++){
                        curr[i] = geneConstant[j];
                        if(bankSet.find(curr) == bankSet.end() && find(bank.begin(),bank.end(),curr) != bank.end() ){
                            todo.push(curr);
                            bankSet.insert(curr);
                        }
                    }
                    curr[i] = ch;
                }
            }
            steps++;
        }
        return -1;
    }
};