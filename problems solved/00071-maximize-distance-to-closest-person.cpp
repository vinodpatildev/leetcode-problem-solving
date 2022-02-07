class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int size = seats.size();
        vector<int> vacants(size);
        if(seats[0]==0){vacants[0]=1;}
        else{vacants[0]=0;}
        
        for(int i=1; i<size; i++){
            if(seats[i]==1){
                vacants[i]=0;
            }else{
                vacants[i] = 1 + vacants[i-1];
            }
        }
        for(int i=0; i<size; i++){
            cout<<seats[i]<<" ";
        }cout<<endl;
        for(int i=0; i<size; i++){
            cout<<vacants[i]<<" ";
        }cout<<endl;
        //////////////////////////////////
        int maxIndex = 0,len=0,ans=0;
        for(int i=1; i<size; i++){
            if(vacants[i]>=vacants[maxIndex]){
                maxIndex = i;
            }
        }
        
        if(maxIndex==size-1){
            return vacants[maxIndex];
        }else if(maxIndex+1==vacants[maxIndex]){
            return vacants[maxIndex];
        }
        len = vacants[maxIndex];
        
        if(len%2==1){
             len = (len/2)+1;
        }else{
            len = len/2;
        }
        
        int i=0;
        while(vacants[i]!=0){i++;}
        len = max(len,i);
        if(vacants[size-1]!=0){
            len = max(len,vacants[size-1]);
        }
        return len;
    }
};