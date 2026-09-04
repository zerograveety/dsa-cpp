//striver sheet
//https://takeuforward.org/plus/dsa/problems/sort-a-stack?source=strivers-a2z-dsa-track

//we have to just sort a stack in decending order
//we will create 2 recursive function 1 to just pop all the elements from stack. and we will keep every element in x 
//after that our 2nd recursive function will come to an action 
//when our 1st function returns from last or 2nd function will check if the top element present in the stack is smaller than the current x. if yes then push in stack if not then we will just pop that st.top() and will put our current x and then we will again put that prev st.top and put it back.


class Solution {
public:
    void checkTop(int x, stack<int> &st){
        if(st.empty() || x>=st.top()){
            st.push(x);
            return;
        }
        int y = st.top();
        st.pop();

        checkTop(x,st);
        st.push(y);
    };
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
       int x = st.top();
       st.pop();

       sortStack(st);

       checkTop(x, st);
       return;
    
    }
};