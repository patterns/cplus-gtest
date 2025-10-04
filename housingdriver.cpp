// housingdriver.cpp; Hsin-ih Tu; 2025.10.01;
// main program to exercise the housing points object

#include <iostream>

#include "housing.h"

// Sanity check for yes/no user input.
int KnownYN(std::string input) {
   if (input.size() < 1) {
      return INPUT_INVALID;
   }

   if (input == "Y" || input == "y" || input == "Yes" || input == "yes" || input == "YES") {
      return INPUT_YES;
   }

   if (input == "N" || input == "n" || input == "No" || input == "no" || input == "NO") {
      return INPUT_NO;
   }

   return INPUT_INVALID;
}

// Read yes/no user input with retries.
int ReadYN(std::string prompt) {
   int yn = INPUT_INVALID;
   std::string input;

   for (int retry = MAX_RETRY; retry > 0 && yn == INPUT_INVALID; retry--) {
      std::cout << prompt << std::endl;
      std::cin >> input;

      yn = KnownYN(input);

      if (yn == INPUT_INVALID) {
         std::cout << "Sorry, unknown option. Please type a choice from the list.\n";
      }
   }

   return yn;
}

// Sanity check on numeric user input.
int KnownNum(std::string input) {
   int num;

   // only permit numbers with 2-3 digits
   if (input.size() < 2 || input.size() > 3) {
      return INPUT_INVALID;
   }

   try {
      // conversion can cause 2 exceptions
      // (we already restricted values at 3 digits)
      num = std::stoi(input);
   } catch (const std::invalid_argument& e) {
      num = INPUT_INVALID;
   }

   // for student age, not practical for someone to be older than hundred
   if (num > 100) {
      return INPUT_INVALID;
   }

   return num;
}

// Read numeric input with retries.
int ReadNum(std::string prompt) {
   int yn = INPUT_INVALID;
   std::string input;

   for (int retry = MAX_RETRY; retry > 0 && yn == INPUT_INVALID; retry--) {
      std::cout << prompt << std::endl;
      std::cin >> input;

      yn = KnownNum(input);

      if (yn == INPUT_INVALID) {
         std::cout << "Sorry, invalid number. Please type a number 10-100.\n";
      }
   }

   return yn;
}

// Read class user input with retries.
int ReadClass(Housing h) {
   int classyr = INPUT_INVALID;
   std::string input;

   for (int retry = MAX_RETRY; retry > 0 && classyr == INPUT_INVALID; retry--) {
      std::cout << "What class year are you? (Fr, So, Jr, Sr)" << std::endl;
      std::cin >> input;

      classyr = h.KnownClassYear(input);

      if (classyr == INPUT_INVALID) {
         std::cout << "Sorry, unknown class. Please type a class from the list.\n";
      }
   }

   return classyr;
}

// Accept user input and calculate housing points.
int main() {
   std::string input;
   int sanitized = INPUT_INVALID;
   Housing housing = Housing();

   sanitized = ReadClass(housing);

   if (sanitized == INPUT_INVALID) {
      std::cout << "Maximum attempts exhausted. Exiting program." << std::endl;
      return 1;
   }

   housing.ClassYear(sanitized);

   sanitized = ReadNum("How old are you?");

   if (sanitized == INPUT_INVALID) {
      std::cout << "Maximum attempts exhausted. Exiting program." << std::endl;
      return 1;
   }

   housing.Age(sanitized);

   sanitized = ReadYN("Do you work full-time? (y/N)");

   if (sanitized == INPUT_INVALID) {
      std::cout << "Maximum attempts exhausted. Exiting program." << std::endl;
      return 1;
   }

   housing.FullTime(sanitized);

   sanitized = ReadYN("Are you in Academic Probation? (y/N)");

   if (sanitized == INPUT_INVALID) {
      std::cout << "Maximum attempts exhausted. Exiting program." << std::endl;
      return 1;
   }

   housing.Probation(sanitized);

   sanitized = ReadYN("Are you in Possible Academic Suspension? (y/N)");

   if (sanitized == INPUT_INVALID) {
      std::cout << "Maximum attempts exhausted. Exiting program." << std::endl;
      return 1;
   }

   housing.Suspended(sanitized);

   // pretend that freshman can't have disciplinary probation
   // as the conditional branch
   if (housing.ClassYearVal() != 1) {
      sanitized = ReadYN("Have you been in Disciplinary Probation during the year? (y/N)");

      if (sanitized == INPUT_INVALID) {
         std::cout << "Maximum attempts exhausted. Exiting program." << std::endl;
         return 1;
      }

      housing.Disciplined(sanitized);
   }

   std::cout << "You have " << housing.Points() << " housing points." << std::endl;
   std::cout << "(" << housing.ClassYearVal() << " + " << housing.AgeVal() << " + "
             << housing.FullTimeVal() << " + " << housing.ProbationVal() << " + "
             << housing.SuspendedVal() << " + " << housing.DisciplinedVal() << ")" << std::endl;

   return 0;
}
