//
// Created by dldms on 11/9/2018.
//
#include "Scheduler.hpp"

using namespace std;
/**
 * Read the list, sort the list,
 * return it as vector.
 * @return vector.
 */
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
                case 'R' : day = Course::THUR;
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

/**
 * Current sample data will create 4 schedule conflict.
 * @param v vector passed in.
 */
void Scheduler::overlapSearch(vector<Course>& v) {



    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule

    int conflict = 0;
    vector<Course> overlap;
    cout<<"Schedule"<<endl;
    vector<Course>::iterator i;
    Course temp = *(v.begin());
    cout<<*(v.begin())<<endl;
    for (i = v.begin() + 1; i != v.end(); i++) {
        cout<<*i<<endl;
        if (*i == temp) {
            overlap.push_back(*i);
            overlap.push_back(temp);
            conflict++;
        }
        temp = *i;
    }
    cout<<endl;
    cout<<conflict<<" SCHEDULE CONFLICT"<<endl;
    int c = 0;
    for (i = overlap.begin(); i != overlap.end(); i++){
        if (c % 2 == 0) {
            cout<<endl;
        }
        cout<<*i<<endl;
        c++;
    }
}

