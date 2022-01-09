class Solution {
public:
    bool helper(string ss,string st){
        int ss_size = ss.size();
        int st_size = st.size();
        
        // cout<<"ss : "<<ss<<" "<<ss_size<<" -- "<<"st : "<<st<<" "<<st_size<<endl;
        
        if(ss_size==0&&st_size==0){
            return true;;
        }else if(ss_size==0){
            return false;
        }
        int i=0;
        int j=0;
        while(i+1<ss_size){
            if(ss[i]==ss[i+1]){
                i++;
            }else{break;}
        }
        while(j<st_size){
            if(st[j]==ss[i]){
                j++;
            }else{break;}
        }
        j--;
        // cout<<"     "<<"i : "<<i<<" j : "<<j<<endl;
        
        if(j<0){
            return false;
        }
        int k = (j+1)/(i+1);
        if(k==1 || k>=3){
            return helper(ss.substr(i+1,ss_size-i-1),st.substr(j+1,st_size-j-1));
        }else if(i>0){ 
            return helper(ss.substr(1,ss_size-1),st.substr(1,st_size-1));
        }
        return false;
    }
    int expressiveWords(string s, vector<string>& words) {
        int count=0;
        for(int i=0; i<words.size(); i++){
            if(helper(words[i],s)){
                count++;
                // cout<<"passed " <<s<<" - "<<words[i]<<endl;
            }
        }
        return count;
    }
};