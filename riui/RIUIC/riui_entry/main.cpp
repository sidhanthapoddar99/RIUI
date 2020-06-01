#include <iostream>
#include<iomanip>
#include <fstream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
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
          if(it==1)
          	if(strcmp(a,input)==0){
          		return 1;
          }
          if(strlen(a)>strlen(input)){
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
//add time-date function
//add calculate function
//import different cpp files
//add editors mode
//add help
//discussion functions
//add bye function
//add games(if possible)
//add 'add' functions
int main()
{
    //ofstream file;
   // file.open("data.txt", ios::out|ios::app|ios::binary);
    //ifstream ffile("data.txt", ios::in|ios::app|ios::binary);
    int i=0;
     data a;
    while(i!=-1)
    {

    a.t_input();
    //cout<<"\n\nenter your options:  ";
    //cin>>i;
    //if(i!=2)
      //  file.write((char*)&a,sizeof(a));
    }
}
