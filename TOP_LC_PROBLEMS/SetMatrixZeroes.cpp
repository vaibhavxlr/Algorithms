/**
 * @file SetMatrixZeroes.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/set-matrix-zeroes/
 * @date 2022-06-26
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isRowZero, isColZero;
        isRowZero = false;
        isColZero = false;
        
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                isRowZero = true;
                break;
            }
        }
         
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[0][j] == 0) {
                isColZero = true;
                break;
            }
        }
        
        
        
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 1; j < matrix[0].size(); j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(isRowZero) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
          }
        }
        
        if(isColZero) {
        for(int j = 0; j < matrix[0].size(); j++) {
             matrix[0][j] = 0;
           }
        }
        
    }
};