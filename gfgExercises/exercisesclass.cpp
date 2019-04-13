#include "exercisesclass.h"

ExercisesClass::ExercisesClass()
{

}

////////////////////////////////
// topic:
////////////////////////////////

void ExercisesClass :: ParenthesisChecker() const{
ifstream inFile;
ofstream outFile;
outFile.open("GfG_ParenthesisChecker.txt");  // doesn't work!
outFile << "3\n{([])}\n()\n([]\n";
outFile.close();
string inData="";
vector<char> buffer;
inFile.open("GfG_ParenthesisChecker.txt");
if ( inFile.peek() == std::ifstream::traits_type::eof() ){
    cout << "File is empty" << endl;
}
else if(inFile){
    cout << "OK" << endl;
}
else {
    cout << "NOK" << endl;
}
cout << "File opened in read mode." << endl;
std::getline(inFile,inData);
int count=stoi(inData);

while(count >0){
    std::getline(inFile,inData);
    bool balance = true;
    for(char c : inData){
        if( c=='(' || c=='{' || c=='['){
            buffer.push_back(c);
        }
        else if( c==')' ){
                if( !buffer.empty() && buffer.back() == '(' ){
                    buffer.pop_back();
                }
                else{
                    balance = false;
                    break;
                }
        }
        else if( c==']' ){
                if( !buffer.empty() && buffer.back() == '[' ){
                    buffer.pop_back();
                }
                else{
                    balance = false;
                    break;
                }
        }
        else if( c=='}' ){
                if( !buffer.empty() && buffer.back() == '{' ){
                    buffer.pop_back();
                }
                else{
                    balance = false;
                    break;
                }
        }

    }//for
    cout << (( buffer.empty() && balance)? "Balanced!" : "Not balanced!") << endl;
    count--;

}// while
cout << "END!" ;
inFile.close();
}//func
