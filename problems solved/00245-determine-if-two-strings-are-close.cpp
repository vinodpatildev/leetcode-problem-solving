class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1 == word2) return true;
        unordered_map <int,int> mp1,mp2;
        bitset<26> b1(0),b2(0);
        for(int i=0; i<word1.size(); i++) mp1[word1[i]]++, b1[word1[i]] = 1;
        for(int i=0; i<word2.size(); i++) mp2[word2[i]]++, b2[word2[i]] = 1;
        if(b1 != b2) return false;
        priority_queue<int> p1,p2;
        for(auto p : mp1) p1.push(p.second);
        for(auto p : mp2) p2.push(p.second);

        while(p1.size() &&  p2.size()){
            if(p1.top() != p2.top()) return false;
            p1.pop(); p2.pop();
        }
        if(p1.size() == 0 && p2.size() == 0) return true;
        return false;
    }
};