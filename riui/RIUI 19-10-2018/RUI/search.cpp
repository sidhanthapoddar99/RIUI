#include <windows.h>
#include <iostream>
using namespace std;
void searchh(char a[150])
{
    char b[300]="https://www.google.co.in/search?q=";
    int j=strlen(b);
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]==' ')
        b[j]='+';
        else
        b[j]=a[i];
        j++;
    }
    cout<<endl;
  //system ("start C:\Program Files (x86)\Google\Chrome\Application\chrome.exe https://www.stackoverflow.com"); //for opening stackoverflow through google chrome , if chorme.exe is in that folder..
  ShellExecute(NULL, "open",b, NULL, NULL, SW_SHOWDEFAULT);
  //ShellExecute(0, 0, "http://cpp.sh", 0, 0 , SW_SHOW );
//  return 0;
}
