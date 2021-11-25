#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// TODO: check whether its just two sets if not take all sets -> fileInput()
// TODO: redesign fileInput() to read A,B,C... sets as the ascii char number goes up

using namespace std;

const vector <vector <string>> fileInput(const string &file_name);      // tbc
void functionType(const vector<string> &A, const vector<string> &B);    // tbc
void printTwoSets(const vector<string> &A, const vector<string> &B);    // tbi: can be turned into printing as many as sets input wishes with 2d vector of string (sets) vector
void checkDuplicate(const vector<string> &set, const string &element);  // done
bool isFunction(const vector<string> &A, const vector<string> &B);      // done
bool checkOnto(const vector<string> &A, const vector<string> &B);       // done
bool checkOneToOne(const vector<string> &A, const vector<string> &B);   // done

const vector <vector <string>> fileInput(const string &file_name){
  
    string line;
    ifstream fileIn;
    vector <string> A, B, C, D;
    vector <vector <string>> sets;

    fileIn.open(file_name);
    
    cout << "file opened" << endl;

    fileIn >> line;
    cout << line << endl;
    cout << line.length();

    string setCheck;
    int setNameOrder = 65;      // starting with set A which is 65 in ascii
    char setNames = setNameOrder;

    setCheck.assign(1, setNames);

    if(line == setCheck){
        
        setCheck.assign(1, ++setNames);
        while(fileIn >> line){

            cout << line;
            cout << line.length() << endl;

            if(line == setCheck)
                break;
            A.push_back(line);
        }
    }

    if(line == setCheck){
        
        setCheck.assign(1, ++setNames);
        while(fileIn >> line){

            cout << line;
            cout << line.length() << endl;

            if(line == setCheck)
                break;
            B.push_back(line);
        }
    }

    /* FROM HERE if(line == "B"){
        
        while(fileIn >> line){

            cout << line;
            cout << line.length() << endl;

            if(line == "C" || fileIn.eof())
                break;
            B.push_back(line);
        }
    }

    if(line == "C"){
        
        fileIn >> line;
        while(line != "D" && line != ""){

            C.push_back(line);
            fileIn >> line;
        }
    }  EN SON COMMENTE ALINAN*/

    /*if(line == "D"){
        
        fileIn >> line;
        while(line != ""){

            D.push_back(line);
            fileIn >> line;
        }
    }*/
    
    /*if(line == "B"){
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
     }*/

    if(!A.empty())
        sets.push_back(A);
    if(!B.empty())
        sets.push_back(B);
    if(!C.empty())
        sets.push_back(C);
    if(!D.empty())
        sets.push_back(D);

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
    cout << "Set A elements:" << endl;
    for(int i = 0; i < A.size(); ++i)
        checkDuplicate(temp, A.at(i));
    for(int i = 0; i < temp.size(); ++i)
        cout << temp.at(i) << endl;
    temp.clear();

    cout << "Set B elements:" << endl;
    for(int i = 0; i < B.size(); ++i)
        checkDuplicate(temp, B.at(i));
    for(int i = 0; i < temp.size(); ++i)
        cout << temp.at(i) << endl;

    return;
}

int main(int argc, char *argv[]){

    vector <vector <string>> sets;
    sets = fileInput(argv[1]);

    cout << sets.size() << endl;

    if(sets.size() == 2){

        cout << "run 1 & 2nd problems" << endl; // run 1 & 2nd problems
        printTwoSets(sets.at(0), sets.at(1));
        cout << "Problem 1: ";
        functionType(sets.at(0), sets.at(1));   // call for Problem 1
        cout << "Problem 2: ";
        functionType(sets.at(1), sets.at(0));   // call for Problem 2

    }else if(sets.size() > 2){

        cout << "run 3rd problem" << endl;      // run 3rd problem
        for(int i = 0; i < sets.size(); ++i){
            
            if(!isFunction(sets.at(i), sets.at(i + 1)))
                cout << "Problem 3: not a function" << endl;
            break;
        }

        functionType(sets.at(sets.size() - 1), sets.at(sets.size()));
    }
    
    return 0;
}

