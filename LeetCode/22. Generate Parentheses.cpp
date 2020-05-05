# define MAX_SIZE 100 

class Solution {
public:
    
    vector<string> v ;
    char s[MAX_SIZE] ; 
    void printParentheses(int position ,int n,int open,int closed){
        if(closed == 0) {
            v.push_back(s);
            return ;
        }
        else {
            if(open > 0){
                s[position] = '(' ; 
                printParentheses(position+1,0,open-1,closed);
            }
            
            if (closed > open){
                s[position] = ')';
                printParentheses(position+1,0,open,closed-1);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        printParentheses(0,0,n,n);
        return v;
    }
};
