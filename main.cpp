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
    string answer;
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
    cout<<"----------------------------------------------\n";
    cout<<"                Question Paper                \n";
    cout<<"----------------------------------------------\n\n";

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
            string optLine;
            string allOpt = "";
            while(getline(file, optLine)){
                if(optLine.find("}")){
                    break;
                }
                allOpt += optLine + "\n";
            }
            curr.options = allOpt;
        }
        else if(line.find("\\answer") != string::npos){
            curr.answer = extractLine(line);
        }
        // cout<<endl;
    }
    if(curr.que != ""){
        questions.push_back(curr);
    }
    for(int i = 0; i < questions.size(); i++){
        cout<<"Q"<<i+1<<". "<<questions[i].que
        <<" ("<<questions[i].marks<<" marks)"<<endl<<endl;

        if(questions[i].format == "MCQ"){
            cout<<questions[i].options<<endl;
        }
    }
    cout<<"----------------------------------------------\n";
    cout<<"                  Answer Key                  \n";
    cout<<"----------------------------------------------\n\n";

    for(int i = 0; i < questions.size(); i++){
        if(questions[i].format == "MCQ") {
            cout<<"Q"<<i+1<<": "<<questions[i].answer<<endl;
        }
    }
    //optional if want to print these details: 
    // for(int i = 0; i < questions.size(); i++){
    //     cout<<"Options: "<<questions[i].options<<endl<<
    //     "Difficulty: "<<questions[i].difficulty<<"   Format: "    
    //     <<questions[i].format<<endl<<endl;
    // }
    cout<<"Number of questions: "<<questions.size();
    file.close();
    return 0;
}
