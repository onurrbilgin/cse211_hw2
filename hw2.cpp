#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// TODO: check whether its just two sets if not take all sets -> fileInput()

using namespace std;

const vector <vector <string>> fileInput(const string &file_name);      // tbc
void functionType(const vector<string> &A, const vector<string> &B);    // tbc
void printTwoSets(const vector<string> &A, const vector<string> &B);    // tbi: can be turned into printing as many as sets input wishes with 2d vector of string (sets) vector

bool isFunction(const vector<string> &A, const vector<string> &B);      // done
bool checkOnto(const vector<string> &A, const vector<string> &B);       // done
bool checkOneToOne(const vector<string> &A, const vector<string> &B);   // done

const vector <vector <string>> fileInput(const string &file_name){

    string line;
    ifstream fileIn;
    vector <string> A, B, C, D;
    vector <vector <string>> sets;

    //  C.push_back("");    // tbi: whether we need more than one set or not; come back to it later
    //  D.push_back("");

    fileIn.open(file_name);
    
    getline(fileIn, line);  // skip a line to read elements of set A

    if(line == "A"){

        cout << "Set A elements:" << endl;
        while(getline(fileIn, line)){
            if(line == "B")
                break;    
            A.push_back(line);
        }
    }
    
    if(line == "B"){

        cout << "Set B elements:" << endl;
        while(getline(fileIn, line)){
            if(line == "C")
                break;        
            B.push_back(line);
        }
    }
    
    if(line == "C"){

        cout << "Set C elements:" << endl;
        while(getline(fileIn, line)){
            if(line == "D")
                break;
            C.push_back(line);
        }
    }
    
    if(line == "D"){

        cout << "Set D elements:" << endl;
        while(getline(fileIn, line))
            D.push_back(line);
     }

    sets.push_back(A);  sets.push_back(B);  sets.push_back(C);  sets.push_back(D);
    return sets;
}

void functionType(const vector<string> &A, const vector<string> &B){    // done

    if(isFunction(A, B)){

        if(checkOnto(A, B) && checkOneToOne(A, B))
            cout << "bijection";
        else if(!checkOnto(A, B) && checkOneToOne(A, B))
            cout << "one-to-one but not onto";
        else if(checkOnto(A, B) && !checkOneToOne(A, B))
            cout << "onto but not one-to-one";
        else if(!checkOnto(A, B) && !checkOneToOne(A, B))
            cout << "neither onto nor one-to-one";
        
    }else
        cout << "not a function";

    return;
}

bool isFunction(const vector<string> &A, const vector<string> &B){      // done

    if(A.size() > B.size())
        return false;
    else{
        for(int i = 0; i < A.size(); ++i){
            for(int j = i + 1; j < A.size(); j++){
                if(A.at(i) == A.at(j))
                    return false;
            }
        }
    }

    return true;
}

bool checkOnto(const vector<string> &A, const vector<string> &B){       // done

    if(A.size() <= B.size())
        return false;
    return true;
}

bool checkOneToOne(const vector<string> &A, const vector<string> &B){   // done

    for(int i = 0; i < A.size(); ++i){
            for(int j = i + 1; j < A.size(); j++){
                if(B.at(i) == B.at(j))
                    return false;
            }
        }

    return true;
}

void printTwoSets(const vector<string> &A, const vector<string> &B){

    cout << A.at(0);
    for(int i = 0; i < A.size(); ++i){
        for(int j = i + 1; j < A.size(); ++j){  // bakacaz ve test edecez
            if(A.at(i) != A.at(j))
                cout << A.at(j) << endl;
        }
    }
}

int main(int argc, char *argv[]){

    vector <vector <string>> sets;
    sets = fileInput(argv[1]);
    printTwoSets(sets.at(0), sets.at(1));

    cout << "Problem 1: ";
    functionType(sets.at(0), sets.at(1));   // call for Problem 1
    cout << "Problem 2: ";
    functionType(sets.at(1), sets.at(0));   // call for Problem 2
    
    return 0;
}

