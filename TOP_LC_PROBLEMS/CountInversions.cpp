/**
 * @file CountInversions.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://www.codingninjas.com/codestudio/problems/count-inversions_615
 * @date 2022-07-30
 * 
 */

//Inefficient intuitive approach via recursion + divide & conquer
#include <bits/stdc++.h> 
long long getInversionsHelper(long long *arr, int start, int end) {
    if(start >= end) {
        return 0;
    }
    int mid = start + ((end - start)/2);
    long long LInversions = getInversionsHelper(arr, start, mid);
    long long RInversions = getInversionsHelper(arr, mid + 1, end);
    
    int lIndex = start;
    int rIndex = mid + 1;
    
    int count = 0;
    
    while(lIndex < rIndex) {
        int mover = rIndex;
        while(mover <= end) {
           if(arr[lIndex] > arr[mover]) {
            count++;
           }   
           mover++;
        }
        lIndex++;
    }
    return count + LInversions + RInversions;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return getInversionsHelper(arr, 0, n - 1);
}


//Efficient approach using merge sort(improvement of ^)
#include <bits/stdc++.h> 

long long mergeAndCount(long long *arr, int startF, int endF, int startS, int endS) {
    long long count = 0;
    int length = endS - startF + 1;
    long long tempArr[length];
    int i = startF, j = startS, k = 0;
    
    while(i <= endF && j <= endS) {
        if(arr[i] > arr[j]) {
            count += endF - i + 1;
            tempArr[k++] = arr[j];
            j++;
        } else {
            tempArr[k++] = arr[i];
            i++;
        }
    }
    
    while(i <= endF) {
        tempArr[k++] = arr[i++];
    }
    
    while(j <= endS) {
        tempArr[k++] = arr[j++];
    }
    
    k = 0;
    i = startF;
    j = endS;
    
    while(i <= j && k < length) {
        arr[i++] = tempArr[k++];
    }
    
    return count;
}
long long getInversionsHelper(long long *arr, int start, int end) {
    if(start >= end) {
        return 0;
    }
    int mid = start + ((end - start)/2);
    long long LInversions = getInversionsHelper(arr, start, mid);
    long long RInversions = getInversionsHelper(arr, mid + 1, end);
    long long count = mergeAndCount(arr, start, mid, mid + 1, end);
 
    return count + LInversions + RInversions;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return getInversionsHelper(arr, 0, n - 1);
}