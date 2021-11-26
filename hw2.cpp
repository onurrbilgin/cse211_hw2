#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

const vector <vector <string>> fileInput(const string &file_name);      // tbc
void functionType(const vector<string> &A, const vector<string> &B);    // tbc
void printTwoSets(const vector<string> &A, const vector<string> &B);    // done
void printSets(const vector<vector <string>> &sets);
void checkDuplicate(const vector<string> &set, const string &element);  // done
bool isFunction(const vector<string> &A, const vector<string> &B);      // done
bool checkOnto(const vector<string> &A, const vector<string> &B);       // done
bool checkOneToOne(const vector<string> &A, const vector<string> &B);   // done

const vector <vector <string>> fileInput(const string &file_name){
  
    string line;
    ifstream fileIn;
    vector <string> set;
    vector <vector <string>> sets;

    fileIn.open(file_name);
    fileIn >> line; // start reading elements of set A

    while(fileIn >> line){
        if((line.size() == 1) && (line.at(0) >= 'A') && (line.at(0) <= 'Z') || (fileIn.eof())){
            if(fileIn.eof())
                set.push_back(line);
            sets.push_back(set);
            set.clear();
        }else
            set.push_back(line);
    }

    fileIn.close();
    return sets;
}

void functionType(const vector<string> &A, const vector<string> &B){    // done

    if(isFunction(A, B)){

        if(checkOnto(A, B) && checkOneToOne(A, B))
            cout << "bijection" << endl;
        else if(!checkOnto(A, B) && checkOneToOne(A, B))
            cout << "one-to-one but not onto" << endl;
        else if(checkOnto(A, B) && !checkOneToOne(A, B))
            cout << "onto but not one-to-one" << endl;
        else if(!checkOnto(A, B) && !checkOneToOne(A, B))
            cout << "neither onto nor one-to-one" << endl;
        
    }else
        cout << "not a function" << endl;

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

    if(A.size() < B.size())
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

void checkDuplicate(vector<string> &set, const string &element){

    for(int i = 0; i < set.size(); ++i){

        if(set.at(i) == element)
            return;            
    }

    set.push_back(element);
    return;
}

void printTwoSets(const vector<string> &A, const vector<string> &B){

    vector <string> temp;
    cout << "Set elements:" << endl;
    for(int i = 0; i < A.size(); ++i)
        checkDuplicate(temp, A.at(i));
    for(int i = 0; i < temp.size(); ++i)
        cout << temp.at(i) << endl;
    temp.clear();

    cout << "Set elements:" << endl;
    for(int i = 0; i < B.size(); ++i)
        checkDuplicate(temp, B.at(i));
    for(int i = 0; i < temp.size(); ++i)
        cout << temp.at(i) << endl;

    return;
}

void printSets(const vector<vector <string>> &sets){

    vector <string> temp;
    cout << "Elements of sets in order by the file below" << endl << endl;
    for(int i = 0; i < sets.size(); ++i){

        cout << i + 1 << ". set elements:" << endl;
        for(int j = 0; j < sets.at(i).size(); ++j)
            checkDuplicate(temp, sets.at(i).at(j));
        for(int k = 0; k < temp.size(); ++k)
            cout << temp.at(k) << endl;
        temp.clear();
    }

    return;
}

int main(int argc, char *argv[]){

    vector <vector <string>> sets;
    sets = fileInput(argv[1]);

    //  cout <<  endl << " sets.size() = " << sets.size() << endl << endl;

    if(sets.size() == 2){

        printSets(sets);

        cout << "Problem 1: ";
        functionType(sets.at(0), sets.at(1));   // call for Problem 1
        
        cout << "Problem 2: ";
        if(isFunction(sets.at(0), sets.at(1)) && checkOnto(sets.at(0), sets.at(1)) && checkOneToOne(sets.at(0), sets.at(1)))    // check if A->B is a bijection function
            functionType(sets.at(1), sets.at(0));   // call for Problem 2
        else
            cout << "inverse doesn't exist" << endl;

    }else if(sets.size() > 2){

        cout << "run 3rd problem" << endl;      // run 3rd problem
        printSets(sets);
        for(int i = 0; i < sets.size() - 1; i = i + 2){
            if(!isFunction(sets.at(i), sets.at(i + 1))){
                cout << "Problem 3: not a function" << endl;
                exit(1);
            }
        }

        cout << "Problem 3: ";
        functionType(sets.at(sets.size() - 2), sets.at(sets.size() - 1));
    }
    
    return 0;
}

