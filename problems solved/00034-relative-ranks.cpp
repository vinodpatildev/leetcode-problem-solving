class Solution {
public:
    void print_arr(vector<int>& v){
        cout<<"Array : ";
        for(int i=0; i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    void print_arr(vector<pair<int,int>>& v){
        cout<<"Array : ";
        for(int i=0; i<v.size();i++){
            cout<<"["<<v[i].first<<" "<<v[i].second<<"], ";
        }
        cout<<endl;
    }
    
    bool static sortbysec(const pair<int,int> &a,const pair<int,int> &b){
        return (a.second < b.second);
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<pair<int,int>> arr;
        int temp_rank;
        print_arr(score);
        for(int i=0; i<score.size(); i++){
            arr.push_back(make_pair(score[i],i));
        }
        print_arr(arr);
        sort(arr.rbegin(),arr.rend());
        print_arr(arr);
        for(int i=0; i<score.size(); i++){
            arr[i].first = i+1;
        }
        print_arr(arr);
        sort(arr.begin(),arr.end(),sortbysec);
        print_arr(arr);
        for(int i=0; i<score.size(); i++){
            temp_rank = arr[i].first;
            stringstream ss;
            ss << temp_rank;
            string str = ss.str();
            
            if(temp_rank>3){
                ans.push_back(str);
            }else if(temp_rank==3){
                ans.push_back("Bronze Medal");
            }else if(temp_rank==2){
                ans.push_back("Silver Medal");
            }else if(temp_rank==1){
                ans.push_back("Gold Medal");
            }
        }
        return ans;
    }
    
};