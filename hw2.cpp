#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// TODO: check whether its just two sets if not take all sets
// TODO: deger kumesi eleman sayisi tanimdan fazlaysa ortenlik biter direkt
// deger kumesi sayisi tanima esitse kesinlikle ortendir; degerdeki bazi elemanlar ayni ise bile
// deger kumesi eleman sayisi tanimdan az ise kesinlikle fonksiyon degildir

using namespace std;

const vector <vector <string>> fileInput(const string &file_name);
// void functionType(const vector<string> &A, const vector<string> &B);
bool checkDuplicate(const vector<string> &set, const string &element);

// tbi
bool isFunction(const vector<string> &A, const vector<string> &B);
bool checkOnto(const vector<string> &A, const vector<string> &B);
bool checkOneToOne(const vector<string> &A, const vector<string> &B);
bool checkBijection(bool onto, bool oneToOne);



const vector <vector <string>> fileInput(const string &file_name){

    int i = 0, j = 0, l = 0, m = 0;  // test

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
    return sets;
}

bool checkDuplicate(const vector<string> &set, const string &element){

    for(int i = 0; i < set.size(); ++i){

        if(set.at(i) == element)
            return false;
    }

    return true;
}

void functionType(const vector<string> &A, const vector<string> &B){

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

}

bool isFunction(const vector<string> &A, const vector<string> &B){

    if(A.size() > B.size())
        return false;
}

bool checkOnto(const vector<string> &A, const vector<string> &B){

    if(A.size() <= B.size())
        return false;
}

bool checkOneToOne(const vector<string> &A, const vector<string> &B){


}

bool checkBijection(bool onto, bool oneToOne){


}

int main(int argc, char *argv[]){

    vector <vector <string>> sets;
    sets = fileInput(argv[1]);

    cout << "Problem 1: ";
    functionType(sets.at(0), sets.at(1));   // call for Problem 1
    cout << "Problem 2: ";
    functionType(sets.at(1), sets.at(0));   // call for Problem 2
    


    return 0;
}

