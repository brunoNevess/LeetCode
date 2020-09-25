class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int x:nums1) v.push_back(x);
        for(int x:nums2) v.push_back(x);
        sort(begin(v),end(v));
        int n = v.size();
        return n%2 == 1 ? v[n/2] : 0.5*(v[n/2] + v[(n-1)/2]);
    }
};