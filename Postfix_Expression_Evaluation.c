#include<stdio.h>
char postfix[20];
int stack[20],top=-1;
void push(int symbol);
int pop();
void postfix_eval();
int main()
{ 
    printf("Enter postfix expression\n");
    scanf("%s",postfix);
    postfix_eval();
}
void postfix_eval()
{
    int i=0;
    int op1,op2,res;
    char symbol;
    while((symbol=postfix[i++])!='\0')
    {
        if(isdigit(symbol))
        {
            push(symbol-'0');
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(symbol)
            {
                case '+':res=op1+op2;
                         push(res);
                         break;
                case '-':res=op1-op2;
                         push(res);
                         break;
                case '*':res=op1*op2;
                         push(res);
                         break;
                case '/':res=op1/op2;
                         push(res);
                         break;
                
            }
        }
    }
    printf("Evaluated output is: \n");
    printf("%d\n",pop());
}

void push(int symbol)
{
    if(top==19)
    printf("Stack is full\n");
    else
    {
        top=top+1;
        stack[top]=symbol;
    }
}

int pop()
{
    if(top==-1)
    printf("Stack is empty\n");
    else
    {  
        int ele;
        ele=stack[top--];
        return ele;
    }
}
