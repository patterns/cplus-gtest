// housing.cpp; Hsin-ih Tu; 2025.10.01;
// a Housing Lottery object 
// 

#include <algorithm>
#include "housing.h"

//----------------------------------------------------------------------------
// Housing Lottery constructor 
// 

Housing::Housing() {
   year_ = 0;
   age_ = 0;
   fulltime_ = 0;
   probation_ = 0;
   suspended_ = 0;
   disciplined_ = 0;
}

int Housing::Points() {
   return ClassYearVal() + AgeVal() + FullTimeVal() + ProbationVal() + SuspendedVal() + DisciplinedVal();
}

// Check that input is a member of the Class Year list.
// (see digitalocean.com/community/tutorials/string-uppercase-lowercase-c-plus-plus)
int Housing::KnownClassYear(std::string input) {
   std::string allcaps = input;

   if (input.size() < 2) {
      return INPUT_INVALID;
   }

   std::transform(allcaps.begin(), allcaps.end(), allcaps.begin(), ::toupper);

   for (int n=0 ; n<MAX_CLASSYR ; n++) {
      if (allcaps.compare(0, 2, CLASS_YEAR[n], 2) == 0) {
         return n+1;
      }
   }

   return INPUT_INVALID;
}

// Assign the class year member field.
// (we assume input has been validated already)
void Housing::ClassYear(std::string input) {
   // very quick & dirty mapping of label to numeric value (instead of enums)
   std::string allcaps = input;
   std::transform(allcaps.begin(), allcaps.end(), allcaps.begin(), ::toupper);

   for (int n=0 ; n<MAX_CLASSYR ; n++) {
      if (allcaps.compare(0, 2, CLASS_YEAR[n], 2) == 0) {
         year_ = n + 1;
         break;
      }
   }
}

void Housing::ClassYear(int val) {
    // if val <1 or >MAX_CLASSYR , uh-oh...
    year_ = val;
}

// getter for class year member field.
int Housing::ClassYearVal() {
   return year_;
}

// setter for 23plus
void Housing::Age(int yesno) {
   if (yesno < 1) {
      // natural number
      age_ = 1;
   } else {
      age_ = yesno;
   }
/*******
   ////if yesno == INPUT_INVALID , uh oh....
   if (yesno == INPUT_YES) {
      age_ = 0;
   } else {
      age_ = 1;
   }******/
}

// getter for age (calculated val).
int Housing::AgeVal() {
   return std::max(0, (age_ - 23)/2);
}

// setter for full-time
void Housing::FullTime(int yesno) {
   ////if yesno == INPUT_INVALID , uh oh....
   if (yesno == INPUT_YES) {
      fulltime_ = 1;
   } else {
      fulltime_ = 0;
   }
}

// getter for full-time.
int Housing::FullTimeVal() {
   return fulltime_;
}

// setter for probation
void Housing::Probation(int yesno) {
   ////if yesno == INPUT_INVALID , uh oh....
   if (yesno == INPUT_YES) {
      probation_ = -1;
   } else {
      probation_ = 0;
   }
}

// getter for probation.
int Housing::ProbationVal() {
   return probation_;
}

// setter for suspended
void Housing::Suspended(int yesno) {
   ////if yesno == INPUT_INVALID , uh oh....
   if (yesno == INPUT_YES) {
      suspended_ = -2;
   } else {
      suspended_ = 0;
   }
}

// getter for suspended.
int Housing::SuspendedVal() {
   return suspended_;
}

// setter for disciplined
void Housing::Disciplined(int yesno) {
   ////if yesno == INPUT_INVALID , uh oh....
   if (yesno == INPUT_YES) {
      disciplined_ = -3;
   } else {
      disciplined_ = 0;
   }
}

// getter for disciplined.
int Housing::DisciplinedVal() {
   return disciplined_;
}

