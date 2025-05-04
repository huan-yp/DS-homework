#include <bits/stdc++.h>
using namespace std;
int match(char* ch){
    if(*ch == '(')
        return 1;
    if(*ch == ')')
        return -1;
    if(*ch == '[')
        return 2;
    if(*ch == ']')
        return -2;
    if(*ch == '{')
        return 3;
    if(*ch == '}')
        return -3;
    if(*ch=='/'&&*(ch+1)=='*')
        return 4;
    if(*ch=='*'&&*(ch+1)=='/')
        return -4;
    return 0;
}
void modify(char* &ch){
    int var = match(ch);
    ch++; ch += abs(var) == 4;
}
string prt(int var){
    switch (var){
    case 1:
        return "(";
    case 2:
        return "[";
    case 3:
        return "{";
    case 4:
        return "/*";
    case -1:
        return ")";
    case -2:
        return "]";
    case -3:
        return "}";
    case -4:
        return "*/";
    default:
        return "";
    }
}
int main()
{
    /*
    S=“(”;
    S="/ *(* /";
    S=“(())()()))()”;
    S=“[]{(})()”;
    S=“[({((({[]})))})]”;
    S=“(())ld()([[{[))dq)]}z]]()”;
    S=“(())/* i* /{()[()]}()”;
    S=“((g))()([[{[xq)))]}vaj]]()”;
    S=“(({{))ld[()([[{[))dq)]}z]]()”;
    */
    char ch[][200] = {
        "(",
        "/*(*/",
        "(())()()))()",
        "[]{(})()",
        "[({((({[]})))})]",
        "(())ld()([[{[))dq)]}z]]()",
        "(())/*i*/{()[()]}()",
        "((g))()([[{[xq)))]}vaj]]()",
        "(({{))ld[()([[{[))dq)]}z]]()",
    };
    for(int i=0;i<9;i++){
        cout << "testing " << i + 1 << ":" << ch[i] << endl;
        char* p = ch[i];
        stack<pair<int, int>> s;
        while(*p){
            int var = match(p);
            if(!var){
                p++;
            }
            else{
                if(var > 0){
                    s.push(make_pair(var, p - ch[i]));
                }
                else{
                    if(s.empty()){
                        cout << "error on pos " << p - ch[i] + 1 << " " << prt(var) << ": no left braket found" << endl;
                        break;
                    }
                    if(s.top().first != abs(var)){
                        cout << "error on pos " << p - ch[i] + 1 << " " << prt(var) <<  ": unmatched left braket found" << endl;
                        cout << "found " << prt(s.top().first) << " at pos " << s.top().second + 1 << endl;
                        break;
                    }
                    s.pop();
                }
                modify(p);
            }            
        }
        if(*p){
            continue;
        }
        if(!s.empty()){
            cout << "error on pos " << s.top().second + 1 << " " << prt(s.top().first) << ": no matched right braket found" << endl;
            continue;
        }
        cout << "Correct" << endl;
    }
    return 0;
}
