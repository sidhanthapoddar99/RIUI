#include <iostream>
#include <cstring>
using namespace std;
class table
{
    public:
        int from;
        int to;
        char todo[50];
        void input(int f,int e,char t[50]){
            from=f;
            to=e;
            strcpy(todo,t);
        }
        int check(int f,int e){

        if(f>to||e<from)
            return(1);
        return(0);
        }
        void print(){
        cout<<from<<"\t-\t"<<to<<"\t\t"<<todo<<endl;
        }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
