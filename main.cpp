#include<iostream>
#include<fstream>
#include<string>
#include<vector>
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
    vector<Question> questions;
    while(getline(file, line)){
        //.find() and string::npos finds the line with given start
        if(line.find("\\question") != string::npos){
            if(curr.que != ""){
                questions.push_back(curr);
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
        else if(line.find("\\options") != string::npos){
            curr.options = extractLine(line);
        }
        // cout<<endl;
    }
    if(curr.que != ""){
        questions.push_back(curr);
    }
    for(int i = 0; i < questions.size(); i++){
        cout<<"Question: "<<questions[i].que<<endl;
        cout<<"Marks: "<<questions[i].marks<<endl;
        cout<<"Format: "<<questions[i].format<<endl;
        cout<<"Difficulty: "<<questions[i].difficulty<<endl;
        cout<<"Options: "<<questions[i].options<<endl<<endl;
    }
    cout<<"Number of questions: "<<questions.size();
    file.close();
    return 0;
}
