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
        cout<<line<<endl;
    }
    file.close();
    return 0;
}