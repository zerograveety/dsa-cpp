//Question from strivers sheet
//https://takeuforward.org/plus/dsa/problems/reverse-a-stack?source=strivers-a2z-dsa-track
//we have to reverse a stack using recusrion
//first we will just remove all the integers from stack using resursion 
//then we crete another recursive function to insert in stack.

class Solution {
public:
    void insert(int x, stack<int> &st){
        if(st.empty()){
            st.push(x);
            return;
        }
        int y = st.top();
        st.pop();

        insert(x,st);
        st.push(y);

    }
    void reverseStack(stack<int> &st) {
        if (st.empty()) return;

        int x = st.top();
        st.pop();

        reverseStack(st);

        insert(x,st);
    }
};