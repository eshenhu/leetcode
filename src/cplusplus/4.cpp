/*
     Haha, I use the std-c++ 17 feature std::merge().
     It is a stupid solution as the time complexity that we don't need sort all the data.
 */
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(merge));
        
        int size = merge.size();
        
        if (size == 0)
            return 0;
        
        if (size == 1)
            return (double)merge.at(0);
        
        if (size % 2)
            return (double)merge.at(size/2);
        else
            return (double)merge.at(size/2) / 2 + (double)merge.at(size/2 - 1) / 2;
    }
};
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_nums1 = nums1.length();
        int len_nums2 = nums2.length();
        if (len_nums1 > len_nums2)
             return _findMedianSortedArraysWithS1LessS2(nums2, nums1);          
        else
             return _findMedianSortedArraysWithS1LessS2(nums1, nums2); 
    }

    /* internal implemention */
    double _findMedianSortedArraysWithS1LessS2(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.length();
        int n = nums2.length();

	std::assert(len_nums1 <= len_nums2);
       
        int iMin = 0, iMax = m, iHalf = (m + n + 1)/2;

        while (iMin <= iMax){
	    int i = (iMin + iMax) / 2;
            int j = iHalf - i;
            if (i < iMax && B[j-1] > A[i]){
                iMin = i + 1;
            }     
            else if (i > iMin && A[i-1] > B[j]){
                iMax = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = B[j -1];
                else if (j == 0)
                    maxLeft = A[i -1];
                else
                    maxLeft = max(A[i-1], B[j-1]);

                if ( (m + n) % 2 == 1)
                    return maxLeft;

                int minRight = 0;
                if (i == m)
                    minRight = B[j];
                else if (j == n)
                    minRight = A[i];
                else
                    minRight = min(A[i], B[j]);
                return (maxLeft + minRight) / 2.0; 
            }
	}
        return 0.0;
  




















    }

}
