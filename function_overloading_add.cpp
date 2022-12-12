
#include <iostream>
using namespace std;
void add(int a,int b)
{
int c=a+b;
cout<<"Summation="<<c;
}
void add(float a,float b)
{
float c=a+b;
cout<<"Summation="<<c;
}

void add(char a,char b)
{
int c=a+b;
cout<<"Summation="<<c;
}

void add(int a,int b,int c)
{
int d=a+b+c;
cout<<"Summation="<<d;
}
int main()
{
int a;
for(;;)
{
cout<<"\nSpecify type of numbers you want to add\n1.)Integer\n2.)Float\n3.)Character\n4.)3integers\n5.)Exit"<<endl;
cin>>a;
switch(a)
{
case 1:
int b,c;
cout<<"Enter two integer type numbers"<<endl;
cin>>b>>c;
add(b,c);
break;
case 2:
float d,e;
cout<<"Enter two floating type numbers"<<endl;
cin>>d>>e;
add(d,e);
break;
case 3:
char f,g;
cout<<"Enter two characters"<<endl;
cin>>f>>g;
add(f,g);
break;
case 4:
int h;
cout<<"Enter three integer numbers"<<endl;
cin>>b>>c>>h;
add(b,c,h);
break;
default:exit(0);
}
}
}
