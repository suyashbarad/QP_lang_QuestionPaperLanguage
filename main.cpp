#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Question{
    string que;
    string marks;
    string format;
    string difficulty;
    string options;
};

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
    Question curr;
    string line;
    while(getline(file, line)){
        //.find() and string::npos finds the line with given start
        if(line.find("\\question") != string::npos){
            if(curr.que != ""){
                cout<<"Question: "<<curr.que<<endl;
                cout<<"Marks: "<<curr.marks<<endl;
                cout<<"Format: "<<curr.format<<endl;
                cout<<"Difficulty: "<<curr.difficulty<<endl;
                cout<<"Options: "<<curr.options<<endl<<endl;
            }
            curr = Question();
            curr.que = extractLine(line);
        }
        else if(line.find("\\marks") != string::npos){
            curr.marks = extractLine(line);
        }
        else if(line.find("\\format") != string::npos){
            curr.format = extractLine(line);
        }
        else if(line.find("\\difficulty") != string::npos){
            curr.difficulty = extractLine(line);
        }
        if(line.find("\\options") != string::npos){
            curr.options = extractLine(line);
        }
        // cout<<endl;
    }
    if(curr.que != ""){
        cout<<"Question: "<<curr.que<<endl;
        cout<<"Marks: "<<curr.marks<<endl;
        cout<<"Format: "<<curr.format<<endl;
        cout<<"Difficulty"<<curr.difficulty<<endl;
        cout<<"Options"<<curr.options<<endl<<endl;
    }
    file.close();
    return 0;
}
