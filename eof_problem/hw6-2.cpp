#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> svec;
    cout << "please input text:(at most 10 lines): " << endl;

    while(svec.size() < 10) {       
        string sentence;
        getline(cin, sentence);
        transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
        svec.push_back(sentence);
        if(cin.eof())
            break;          
    }

    // I tried to clean up cin here by 
    // cin.ignore() , cin.sync() and cin.clear()
    // none of them work
    string wordToFind;
    cout << "please input the pattern: ";
    cin >> wordToFind; // This line isn't working
                       // If I print out wordToFind, it contains nothing
    transform(wordToFind.begin(), wordToFind.end(), wordToFind.begin(), ::tolower);

    bool isFind = false;
    int whichLine = 1;
    for(vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++, whichLine++) {
        size_t pos = 0;
        while((pos = iter->find(wordToFind, pos)) != string::npos) {
            cout << "Found at" << endl;  
            cout << "Line " << whichLine << " column " << pos++ << endl;
            isFind = true;
        }       
    }
    if(isFind == false)
        cout << wordToFind << " not found"; 

    return 0;
}