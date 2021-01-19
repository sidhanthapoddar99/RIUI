#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
class data{
    public:
      char input[150];
      char output[150];
      int it;};

void help(char a[150]){


    char b[150];
    int n=0;
    sscanf(a,"%s%d",&b,&n);


    if(strcmp(b,"commands")==0)
    {
            ifstream file;
            file.open("data.txt", ios::in|ios::app|ios::binary);
            data c;
            while(!file.eof()){
            file.read((char*)&c,sizeof(c));
            if(c.it==n)
            cout<<"input: "<<c.input<<endl<<"output:"<<c.output<<endl<<n<<endl<<endl;
    }
    }
    else
    {
        ifstream file("help.dat",ios::in|ios::app|ios::binary);
        while(!file.eof())
        {
            string g;
            getline(file,g);
            cout<<g<<endl;
        }
    }
}
