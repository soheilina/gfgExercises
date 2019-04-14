#include "exercisesclass.h"

ExercisesClass::ExercisesClass()
{

}

////////////////////////////////
// topic: String, file
////////////////////////////////

void ExercisesClass :: ParenthesisChecker() const{
ifstream inFile;
ofstream outFile;
outFile.open("GfG_ParenthesisChecker.txt");  // TODO: An existing file cannot be opened on qt!
outFile << "6\n/"
           "{([])}\n/"
           "()\n/"
           "([]\n/"
           "}(()){}\n/"
           "(()\n/"
           "))))))/n";
outFile.close();
string inData="";
vector<char> buffer;
inFile.open("GfG_ParenthesisChecker.txt");
if ( inFile.peek() == std::ifstream::traits_type::eof() ){
    cout << "File is empty" << endl;
}
else if(inFile){
    cout << "File opened..." << endl;
}
else {
    cout << "File could not be opend..." << endl;
}


std::getline(inFile,inData);
int count=stoi(inData);

while(count >0){
    std::getline(inFile,inData);
    bool balance = true;
    for(char c : inData){
        if( c=='(' || c=='{' || c=='['){
            buffer.push_back(c); // HINT: instead of vector you could have used stack<T>
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

    }//end of for
    cout << (( buffer.empty() && balance)? "Balanced!" : "Not balanced!") << endl;
    count--;

}//end of while
cout << "END!" ;
inFile.close();
}//end of func

////////////////////////////////
// topic: String, file
// task: Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.
////////////////////////////////
void ExercisesClass :: ReverseWords() const{
    string str = "i.like.this.program.very.much";

    string res="";
    stringstream ss(str);
    char delimeter='.';
    for( string token(""); std::getline(ss, token, delimeter); ){ // alternative: while loop
        res = token + delimeter + res;
    }
    res.erase(res.end()-1);
    cout << res << endl;
}

////////////////////////////////
// topic: array
// task: Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.
////////////////////////////////
void ExercisesClass :: SubArrayGivenSum() const{
    string input = "2\n"\
                   "5 12\n"\
                   "1 2 3 7 5\n"\
                   "10 15\n"\
                   "1 2 3 4 5 6 7 8 9 10\n";
    int numInputs;
    vector<int> arr;
    stringstream ss(input),ssTemp;
    string temp;
    std::getline(ss, temp);
    numInputs = stoi(temp);
    for(int m=0; m < numInputs; m++){
        cout << "Result for the input number " << m+1 << ":" << endl;
        // first line
        getline(ss,temp,' ');
        int len = stoi(temp);
        getline(ss,temp,'\n');
        int sumTotal = stoi(temp);
        // 2nd line
        getline(ss,temp,'\n');
        ssTemp << temp;
        while(getline(ssTemp,temp,' ')){
            arr.push_back(stoi(temp));
        }//while
        int sum = 0;
        bool flag = true;
        for(int i=0; i<len && flag;){
            for(int j=i; j<len && flag; j++){
                sum += arr.at(j);
                if( sum == sumTotal){
                    cout << "startIdx =" << i << ", endIdx =" << j << endl;
                    flag = false;
                    break;
                }
                else if(sum > sumTotal){
                    while(sum > sumTotal && i<=j){
                        //move startIdx
                        sum -= arr.at(i);
                        i++;
                        if(sum==sumTotal){
                            cout << "startIdx =" << i << ", endIdx =" << j << endl;
                            flag = false;
                            break;
                        }
                    }
                }
                else if(j==len-1){
                    i++;
                }
            }
        //i++;
        } // end

    arr.clear();
    ssTemp.clear();
    }//end for

}
