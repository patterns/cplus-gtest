#include <gtest/gtest.h>
#include "housing.h"

TEST(HousingTest, 55year_senior) {
   Housing h = Housing();

   // a 55 year old senior
   h.ClassYear(CLASS_SENIOR);
   h.Age(55);

   int agePt = std::max(0,(55-23)/2); 
   EXPECT_EQ(h.Points(), 4+ agePt +0-0-0-0);
}

TEST(HousingTest, 10year_freshman) {
   Housing h = Housing();

   // a 10 year old freshman
   h.ClassYear(CLASS_FRESHMAN);
   h.Age(10);

   EXPECT_EQ(h.Points(), 1+0+0-0-0-0);
}

TEST(HousingTest, 23year_sophomore) {
   Housing h = Housing();

   // a 23 year old sophomore 
   h.ClassYear(CLASS_SOPHOMORE);
   h.Age(23);

   EXPECT_EQ(h.Points(), 2+0+0-0-0-0);
}

TEST(HousingTest, 23year_junior_disciplined) {
   Housing h = Housing();

   // a 23 year old junior w disciplinary probation
   h.ClassYear(CLASS_JUNIOR);
   h.Age(23);
   h.Disciplined(INPUT_YES);

   EXPECT_EQ(h.Points(), 3+0+0-0-0-3);
}

TEST(HousingTest, 23year_junior_suspended) {
   Housing h = Housing();

   // a 23 year old junior w possible suspension
   h.ClassYear(CLASS_JUNIOR);
   h.Age(23);
   h.Suspended(INPUT_YES);

   EXPECT_EQ(h.Points(), 3+0+0-0-2-0);
}

TEST(HousingTest, 23year_junior_probation) {
   Housing h = Housing();

   // a 23 year old junior w academic probation
   h.ClassYear(CLASS_JUNIOR);
   h.Age(23);
   h.Probation(INPUT_YES);

   EXPECT_EQ(h.Points(), 3+0+0-1-0-0);
}

TEST(HousingTest, 23year_junior_student_teacher) {
   Housing h = Housing();

   // a 23 year old junior student teacher
   h.ClassYear(CLASS_JUNIOR);
   h.Age(23);
   h.FullTime(INPUT_YES);

   EXPECT_EQ(h.Points(), 3+0+1-0-0-0);
}

TEST(HousingTest, 23year_junior_all) {
   Housing h = Housing();

   // a 23 year old junior w all attributes
   h.ClassYear(CLASS_JUNIOR);
   h.Age(23);
   h.FullTime(INPUT_YES);
   h.Probation(INPUT_YES);
   h.Suspended(INPUT_YES);
   h.Disciplined(INPUT_YES);

   EXPECT_EQ(h.Points(), 3+0+1-1-2-3);
}


