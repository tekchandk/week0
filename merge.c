// Outputs sorted array by merge method
// Author : Tek Chand
// 29 January 2018
// Week : 2


// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
int* merge(int* arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    /* create temp arrays */
    int L[n1], R[n2]; 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
    {
        L[i] = arr[l + i]; 
    }
        
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
    } 
 
  
    // Merge the temp arrays back into arr[l..r]
    // Initial index of first subarray
    i = 0;  
    // Initial index of second subarray 
    j = 0; 
    // Initial index of merged subarray
    k = 0;  
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of R[], if there are any 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    return arr;
} 
  
// l is for left index and r is right index of the sub-array of arr to be sorted 
void mergeSort(int* arr, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 