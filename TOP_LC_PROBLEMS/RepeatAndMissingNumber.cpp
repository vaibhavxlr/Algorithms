/**
 * @file RepeatAndMissingNumber.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://www.interviewbit.com/problems/repeat-and-missing-number-array/
 * @date 2022-07-27
 * 
 */

using ll = long long;

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll sumInd = 0, sumSqu = 0;
    
    for(int i = 0; i < A.size(); i++) {
        sumInd += (ll)A[i];
        sumSqu += (ll)(A[i]) * (ll)(A[i]);
        sumInd -= (ll)(i + 1);
        sumSqu -= (ll)(i + 1) * (ll)(i + 1);
    }
    
    ll remAns = sumSqu / sumInd; //as sumSqu = (A^2 - B^2) and sumInd = (A - B), remAns will be (A + B)
                                 //where A is sum of all A[i] and B is sum of all i + 1(i.e. first n numbers)
                                 //calculated at the same time
                                 
    ll repeated = (remAns + sumInd) / 2;
    ll missing = (remAns - sumInd) / 2;
    
    return {(int)repeated, (int)missing};
}
