class DataStream {
public:
    unordered_map <int,int> mpp;
    deque <int> stream;
    int _value,_k;
    DataStream(int value, int k) {
        _value = value;
        _k = k;
    }
    
    bool consec(int num) {
        stream.push_front(num);
        mpp[num]++;
        if(stream.size()<_k) return false;
        else if(stream.size()>_k){
            int pop_element = stream.back();
            if(mpp[pop_element] == 1) mpp.erase(pop_element);
            else mpp[pop_element]--;
            stream.pop_back();
            // cout<<"last element deleted.--"<<pop_element<<"--";
        }
        // cout<<mpp.size()<<" "<<(num==_value)<<endl;
        return mpp.size()==1 && num==_value;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */