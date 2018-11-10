//
// Created by dldms on 11/9/2018.
//
#include "Scheduler.hpp"

using namespace std;
vector<Course> Scheduler::readList() {
    //TODO read from courses.txt

    ifstream ifile("../courses.txt", ios::in);

    if (!ifile.is_open()) {
        cerr << "There was a problem opening the input file!\n";
        exit(1);
    }
    vector<Course> v;
    int count = 0;
    string temp = "";
    string title = "";
    Course::dayOfWeek day;
    unsigned int start_time;
    unsigned int finish_time;
    //TODO store data in an STL container
    while (ifile >> temp) {
        if(count == 0) {
            title = temp;
        }
        if(count == 1) {
            char *s = const_cast<char *>(temp.c_str());
            switch(*s) {
                case 'M' : day = Course::MON;
                    break;
                case 'T' : day = Course::TUE;
                    break;
                case 'W' : day = Course::WED;
                    break;
                case 'F' : day = Course::FRI;
                    break;
                case 'S' : day = Course::SAT;
                    break;
            }
        }
        if(count == 2) {
            start_time = stoi(temp);
        }
        if(count == 3) {
            finish_time = stoi(temp);
        }
        count++;
        if (count == 4) {
            Course c(title, day, start_time, finish_time);
            v.push_back(c);
            count = 0;
        }
    }
    sort(v.begin(), v.end());
    return v;
}

void Scheduler::overlapSearch(vector<Course> v) {

    //TODO sort your STL container with the sort algorithm

    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule
//    vector<Course>::iterator i;
//    for (i = v.begin(); i != v.end(); i++){
//        cout<<*i<<endl;
//    }

    for (auto i = 0; i <= v.size(); i++){
        cout<<v[i]<<endl;
    }

}

