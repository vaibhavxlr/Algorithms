class Solution {
public:

    void mergeSort(vector<int>& nums, int start, int end) {
        if(start >= end) {
            return;
        }

        int mid = start +  ((end - start) / 2);
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        int *arr = new int[end - start + 1];
        // int arr[start - end];
        int i = start, j = mid + 1, k = 0;

        while(i <= mid && j <= end) {
            if(nums[i] < nums[j]) {
                arr[k++] = nums[i++];
            } else {
                arr[k++] = nums[j++];
            }
        }

        while(i <= mid) {
            arr[k++] = nums[i++];
        } 

        while(j <= end) {
            arr[k++] = nums[j++];
        }

        k = 0;
        
        for(int i = start; i <= end; i++) {
            nums[i] = arr[k++];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        mergeSort(nums, 0, size - 1);
        return nums;
    }
};