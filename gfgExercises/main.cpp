#include "exercisesclass.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "It is running..." << endl;
    std::unique_ptr<ExercisesClass> uPtrObj = std::make_unique<ExercisesClass>();
    //uPtrObj->ParenthesisChecker();
    //uPtrObj->ReverseWords();
    uPtrObj->SubArrayGivenSum();

    return 0;
}
