#include<iostream>
#include<stack>
using namespace std;
#define size 10
int s[size],top=-1;


void push(int value)
{
      top++;
      s[top] = value;
}

void display()
{
for(int i=top;i>=0;i--)
{
cout<<s[i]<<" ";
}
cout<<"\n";
}

void pop()
{
if(top==-1)
{
cout<<"not possible to pop "<<"\n";
}
else
{
top--;
}
}

void isfull()
{
if(top==size-1)
{
cout<<"full"<<"\n";
}
else cout<<"not full \n";
}

void isEmpty()
{
if(top==-1)
{
cout<<"Empty hai";
}
else cout<<"Empty nahi hai";
}

void peek()
{
cout<<s[top]<<endl;
}

int main() {
   
    int n=5;
    while(1)
    {
    int i;
    int f=0;
    cout<<"\n\n\n22.END\n\n\n0.display\n1.push\n2.pop\n3.isfull\n4.isEmpty\n5.peek\n6.stacktop\nEnter: \n\n";
    cin>>i;
   
    switch(i)
    {
    case 0:
    display();
    break;
    case 1:
    int value;
    cout<<"Enter value: ";
    cin>>value;
    push(value);    
    break;
    case 2:
    pop();
    break;
case 22:
f=1;
break;
case 3:
isfull();
break;
case 4:
isEmpty();
break;
case 5:
peek();
break;
case 6:
peek();
break;  
   
}
if(f==1)break;
}
   
}
