// 1922 Leetcode
// logic is same as leetcode 50
//Count Good Numbers — Notes

// Key Idea

// For a good number:

// * Even digit positions → 5 choices: 0, 2, 4, 6, 8
// * Odd digit positions → 4 choices: 2, 3, 5, 7

// So:

// n even:
// 5^(n/2) × 4^(n/2)
// n odd:
// 5^(n/2 + 1) × 4^(n/2)

// Problem

// n can be extremely large, so calculating 5^n normally causes overflow.

// The answer must be returned:

// MOD = 1e9 + 7

// Solution

// Use recursive fast exponentiation:

// power(x, n)

// Instead of calculating x^n one multiplication at a time:

// x^n → x^(n/2) → x^(n/4) → ...

// This gives:

// O(log n)

// Important MOD Rule

// After every multiplication, take % MOD:

// long long result = (half * half) % MOD;
// if(n % 2)
//     result = (result * x) % MOD;

// This keeps numbers small and prevents overflow.

// Recursive Base Case

// if(n == 0)
//     return 1;

// because:

// x^0 = 1

// Remember

// When you see:

// x^n % MOD

// think:
// Fast Power + MOD after multiplication




class Solution {
public:
    long long myPow(int x, long long y){
        const long long MOD = 1000000007; //
        if(y == 0) return 1; 
        long long half = myPow( x, y/2);
        long long foreven= (half * half) %  MOD;

        if(y%2 != 0){
            return (foreven * x) % MOD;
        }else{ 
            return foreven;

        }
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007;
        long long N = n/2;
        
        
         if(n%2 != 0){
            return ((myPow( 5, N) * myPow(4, N) % MOD) * 5 % MOD);
        }else{ 
            return (myPow( 5, N) * myPow(4, N) % MOD);

        }
    }
};