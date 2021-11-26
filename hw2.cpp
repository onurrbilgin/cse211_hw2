#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

// declarations of functions
const vector <vector <string>> fileInput(const string &file_name);      
void functionType(const vector<string> &A, const vector<string> &B);     
void printSets(const vector<vector <string>> &sets);
void checkDuplicate(const vector<string> &set, const string &element);  
bool isFunction(const vector<string> &A, const vector<string> &B);      
bool checkOnto(const vector<string> &A, const vector<string> &B);       
bool checkOneToOne(const vector<string> &A, const vector<string> &B);   

const vector <vector <string>> fileInput(const string &file_name){  // function for getting input from file
  
    string line;
    ifstream fileIn;
    vector <string> set;
    vector <vector <string>> sets;  // 2d vector of string vectors as sets

    fileIn.open(file_name);
    fileIn >> line; // start reading elements of set A

    // below, start reading
    while(fileIn >> line){
        if((line.size() == 1) && (line.at(0) >= 'A') && (line.at(0) <= 'Z') || (fileIn.eof())){ // basically, if theres a string named between A to Z take it as set
            if(fileIn.eof())                                                                    // and if file is ended just stop reading
                set.push_back(line);
            sets.push_back(set);
            set.clear();
        }else
            set.push_back(line);
    }

    fileIn.close(); // close the file
    return sets;    // return sets
}

void functionType(const vector<string> &A, const vector<string> &B){    // function for deciding function type: onto, one-to-one, bijective etc.
    // calling neccessary functions for if its function, if so is it one-to-one or onto and such
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

bool isFunction(const vector<string> &A, const vector<string> &B){      // function for if given two sets creates a function

    if(A.size() > B.size())     // if first set's size is less than pre-image set's size, not a function
        return false;
    else{ // checking if there are duplicates in first set, not a function
        for(int i = 0; i < A.size(); ++i){
            for(int j = i + 1; j < A.size(); j++){
                if(A.at(i) == A.at(j))
                    return false;
            }
        }
    }

    return true;    // otherwise its a function
}

bool checkOnto(const vector<string> &A, const vector<string> &B){   // checking whether the function is onto or not

    if(A.size() < B.size()) // basically, if pre-image set's size is bigger than first set, not onto
        return false;
    return true;
}

bool checkOneToOne(const vector<string> &A, const vector<string> &B){   // checking whether the function is one-to-one or not
    // here, checking if two different first set elements go to the same element in pre-image set
    for(int i = 0; i < A.size(); ++i){
            for(int j = i + 1; j < A.size(); j++){
                if(B.at(i) == B.at(j))
                    return false;   // if so, not one-to-one
            }
        }

    return true;    // if not, one-to-one
}

void checkDuplicate(vector<string> &set, const string &element){    // helper function to delete duplicate elements in a set

    for(int i = 0; i < set.size(); ++i){    // check the given set and if theres a duplicate element, just return
        if(set.at(i) == element)
            return;            
    }

    set.push_back(element); // if the given element is not duplicate, push it to the vector
    return;
}

void printSets(const vector<vector <string>> &sets){    // function for displaying sets

    vector <string> temp;
    cout << "Elements of sets in order by the file below" << endl << endl;
    for(int i = 0; i < sets.size(); ++i){
        // basically, with the help of a loop, im checking each element of the set and if theres a duplicate i remove it
        //  and print the rest of the set (which has no duplicates anymore)
        cout << "-> " << i + 1 << ". set elements:" << endl;
        for(int j = 0; j < sets.at(i).size(); ++j)
            checkDuplicate(temp, sets.at(i).at(j));
        for(int k = 0; k < temp.size(); ++k)
            cout << temp.at(k) << endl;
        temp.clear();
    }

    return;
}

int main(int argc, char *argv[]){   // driver function for calling neccessary functions

    vector <vector <string>> sets;
    vector <string> temp;
    sets = fileInput(argv[1]);

    if(sets.size() == 2){   // if theres 2 sets, run problem 1 & 2

        printSets(sets);    // display the sets

        cout << "Problem 1: ";
        functionType(sets.at(0), sets.at(1));   // decide the function type
        
        cout << "Problem 2: ";
        if(isFunction(sets.at(0), sets.at(1)) && checkOnto(sets.at(0), sets.at(1)) && checkOneToOne(sets.at(0), sets.at(1)))    // check if A->B is a bijection function
            functionType(sets.at(1), sets.at(0));   // decide the function type
        else
            cout << "inverse doesn't exist" << endl;    // if its not bijection, there can't be inverse of it

    }else if(sets.size() > 2){  // if there are more sets, run problem 3

        cout << "run 3rd problem" << endl;     
        printSets(sets);

        for(int i = 0; i < sets.size() - 1; i = i + 2){ // check consecutive sets, if they don't make a function, composition of functions are not a function
            if(!isFunction(sets.at(i), sets.at(i + 1))){
                cout << "Problem 3: not a function" << endl;
                exit(1);
            }
        }

        for(int i = 0; (i < sets.at(0).size()) && (i < sets.at(sets.size() - 1).size()); ++i)   // matching first set with the last set but new
            temp.push_back(sets.at(sets.size() - 1).at(i));                                     // set can't be greater than the two sets
        
        cout << "Problem 3: ";
        functionType(sets.at(0), temp); // decide type of composition function
    }
    
    return 0;
}

