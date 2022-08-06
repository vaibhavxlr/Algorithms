/**
 * @file SearchA2DMatrix.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/search-a-2d-matrix/
 * @date 2022-08-06
 */


//Linear search + Binary Search solution
class Solution {
public:
    bool usingBinSearch(vector<vector<int>>& matrix, int start, int end, int row, int target) {
        if(start > end) {
            return false;
        }
        
        int mid = start + ((end - start) / 2);
        
        if(matrix[row][mid] == target) {
            return true;
        }
        
        if(matrix[row][mid] > target) {
            return usingBinSearch(matrix, start, mid - 1, row, target);
        } else {
            return usingBinSearch(matrix, mid + 1, end, row, target);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0] > target) {
            return false;
        }
        
        int rowToConsider = matrix.size() - 1;
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] > target) {
                rowToConsider = i - 1;
                break;
            }
        }
        return usingBinSearch(matrix, 0, matrix[0].size() - 1, rowToConsider, target);
    }
};


//Pure Binary Search solution assuming 2D Array is flattened to a 1D Array

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if(matrix.size() == m)
        int start = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int end = (rows * cols) - 1;
        
        while(start <= end) {
            int pivotableMid = start + ((end - start) / 2);
            int pivotableMidEle = matrix[pivotableMid / cols][pivotableMid % cols];
            if(pivotableMidEle == target) {
                return true;
            } else if(pivotableMidEle > target) {
                end = pivotableMid - 1;
            } else {
                start = pivotableMid + 1;
            }
        }
        
        return false;
    }
};

