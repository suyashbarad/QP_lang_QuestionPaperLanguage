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

    ifstream infile("sample.qp");
    ofstream outfile("output.txt");

    if(!infile){
        cout<<"Error opening file! ";
        return 1;
    }
    if(!outfile){
        cout<<"Error opening file! ";
        return 1;
    }
    Question curr;
    string line;
    vector<Question> questions;
    while(getline(infile, line)){
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
            while(getline(infile, optLine)){
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

    cout<<"----------------------------------------------\n";
    cout<<"                Question Paper                \n";
    cout<<"----------------------------------------------\n\n";      //for terminal output


    outfile<<"----------------------------------------------\n";
    outfile<<"                Question Paper                \n";
    outfile<<"----------------------------------------------\n\n";      //for outfile output

    for(int i = 0; i < questions.size(); i++){
        string qline = "Q" + to_string(i+1) + ". " + questions[i].que
        + " (" + questions[i].marks + " marks)\n\n";

        cout<<qline;
        outfile << qline;
        if(questions[i].format == "MCQ"){
            cout<<questions[i].options<<endl;
            outfile<<questions[i].options<<"\n";
        }

    }
    cout<<"----------------------------------------------\n";
    cout<<"                  Answer Key                  \n";
    cout<<"----------------------------------------------\n\n";

    outfile<<"----------------------------------------------\n";
    outfile<<"                  Answer Key                  \n";
    outfile<<"----------------------------------------------\n\n";

    for(int i = 0; i < questions.size(); i++){
        if(questions[i].format == "MCQ") {
            string ansLine = "Q" + to_string(i+1) + ": " + questions[i].answer + "\n";
            cout << ansLine;
            outfile << ansLine;
        }
    }
    //optional if want to print these details: 
    // for(int i = 0; i < questions.size(); i++){
    //     cout<<"Options: "<<questions[i].options<<endl<<
    //     "Difficulty: "<<questions[i].difficulty<<"   Format: "    
    //     <<questions[i].format<<endl<<endl;
    // }
    cout<<"Number of questions: "<<questions.size();
    infile.close();
    outfile.close();

    return 0;
}
