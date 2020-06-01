#include <iostream>
#include<iomanip>
#include <fstream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>

using namespace std;
bool ex;
int debugm;
void help(char a[150]);
void notepad();
void exptree(char postfix[150]);
void date();
void launch(char a[150]);
void searchh(char a[150]);
class data{
    public:
      char input[150];
      char output[150];
      int it;
      void t_input(){
        char st[10];
          cout<<"enter the key phase"<<endl;
          gets(input);
          cout<<"enter the phase you want to print in none enter ' ':";
          gets(output);
          cout<<"enter th e type of input:";
          gets(st);
         sscanf(st, "%d", &it);

          cout<<"added data"<<endl;
          }

      int check_type(char a[150]){
          //cout<<endl<<a;//<<"**"<<endl<<input<<"**"<<endl;
          if(it==1)
          	if(strcmp(a,input)==0){
          		return 1;
          }
          if(strlen(a)>=strlen(input)){
          	for(int i=0;i<strlen(input);i++)
          		if(a[i]!=input[i])
            		return 0;
            return it;
          }

          return 0;
        }

      void output1()
        {
            cout<<"your output are"<<endl;
            cout<<input<<endl<<output<<endl<<it<<endl<<endl;
        }

};
//add developers mode(user can create code which can be add to the cpp)
//add new function option
//add time-date function 6
//add calculate function 4
//import different cpp files
//add editors mode 2
//add help 5
//discussion functions
//add bye function 3
//add games(if possible)
//add 'add' functions 6
int datacheck(char input[150]);
void bye()
{
    cout<<"RIUI> BYE BYE";
    ex=false;
}
void add_to_file(int n)
{
    ofstream file;
   file.open("data.txt", ios::out|ios::app|ios::binary);
    ifstream ffile("data.txt", ios::in|ios::app|ios::binary);
    for(int i=0;i<n;i++)
    {
        data a;
        a.t_input();
        file.write((char*)&a,sizeof(a));
    }
    file.close();

}
void del_from_file(char b[150])//7
{
    //cout<<b;
    fstream file;
    file.open("data.txt", ios::in|ios::binary);
    fstream ffile("temp.txt", ios::out|ios::binary);
    while(!file.eof())
    {
        data a;
        //a.t_input();
        file.read((char*)&a,sizeof(a));
        if(strcmp(a.input,b)!=0)
        ffile.write((char*)&a,sizeof(a));
    }
    ffile.close();
    file.close();
    //ifstream file;
   file.open("temp.txt", ios::in|ios::binary);
    //ofstream
    ffile.open("data.txt", ios::out|ios::binary);
    while(!file.eof())
    {
        data a;
        //a.t_input();
        file.read((char*)&a,sizeof(a));
        //if(strcmp(a.input,b)!=0)
        ffile.write((char*)&a,sizeof(a));
    }
    ffile.close();
    file.close();


}
void debug_func()
{
    cout<<"\nriui> sorry admin this command is not available\n riui> do you want to add it? "<<endl;
    char st[150];
    gets(st);
    if(strcmp(st,"yes")==0)
        add_to_file(1);
    else
       cout<<"\nriui> no problem i would ignore it ;)\n\n"<<endl;
}
int main()
{
    debugm=0;
    ex=true;
    //add_to_file(0);
    char input[150]="";
    while(ex==true)
    {
    char f[150];
    cout<<"User> ";
    gets(f);
    strcpy(input,f);
    //cout<<f;
    int k= datacheck(input);
    }
}
void divfunc(char a[150],int n)
{
    switch(n){
    case 1:cout<<"not possible"<<endl;
    break;
    case 2:notepad();//notepad
    break;
    case 3:bye();// bye bye
    break;
    case 4:exptree(a);//calculate exp
    break;
    case 6:add_to_file(1);//add to file
    break;
    case 7:del_from_file(a);//delete exp
    break;
    case 8:debugm++;//switch debug mode
    break;
    case 9:date();//show date
    break;
    case 10:help(a);
    break;
    case 11:launch(a);
    break;
    case 12:searchh(a);
    break;
    case 13:searchh(a);
    break;
    default:cout<<"wrong input";
    break;
    }
}

void formeqn(char input[150],char a[150],data d)
{
    int j=0;
    for(int i=strlen(d.input)+1;i<strlen(input);i++)
        a[j++]=input[i];
}
int datacheck(char input[150])
{
    ifstream file;
    file.open("data.txt", ios::in|ios::app|ios::binary);
    data a;
    while(!file.eof()){
            //cout<<"check1";
    file.read((char*)&a,sizeof(a));
    int n=a.check_type(input);
    //cout<<" "<<input<<endl;
    //cout<<a.input<<endl;
    if(n==1)
    {
        file.close();
        cout<<"Riui>"<<a.output<<endl<<endl;
        //break;
        return 1;

    }
    else if(n!=0)
    {
        file.close();
        if(n!=12){
        char eqn[150]="";
        formeqn(input,eqn,a);
        divfunc(eqn,n);}
        else
            divfunc(input,n);
        return 1;

    }
    }
    file.close();
    if(debugm%2==0){

    cout<<"\nriui> sorry i cant understand what you are saying\n"<<endl;

    }
    else
    debug_func();
    return 0;
}
