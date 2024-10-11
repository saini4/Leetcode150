#include <stdio.h>

// Function to merge two sorted arrays nums1 and nums2
// Time Complexity: O(m + n) where m and n are the sizes of the two arrays
// Space Complexity: O(1) as we are merging in place without using extra space

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = m - 1;         
    int j = n - 1;      
    int k = nums1Size - 1; 

    
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0)
    {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}

int main()
{
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    int m = 3;
    int n = 3;

    merge(nums1, 6, m, nums2, n,n);

    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", nums1[i]);
    }
    return 0;
}
