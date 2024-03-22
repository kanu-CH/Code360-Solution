bool isValidParenthesis(string s)
{
   stack<char> sta;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            sta.push(ch);
        }
        else
        {
            if(!sta.empty()) {
                char top = sta.top();
                if( (ch == ')' && top == '(') || 
                    ( ch == '}' && top == '{') || 
                    (ch == ']' && top == '[') ) {
                    sta.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            } 
        }  
    }
    
    if(sta.empty())
        return true;
    else
        return false;
}
