PARENTHESIS CHECKER(SIMPLE)
TC : O(N)
SC:O(N) -(USING STACK)
==================================================


bool ispar(string expr)
    {
    stack<char>s;
    char x;
    
    for(int i =0;i<expr.length();i++){
        if(expr[i]=='{' || expr[i]=='(' || expr[i]=='[' ){
            s.push(expr[i]);
            continue;
        }
        if(s.empty())
        return false;
        
        switch(expr[i]){
            case ')':
               x = s.top();
               s.pop();
               if(x=='{' || x=='[')
               return false;
               break;
             case '}':
               x = s.top();
               s.pop();
               if(x=='(' || x=='[')
               return false;
               break;
             case ']':
               x = s.top();
               s.pop();
                if(x=='{' || x=='(')
               return false;
               break;
        }
    }
    
    return(s.empty());
    }

};