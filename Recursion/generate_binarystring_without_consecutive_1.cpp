//Generate a binary string without consecutive ones
// Approach: Backtracking / Recursion

// Generate the string one character at a time.

// * We can always add 0.
// * We can add 1 only if the previous character is not 1.
// * When s.length() == n, we have a valid string → store it and return.

// generate("00")
//       ↓
// generate("000")
//       ↓
// length == n
//       ↓
// return
//       ↓
// back to generate("00")
//       ↓
// continue from where it stopped

//Why Lexicographically Sorted?

// Always try '0' before '1'.

class Solution {
public:
    void generate(int n, string &curr, vector<string> &ans){
        if(curr.length() ==n){
            ans.push_back(curr);
            return; 
        }
        curr.push_back('0');
        generate(n, curr, ans);
        curr.pop_back();

        if(curr.empty() || curr.back()!='1'){
            curr.push_back('1');
            generate(n, curr, ans);
            curr.pop_back();
        }


    }
    
    vector<string> generateBinaryStrings(int n) {
        vector<string>ans;
        string curr;

        generate(n, curr, ans);
        return ans;
    }
};
