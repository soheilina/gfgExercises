#ifndef EXERCISESCLASS_H
#define EXERCISESCLASS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class ExercisesClass
{
public:
    ExercisesClass();
    ~ExercisesClass() = default;

public:
    void ParenthesisChecker(void) const;
};

#endif // EXERCISESCLASS_H
