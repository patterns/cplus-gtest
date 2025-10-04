// housing.h; Hsin-ih Tu; 2025.10.01;
// housing lottery calculation

#ifndef HOUSING_H
#define HOUSING_H

#include <string>

const int INPUT_YES = 1;        // yes as a numeric value
const int INPUT_NO = 0;         // no as a numeric value
const int INPUT_INVALID = -99;  // user input invalid
const int MAX_RETRY = 3;        // retry attempts allowed
const int MAX_CLASSYR = 4;      // list size of class year
const char CLASS_YEAR[][10] = {"FR", "SO", "JR", "SR"};
const int CLASS_SENIOR = 4;
const int CLASS_JUNIOR = 3;
const int CLASS_SOPHOMORE = 2;
const int CLASS_FRESHMAN = 1;

//---------------------------------------------------------------------------
// Housing:  the set of fields used in assigning housing points
//    for the lottery.
//
// Implementation and assumptions:
//   -- with 23plus, age that is under 23 yr is true otherwise false

class Housing {
public:
   Housing();
   int Points();                     // calculate housing points
   int KnownClassYear(std::string);  // validate input against known class years
   void ClassYear(std::string);      // setter for class year
   void ClassYear(int);              // setter for class year w known value
   int ClassYearVal();               // getter for class year
   void Age(int);                    // setter for 23plus
   int AgeVal();                     // getter for 23plus
   void FullTime(int);               // setter for full-time
   int FullTimeVal();                // getter for full-time
   void Probation(int);              // setter for probation
   int ProbationVal();               // getter for probation
   void Suspended(int);              // setter for suspended
   int SuspendedVal();               // getter for suspended
   void Disciplined(int);            // setter for disciplined
   int DisciplinedVal();             // getter for disciplined

private:
   int age_;       // students are grouped by 23plus or younger
   int year_;      // class year of student
   int fulltime_;  // full-time off campus program participant
   int probation_;
   int suspended_;
   int disciplined_;
};

#endif
