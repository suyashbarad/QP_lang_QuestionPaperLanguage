#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string extractLine(string line){
    int start = line.find("{");
    int end = line.find("}");
    return line.substr(start + 1, end-start-1);
}

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
            string question = extractLine(line);
            cout<<"Question: "<<question<<endl;
        }
        if(line.find("\\marks") != string::npos){
            string marks = extractLine(line);
            cout<<"Marks: "<<marks<<endl;
        }
        if(line.find("\\format") != string::npos){
            string format = extractLine(line);
            cout<<"Format: "<<format<<endl;
        }
        if(line.find("\\difficulty") != string::npos){
            string difficulty = extractLine(line);
            cout<<"Difficulty: "<<difficulty<<endl;
        }
        if(line.find("\\options") != string::npos){
            string options = extractLine(line);
            cout<<"Options: "<<options<<endl<<endl;
        }
        // cout<<endl;
    }
    file.close();
    return 0;
}
