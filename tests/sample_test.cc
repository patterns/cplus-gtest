#include <gtest/gtest.h>
#include "housing.h"

// Sample cases
TEST(HousingTest, 25year_senior_probation ) {
   Housing h = Housing();

   // a 25 year old senior on academic probation
   h.ClassYear(CLASS_SENIOR);
   h.Age(25);
   h.Probation(INPUT_YES);
   EXPECT_EQ(h.Points(), 4+1+0-1-0-0);
}

TEST(HousingTest, 22year_junior_student_teacher) {
   Housing h = Housing();

   // a 22 year old junior who is a student teacher
   h.ClassYear(CLASS_JUNIOR);
   h.Age(22);
   h.FullTime(INPUT_YES);
   EXPECT_EQ(h.Points(), 3+0+1-0-0-0);
}

TEST(HousingTest, 20year_sophomore_disciplined) {
   Housing h = Housing();

   // a 20 year old sophomore on disciplinary probation
   h.ClassYear(CLASS_SOPHOMORE);
   h.Age(20);
   h.Disciplined(INPUT_YES);
   EXPECT_EQ(h.Points(), 2+0+0-0-0-3);
}

