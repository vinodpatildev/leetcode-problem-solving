class Solution {
public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = -1;
        int l1 = 0;
        int l2 = 0;
        while(l1<m && l2<n){
            if(nums1[l1] <= nums2[l2]){
                // swap(nums1[++index],nums1[l1++]);
                index++;
                l1++;
            }else{
                swap(&nums1[++index], &nums2[l2]);
                l1++;
                int l = l2;
                while(l<n-1){
                    if(nums2[l] < nums2[l+1]){
                        break;
                    }else{
                        swap(&nums2[l],&nums2[l+1]);
                    }
                    l++;
                }
            }
        }
        while(l2<n){
            swap(&nums1[++index], &nums2[l2++]);
        }
    }
};