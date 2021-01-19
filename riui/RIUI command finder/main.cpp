#include <iostream>
#include<fstream>
using namespace std;
class data{
    public:
      char input[150];
      char output[150];
      int it;
      void output1()
        {
            cout<<"your output are"<<endl;
            cout<<input<<endl<<output<<endl<<it<<endl<<endl;
        }
      };
int main()
{
    cout << "enter x:" << endl;
    int x;
    cin>>x;

    ifstream file;
    file.open("data.txt", ios::in|ios::app|ios::binary);
    data a;
    while(!file.eof())
        {
                   // cout<<"check1";
            file.read((char*)&a,sizeof(a));
            int n=a.it;
            if(x==n)
            {

                a.output1();


            }

    }
        file.close();
    cin>>x;
        return 0;
}
