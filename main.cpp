#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Scheduler.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule()
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
}

int main () {
    Scheduler s;
    vector<Course> v = s.readList();
    s.overlapSearch(v);
    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}