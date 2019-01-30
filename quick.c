// Outputs sorted array by quick method
// Author : Tek Chand
// 29 January 2018
// Week : 2

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int* arr, int low, int high) 
{ 
    // Pivot 
    int pivot = arr[high];    
    // Index of smaller element
    int i = (low - 1);   
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= pivot) 
        { 
            // Increment index of smaller element 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
  
  // low  --> Starting index, 
  // high  --> Ending index 
int* quickSort(int* arr, int low, int high) 
{ 
    if (low < high) 
    { 
        // pi is partitioning index
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before partition
        quickSort(arr, low, pi - 1); 
        // Separately sort elements after partition
        quickSort(arr, pi + 1, high); 
    } 
    return arr;
} 