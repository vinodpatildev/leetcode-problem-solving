class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        //no of elements in left of median inclusive
        int no_elements_left = (n+1) >> 1;

        //expected elements to be picked from array nums1 0 >> n1;
        int low=0, high=n1;

        while(low <= high){
            int mid1 = (low+high) >> 1;
            int mid2 = no_elements_left - mid1;

            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;

            if(0 <= mid1-1) l1 = nums1[mid1-1];
            if(mid1 < n1) r1 = nums1[mid1];

            if(0 <= mid2-1) l2 = nums2[mid2-1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(l1 > r2) high = mid1-1;
            else if(l2 > r1) low = mid1+1;
            else {
                if(n&1) return max(l1,l2);
                return ((double)max(l1,l2) + min(r1,r2)) / 2.0;
            }
        }
        return -1;
    }
};