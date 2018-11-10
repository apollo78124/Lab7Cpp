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

/**
 * Read the textfile and part it to the course object.
 * Calculate the overlapping courses.
 */
class Scheduler {

public:
    /**
     * Read the text and return the sorted vector of course obejects.
     * @return vector.
     */
    vector<Course> readList();

    /**
     * Search for the overlapping courses from the passed in vector.
     * @param v
     */
    void overlapSearch(vector<Course>& v);

};
#endif //LAB7_SCHEDULER_HPP
