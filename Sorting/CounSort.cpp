/**
 * @file CounSort.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief Sorting algoritm for an array of real numbers, 
 *        of a smaller range(i.e. highest no. - lowest no. + 1) 
 *        as compared to the input array size
 * @date 2022-06-01
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void sortUsingCountSort(int unsortedArr[], int size) {
    int &minima = *min_element(unsortedArr, unsortedArr + size);
    int &maxima = *max_element(unsortedArr, unsortedArr + size);    
    int range = maxima - minima + 1;
    int *freqArr = new int[range];
    memset(freqArr, 0, range*sizeof(int));
    int *solArr = new int[size];

    for(int i = 0; i < size; i++) {
        freqArr[unsortedArr[i] - minima]++;
    }
   

    for(int i = 1; i < range; i++) {
        freqArr[i] += freqArr[i - 1];
    }

    

    for(int i = size - 1; i >= 0; i--) {
       solArr[freqArr[unsortedArr[i] - minima] - 1] = unsortedArr[i];
       freqArr[unsortedArr[i] - minima]--;
    }


    for(int i = 0; i < size; i++) {
    	unsortedArr[i] = solArr[i];
    }
}

int main() {
    int unsortedArr[] = {4, 3, 9, 5, 4, 3, 3, 2, 1, 1, 8, 7};
    int size = sizeof(unsortedArr)/sizeof(int);

    sortUsingCountSort(unsortedArr, size);
    
    for (int i = 0; i < size; i++) {
        cout << unsortedArr[i] << " ";
    }

    return 0;
}