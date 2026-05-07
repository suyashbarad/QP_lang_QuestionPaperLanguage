#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream file("sample.qp");
    if(!file){
        cout<<"Error opening file! ";
        return 1;
    }
    string line;
    while(getline(file, line)){
        //.find() and string::npos finds the line with given start
        if(line.find("\\question") != string::npos){
            cout<<"question Line found: \n"<<line<<endl;
        }
        if(line.find("\\marks") != string::npos){
            cout<<"marks Line found: \n"<<line<<endl;
        }
        if(line.find("\\format") != string::npos){
            cout<<"format Line found: \n"<<line<<endl;
        }
        if(line.find("\\difficulty") != string::npos){
            cout<<"difficulty Line found: \n"<<line<<endl;
        }
        if(line.find("\\options") != string::npos){
            cout<<"options Line found: \n"<<line<<endl;
        }

    }
    file.close();
    return 0;
}
