#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsOperand(char C) 
{
  if(C >= '0' && C <= '9') return true;
  if(C >= 'a' && C <= 'z') return true;
  if(C >= 'A' && C <= 'Z') return true;
  return false;
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
int infixToPostfix(string exp)
{
    int i , k=-1;
    char *res;

    stack <char> st;

    for(i=0;i<exp.size();i++)
    {
      if(IsOperand(exp[i]))
        cout << exp[i];						/*res[++k]=exp[i];*/
      else
      {
        if(exp[i] == '(')
          st.push(exp[i]);
        else
        {
          if(exp[i] == ')')
          {
            while(!st.empty() && st.top() != '('){     	
              	cout << st.top();							/*res[++k] = st.top();*/
              st.pop();
            }

            if(!st.empty() && st.top() != '(')
              return -1;
            else
              st.pop();
          }
          else
          {
            while(!st.empty() && Prec(exp[i]) <= Prec(st.top())){
              cout << st.top(); 
              st.pop();
            }
            st.push(exp[i]);
          }

        }
      }


    }

        while(!st.empty()){
          cout << st.top();
          st.pop();
        }
  	cout << "\n";
  	return 1;      
} 
 
int main()
{
  string exp;
  int i , ct1 = 0, ct2 = 0;

  cin >> exp;

  for(i=0;i<exp.size();i++)
  {
  	if(exp[i] == '(' )
  		ct1++;
  	if(exp[i] == ')')	
  		ct2++;	
  }
  if(ct1 == ct2)
 	 infixToPostfix(exp); 
  else
  	cout << "-1\n";
  return 0;
}