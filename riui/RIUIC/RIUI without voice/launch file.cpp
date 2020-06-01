#include <windows.h>
#include <iostream>
using namespace std;
void launch(char a[150])
{
    cout<<endl<<"launched: "<<a<<endl;
  //system ("start C:\Program Files (x86)\Google\Chrome\Application\chrome.exe https://www.stackoverflow.com"); //for opening stackoverflow through google chrome , if chorme.exe is in that folder..
  ShellExecute(NULL, "open",a, NULL, NULL, SW_SHOWDEFAULT);
  //ShellExecute(0, 0, "http://cpp.sh", 0, 0 , SW_SHOW );
//  return 0;
}
