#include "Course.hpp"

using namespace std;
/**
 * Only commented the methods that I made.
 * @param title
 * @param day
 * @param start_time
 * @param finish_time
 */
Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

/**
 * Assign the passed in course object.
 * @param m
 * @return
 */
Course & Course::operator =(const Course & m) {
    //TODO implement the operator
    title = m.title; day = m.day; start_time = m.start_time; finish_time = m.finish_time;
    return *this;
}

/**
 * Compare the schedule of two courses.
 * It will return true of the course duration time is overlapping even for a minute.
 * @param m
 * @return boolean
 */
bool Course::operator == (const Course & m) const {
    //TODO implement the operator
    return ((day == m.day && start_time == m.start_time && finish_time == m.finish_time)
    || (day == m.day && finish_time > m.start_time && start_time < m.finish_time));
}

/**
 * Compare the course object by time and day.
 * Start from Monday to Sunday
 * from 0000 to 2359
 * @param m
 * @return boolean
 */
bool Course::operator < (const Course & m) const
{
    //TODO implement the operator
    if (day == m.day) {
        if (start_time == m.start_time)
            return (finish_time < m.finish_time);
        return (start_time < m.start_time);
    }
    return (day < m.day);
}

/**
 * Stream the course object.
 * Change the enum day to readable text.
 * @param os
 * @param m
 * @return ostream
 */
ostream & operator << (ostream &os, const Course & m)
{
    //TODO implement the operator
    string day = "";
    switch(m.day) {
        case 0 : day = "M";
            break;
        case 1 : day = "T";
            break;
        case 2 : day = "W";
            break;
        case 3 : day = "R";
            break;
        case 4 : day = "F";
            break;
        case 5 : day = "S";
            break;
        case 6 : day = "S";
            break;
    }
    os<<m.title<<" "<< day<<" "<<m.start_time<<" "<<m.finish_time;
    return os;
}