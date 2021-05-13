#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream in1("in1.txt");
    ifstream in2("in2.txt");

    vector<string> programming;
    vector<string> history;

    while (!in1.eof()) {
        string student;
        in1 >> student;
        programming.push_back(student);
    }
    in1.close();

    while (!in2.eof()) {
        string student;
        in2 >> student;
        history.push_back(student);
    }
    in2.close();

    ofstream out("out.txt");
    for(int i = 0; i < programming.size(); i++){
        bool contains = false;
        for(int j = 0; j < history.size(); j++){
            if(programming[i] == history[j]){
                contains = true;
                break;
            }
        }
        if(!contains){
            out << programming[i] << endl;
        }
    }
    out.close();


    return 0;
}
