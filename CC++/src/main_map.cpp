#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <regex>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "----------无情的分割线--------" << endl;
    cout << "          ypb                " << endl;
    cout << "----------无情的copy---------" << endl;

    cout << endl;
    
    // ---------------at---------------------
    // std::map<std::string,int> mymap =
    // {
    //     { "alpha", 0 },
    //     { "beta", 0 },
    //     { "gamma", 0 } 
    // };

    // mymap.at("alpha") = 10;
    // mymap.at("beta") = 20;
    // mymap.at("gamma") = 30;

    // for (auto& x: mymap)
    // {
    //     std::cout << x.first << ": " << x.second << '\n';
    // }

    // ---------------begin---------------------
    // std::map<char,int> mymap;

    // mymap['b'] = 100;
    // mymap['a'] = 200;
    // mymap['c'] = 300;

    // // show content:
    // for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    // --------------cbegin---------------
    // std::map<char,int> mymap;

    // mymap['b'] = 100;
    // mymap['a'] = 200;
    // mymap['c'] = 300;

    // // print content:
    // std::cout << "mymap contains:";
    // for (auto it = mymap.cbegin(); it != mymap.cend(); ++it)
    // std::cout << " [" << (*it).first << ':' << (*it).second << ']';
    // std::cout << '\n';

    //----------(auto& x: mymap)------
      std::map<char,int> mymap;

      mymap.emplace('x',100);
      mymap.emplace('y',200);
      mymap.emplace('z',100);

      std::cout << "mymap contains:";
      for (auto& x: mymap)
        std::cout << " [" << x.first << ':' << x.second << ']';
      std::cout << '\n';

 
    return 0;
}
