#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const vector <vector <string>> fileInput(const string &file_name);
void functionType(const vector<string> &A, const vector<string> &B);
bool checkDuplicate(const vector<string> &set, const string &element);

const vector <vector <string>> fileInput(const string &file_name){

    int i = 0, j = 0, l = 0, m = 0;  // test

    string line;
    ifstream fileIn;
    vector <string> A, B, C, D;
    vector <vector <string>> sets;

    C.push_back("");    // tbi: whether we need more than one set or not; come back to it later
    D.push_back("");

    fileIn.open(file_name);
    
    getline(fileIn, line);  // skip a line to read elements of set A

    if(line == "A"){

        cout << "Set A elements:" << endl;
        while(getline(fileIn, line)){

            if(line == "B")
                break;

            if(checkDuplicate(A, line)){
                A.push_back(line);
                cout << A.at(i) << endl;
                i++;
            }
        }
    }
    
    if(line == "B"){

        cout << "Set B elements:" << endl;
        while(getline(fileIn, line)){

            if(line == "C")
                break;

            if(checkDuplicate(B, line)){
                B.push_back(line);
                cout << B.at(j) << endl;
                j++;
            }
        }
    }
    
    if(line == "C"){

        cout << "Set C elements:" << endl;
        while(getline(fileIn, line)){

            if(line == "D")
                break;

            if(checkDuplicate(C, line)){
                C.push_back(line);
                cout << C.at(l) << endl;
                l++;
            }
        }
    }
    
    if(line == "D"){

        cout << "Set D elements:" << endl;
        while(getline(fileIn, line)){

            if(checkDuplicate(D, line)){
                D.push_back(line);
                cout << D.at(m) << endl;
                m++;
            }
        }
    }

    sets.push_back(A);  sets.push_back(B);  sets.push_back(C);  sets.push_back(D);
    cout << "end of inputFile function" << endl;

    return sets;
}

void functionType(const vector<string> &A, const vector<string> &B){

    if(A.size() > B.size()){    // check for if function

        cout << "Problem 1: not a function" << endl;
        return;
    }else if(A.size() == B.size()){ // check for bijective

        cout << "Problem 1: bijective" << endl;
        return;
    }else if(A.size() < B.size()){  // check for onto

        cout << "Problem 1: one-to-one but not onto" << endl;
        return;
    }

    // we don't have to check for the conditions like "onto but not one-to-one" and 
    // "neither onto nor one-to-one" since we match set elements in the same row
}

bool checkDuplicate(const vector<string> &set, const string &element){

    for(int i = 0; i < set.size(); ++i){

        if(set.at(i) == element)
            return 0;
    }

    return 1;
}

int main(int argc, char *argv[]){

    vector <vector <string>> sets;
    sets = fileInput(argv[1]);

    functionType(sets.at(0), sets.at(1));



    return 0;
}

