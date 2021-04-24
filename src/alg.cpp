// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int Priority(char op) {
swith(op) {
case '(':
return 0;
case ')':
return 1;
case '+':
return 2;
case '-':
return 2;
case '*':
return 3;
case '/':
return 3;
default:
return -1;
}
}
std::string infx2pstfx(std::string inf) {
int i =0;
char x = inf[i];
char t = 0;
std::string pstfx;
Tstack <char> stackCh;
while (x) {
int Pr;
Pr = Prioriry(x);
if (Pr > -1) {
if ((pr == 0 || Pr > priority(t) || stackCh.isEmpty()) && x != ')') {
if (stackCh.isEmpty())
t = x;
stackCh.push(x);
} else if (x == ')')
{
while (stackCh.get() != '(') {
pstfx.push_back(stackCh.get());
pstfx.push_back(' ');
stackCh.pop();
}
stackCh.pop();
if (stackCh.isEmpty()) 
t = 0;
} else {
while (!stackCh.isEmpty() && Priority(stackCh.get() >= Pr) {
pstfx.push_back(stackCh.get());
pstfx.push_back(' ');
stackCh.pop();
}
if (stackCh.isEmpty()
t = x;
stackCh.push(x);
}
} else {
pstfx.push_back(x);
pstfx.push_back(' ');
}
x = inf[++i];
}
while (!stackCh.isEmpty()) {
pstfx.push_back(stackCh.get());
pstfx.push_back(' ');
stackCh.pop();
}
pstfx.erase(pstfx.end() - 1, pstfx.end());
return pstfx;
}
int calculating(char oper, int num1, int num2) {
switch (oper) {
case '+':
return num1 + num2;
break;
case '-':
return num1 - num2;
break;
case '*':
return num1 * num2;
break;
case '/':
return num1 / num2;
break;
}
}

int eval(std::string pst) {
TStack <int> stackInt;
int i = 0;
int res = 0;
char x = pst[i];
while (x) {
if (x >= '0' && x <= '9') {
int insInt = 0;
int y = 1;
while (x != ' ') {
insInt += (x - 48) * y;
y *= 10;
x = pst[++i];
}
stackInt.push(insInt);
} else {
char oper = x;
i++;
int num2 = stackInt.get();
stackInt.pop();
int num1 = stackInt.get();
stackInt.pop();
int res = calculating(oper, num1, num2);
stackInt.push(res);
}
if (i < pst.size())
x = pst[++i];
else
x = 0;
}
result = stackInt.get();
stackInt.pop();
return result;
}
