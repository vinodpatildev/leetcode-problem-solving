class SummaryRanges {
public:
    set<int>st; //initialize set
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value); //adding value in set
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans; 
        vector<int>t(st.begin(),st.end()); // converting set to vector for better traversing [for me :)]
        int i = 0;
        while(i<t.size())
        {
            int start = t[i]; //start of interval
			
			//while there is values whose difference is 1 just consider it.. in the range
            while(i+1<t.size() and t[i]+1 == t[i+1])
            {
                i++;
            }
            ans.push_back({start,t[i]});
            i++;
        }
        return ans;
    }
};


/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */