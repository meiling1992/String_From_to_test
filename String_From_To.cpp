#include "String_From_to_test.h"
int main(){
cout<<"Begin()"<<endl;
string s("1234");
auto temp=String_From<int>(s);
cout<<temp<<endl;
int test_int=123456;
auto temp_n=To_String(test_int);
cout<<temp_n<<endl;
return 0;
}
