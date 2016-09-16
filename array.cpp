#include <iostream>
using namespace std;
int main(){
int array[2][2]={1,2,3,4};
cout<<"c="<<sizeof(array[0])/sizeof(array[0][0]);
cout<<"r="<<sizeof(array)/sizeof(array[0]);
return 0;
}
