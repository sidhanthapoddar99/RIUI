#include <iostream>
#include<iomanip>
#include <fstream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
int tn;
bool checkn(char np[100])
{


    for(int i=0;i<strlen(np);i++)
    {
        if(isdigit(np[i])==false)
            return(false);
    }
    return(true);
}
class txtline
{
	public:
	txtline(int n,char s[100])
	{
		no=n;
		strcpy(line,s);
		next=NULL;
		prev=NULL;

	}

	char line[100];
	int no;
	txtline *next;
	txtline *prev;
	void print1()
	{
			cout<<no<<"> "<<line<<endl;
			if(next!=NULL)
				next->print1();

		}
	void del(int n)
	{
	    if(no==n)
        {
            prev->next=next;
            if(no!=tn-1)
            next->prev=prev;
        }
        if(no>n)
		no--;
		if(next!=NULL)
		next->del(n);
		}

	void change(int n)
	{
	    //cout<<"pass 1";
	    if(n>no)
            next->change(n);
        else if(n==no){
                char s[100];
                cout<<no<<"> ";
                gets(s);
                strcpy(line,s);
        }

	}
	};


void funcin(txtline **start,txtline **end,char s[100])
{

		//string s;

		//cout<<tn<<"> ";
		//getline(cin,s);
		txtline *node=new txtline(tn,s);
		//node->txtline(tn,s);

		if(*start==NULL)
		{
			*start=node;
			*end=*start;
		}
		else
		{
			//cout<<"check1.1"<<endl;
			//txtline *no=new txtline(tn,s);
			(*end)->next = node;
			//(*start)->prev=node;
			node->prev=*end;
			*end=node;
		}
		++tn;

}



void function(txtline *start,txtline *end)
{

		char  s[100];
		while(1==1 ){
		cout<<tn<<"> ";
		gets(s);
		//s=s.trim();
		int flag=1;
		//char ss[100]=s;
		char sp[100];
		char np[100];
		sscanf(s,"%s%s", &sp,&np);

		//delete checking
		if((strcmp(sp,"d")==0) &&checkn(np))
        {
            int no;

            sscanf(np,"%d",&no);
            if(no<=tn)
            {
                if(no==1)//debug friends help
                {
                    txtline **start1=(&start);
                    (*start1)=((start->next));
                    start->prev=NULL;

                }
                start->del(no);
            }
                flag=0;
                tn--;
        }

        //change
        if((strcmp(sp,"l")==0) &&checkn(np))
        {
            int no;

            sscanf(np,"%d",&no);
            //cout<<"check 0"<<no;
            if(no<=tn)
            {
                //cout<<"check 1";
                /*if(no==1)
                {
                    &strat=&(start->next);
                    start->prev=NULL;

                }*/
                start->change(no);
            }
                flag=0;
                //tn--;
        }

		if (flag==1)
            {
                if(strcmp("L",s)==0)
                {
                    system("CLS");
                    start->print1();
                }
                else if(strcmp("E",s)==0)
                break;
                else
                funcin(&start,&end,s);
                }

            }
}

int main()
{
txtline *start=NULL,*end=NULL;
tn=1;
function(start,end);
/*funcin(&start,&end);
cout<<"check1"<<endl;
funcin(&start,&end);
cout<<"check2"<<endl;
funcin(&start,&end);
system("CLS");
start->print1();
*/return 0;

}





