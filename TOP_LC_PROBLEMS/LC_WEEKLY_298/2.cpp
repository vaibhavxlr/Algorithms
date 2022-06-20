/**
 * @file 2.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/
 * @date 2022-06-20
 */
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) {
            return 0;
        }
        for(int i = 1; i <= 10; i++) {
            if((i*k) % 10 == (num) % 10 && (i * k) <= num) {
                return i;
            }
        }
        return -1;
    }
};