/**
 * @file Pow(x, n).cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/powx-n/
 * @date 2022-08-14
 */

//Simple solution if x > 0  and n > 0 and both x and n are both natural numbers
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double last = 1;
        for(int i = 1; i <= n; i++) {
            double ans = 0; 
            for(int j = 1; j <= x; j++) {
                 ans += last;
            }
            // cout << ans << endl;
            last = ans;
            // finalAns += ans;
        }  
        
        return last;
    }
};


//recursive solution, fast power algorithm, x^2n = ((x^n) * (x^n)) or x^(2n + 1) = ((x^n) * (x^n) * x) 
class Solution {
public:
    
    double myPowHelper(double x, long long n) {
        if(n == 0) {
            return 1;
        }
        double temp = myPowHelper(x, n / 2);
        if(n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * x;
        }
    }
    
    double myPow(double x, int n) {
      if(n == 0 || x == 1) {
          return 1;
      }
        
      long long pow = n;
      if(n < 0) {
          x = (1.0)/x;
          pow =  -1 * pow;
      }
        
      return myPowHelper(x, pow);
        
    }
};

//iterative solution, fast power algorithm, 
//if n is odd, multiply x with ans(since 1 is odd, it is guaranteed that ans will have final value), 
//if n is even take half of it and square x(this makes the no. of computations half)
class Solution {
public:
    
    double myPow(double x, int n) {
      long long pow = n;
        
      if(n < 0) {
        pow = -1 * pow;
        x = 1 / x;
      }
        
      double ans = 1.0;
        
      while(pow  > 0) {
        if(pow % 2 == 1) {
            ans = ans * x;
            pow = pow - 1;
        }  else {
            x = x * x;
            pow = pow / 2;
        }
      }
        
      return ans;
        
    }
};