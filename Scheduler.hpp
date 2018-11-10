//
// Created by dldms on 11/9/2018.
#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Course.hpp"
#ifndef LAB7_SCHEDULER_HPP
#define LAB7_SCHEDULER_HPP
class Scheduler {
//private:
    //vector<Course> list;
public:
    vector<Course> readList();
    void overlapSearch(vector<Course> v);

};
#endif //LAB7_SCHEDULER_HPP
