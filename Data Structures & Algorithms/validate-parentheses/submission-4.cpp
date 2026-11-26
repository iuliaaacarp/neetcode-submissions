class Solution {
public:
    bool isOpen(char c){
        return c == '(' || c == '[' || c == '{';
    }

    bool isClosed(char c){
        return !isOpen(c);
    }

    bool theyMatch(char a, char b){
        return (a == '(' && b == ')') ||
            (a == '[' && b == ']') ||
            (a == '{' && b == '}');
    }

    bool isValid(string s) {
        std::stack<char> correct;
        int len = s.length();
        int idx = 0;

        while (idx < len){
            if (isOpen(s[idx])){
                correct.push(s[idx]);
            } else {
                if (isClosed(s[idx]) && correct.empty()){
                    return false;
                }
                char candid = correct.top();
                if (theyMatch(candid, s[idx])){
                    correct.pop();
                } else {
                    return false;
                }
            }
            idx++;
        }
        if (correct.empty()){
            return true;
        }
        return false;
    }
};
