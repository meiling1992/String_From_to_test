#include<iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>
#define MIN_TWO(X,Y) X<Y?X:Y
#define MIN_THREE(X,Y,Z) X<Y?X:Y<Z?X:Z
using namespace std;
int main(){
    list<string> str_list;
    str_list.push_back("Mei ling");
    str_list.push_front("Nan chang");
    str_list.push_front("Chinese");
    list<string>::const_iterator it = str_list.begin();
    for (; it != str_list.end(); ++it)
        cout << *it << endl;
    cout << "reverse" << endl;
    str_list.reverse();
    list<string>::const_iterator reverse_it = str_list.begin();
    for (; reverse_it != str_list.end(); ++reverse_it)
        cout << *reverse_it << endl;
    cout << "rbegin" << endl;
    str_list.reverse();
    list<string>::const_reverse_iterator reverse_it_rbegin = str_list.rbegin();
    for (; reverse_it_rbegin!= str_list.rend(); ++reverse_it_rbegin)
        cout << *reverse_it_rbegin << endl;
    list<int>::size_type size=str_list.size();
    cout << "num--------->merge_test--------->" << endl;
/*
    list<int> c1, c2, c3;
    c1.push_back(2); c1.push_back(5); c1.push_back(7); 
    c2.push_back(3); c2.push_back(1); c2.push_back(6);
    c3.push_back(4); c3.push_back(2); c3.push_back(8);
    list<int>::iterator it_c1 = c1.begin(), it_c2 = c2.begin(), it_c3 = c3.begin();
    cout << "c1=";
    for (; it_c1 != c1.end(); ++it_c1)cout << *it_c1 << " ";
    cout << endl;
    cout << "c2=";
    for (; it_c2 != c2.end(); ++it_c2)cout << *it_c2 << " ";
    cout << endl;
    cout << "c3=";
    for (; it_c3 != c3.end(); ++it_c3)cout << *it_c3 << " ";
    cout << endl;
    c2.merge(c1);
    //c2.sort(greater<int>()); c1.sort(greater<int>());
    list<int>::const_iterator it_c_2 = c2.begin();
    for (; it_c_2 != c2.end(); ++it_c_2)
        cout << *it_c_2 << " ";
    cout << endl; 
    c2.sort(greater<int>());
    list<int>::const_iterator itc_2 = c2.begin();
    for (; itc_2 != c2.end(); ++itc_2)
        cout << *itc_2 << " ";
    cout << endl;
*/
array<int,4> array={1,4,2,3};
list<int> list_array;
vector<int> vector_array;
for(const auto& i:array)//for_each
{
    list_array.push_back(i);
    vector_array.push_back(i);
}
for(const auto& i:vector_array)
cout<<i<<" ";
cout<<endl;
//
cout<<"sort:"<<endl;
sort(vector_array.begin(),vector_array.end(),greater<int>());
cout<<vector_array[0]<<endl;
cout<<"binary_function()<2"<<endl;
auto less_two=count_if(vector_array.begin(),vector_array.end(),std::bind2nd(less_equal<int>(),3));//binary_function//unary_function
cout<<less_two<<endl;
//
cout<<"DP"<<endl;
int test_dp_v[]={1,3,5};
vector<int> vec(11,0);
//auto n=MIN_THREE(1,2,3);
auto function=[](int num,vector<int>& vec){//
    for(int i=1;i<=num;++i)
    {
        if(i==1||i==3||i==5)
        {
            vec[i]=1;
        }
        else if(num>5){
            vec[i]=MIN_THREE(vec[i-1],vec[i-3],vec[i-5])+1;
        }
        else if(num>3){
            vec[i]=MIN_TWO(vec[i-1],vec[i-3])+1;
        }
        else{
            vec[i]=vec[i-1]+1;
        }
    }
    return vec[num];
};
auto  n=function(10,vec);
cout<<n<<endl;
    return 0;
}


