#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <regex>

using namespace std;

int main(int argc, char *argv[])
{
    // 是否匹配整个序列，第一个参数为被匹配的str，第二个参数为regex对象
    cout << regex_match("123", regex("[0-9]+")) << endl;

    // regex搜索
    string str = "subject";
    regex re("(sub)(.*)");
    smatch sm;   // 存放string结果的容器
    regex_match(str, sm, re);

    for(int i = 0; i < sm.size(); ++i)
        cout << sm[i] << " ";
    cout << endl;

    cout <<  "---------[0-9]+-------\n" ;
    // regex搜索多次
    str = "0,1 0,2;0,0 1,0;0,1 1,1;0,2 1,2;1,0 1,1;1,1 1,2;1,1 2,1;1,2 2,2;2,0 2,1";
    re = regex("[0-9]+");
    while(regex_search(str, sm, re)) {
        for(int i = 0; i < sm.size(); ++i)
            cout << sm[i] << " ";
        str = sm.suffix().str();
    }
    cout << endl;

    return 0;
}
