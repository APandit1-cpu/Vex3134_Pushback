#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}



void frontL(){
  chassis.set_heading(0);
  chassis.drive_max_voltage = 6;
  Intake2.spin(forward, 100, percent);
  Intake1.spin(reverse, 100, percent);
  chassis.turn_to_angle(-36);
  chassis.drive_distance(29);
  wait(2, msec);
  chassis.drive_distance(-30);
  Intake.stop();
  chassis.turn_to_angle(-90);
  chassis.drive_distance(38);
  Descorer.set(false);
  chassis.turn_to_angle(-180);
  chassis.drive_distance(-10);
  Intake.spin(reverse, 100, percent);
  /*AUTON DESCRIPTION: 
  Picks up 3 corner balls left corner
  , goes to high goal
  , scores 4 balls total*/
 
  
}

void frontR(){ 
  chassis.set_heading(0);
  chassis.drive_max_voltage = 6;
  Intake2.spin(forward, 100, percent);
  Intake1.spin(reverse, 100, percent);
  chassis.turn_to_angle(36);
  chassis.drive_distance(29);
  wait(2, msec);
  chassis.drive_distance(-30);
  Intake.stop();
  chassis.turn_to_angle(90);
  chassis.drive_distance(38);
  Descorer.set(false);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-40);
  Intake.spin(reverse, 100, percent);
  /*AUTON DESCRIPTION:
  Picks up 3 balls right corner
  , goes to high goal
  , scores 4 balls total*/
}


void HighGoalLR(){
  chassis.set_heading(0);
  chassis.drive_max_voltage = 6;
  Intake2.spin(forward, 100, percent);
  Intake1.spin(reverse, 100, percent);
  chassis.turn_to_angle(-36);
  chassis.drive_distance(29);
  wait(2, msec);
  chassis.drive_distance(-30);
  Intake.stop();
  chassis.turn_to_angle(-90);
  chassis.drive_distance(38);
  chassis.turn_to_angle(-180);
  MatchLoader.set(true);
  chassis.drive_distance(19);
  Intake2.spin(forward, 100, percent);
  Intake1.spin(reverse, 100, percent);
  wait(1, sec);
  chassis.drive_distance(-25);
  Descorer.set(false);
  Intake.spin(reverse, 100, percent);
  wait(1, sec);
  chassis.drive_distance(5);
  chassis.turn_to_angle(0);
  chassis.drive_distance(15);
  chassis.turn_to_angle(90);
  Descorer.set(true);
  chassis.drive_distance(15);
  /*AUTON DESCRIPTION:
  Picks up 3 corner left balls
  , goes to matchloader,
  , puts down matchloader and rams matchloader
  , gets 3 balls
  , moves back and scores on high goal
  , 7 balls total if succesful*/
}



// 6-7 ball auton (goes to corner goal, picks up balls, goes to matchloader, matchloads 3 balls, goes to high goal and scores)
void HighGoalRR(){
  chassis.set_heading(0);
  chassis.drive_max_voltage = 6;
  Descorer.set(true);
  Intake.spin(reverse, 75, percent);
  chassis.turn_to_angle(36);
  chassis.drive_distance(29);
  wait(2, msec);
  chassis.drive_distance(-30);
  Intake.stop();
  chassis.turn_to_angle(90);
  chassis.drive_distance(40);
  chassis.turn_to_angle(180);
  MatchLoader.set(true);
  chassis.drive_distance(25);
  Intake2.spin(forward, 100, percent);
  Intake1.spin(reverse, 100, percent);
  wait(1, sec);
  chassis.drive_distance(-40);
  Descorer.set(false);
  Intake.spin(reverse, 100, percent);
  /*AUTON DESCRIPTION:
  Picks up 3 corner right balls
  ,puts down matchloader and rams matchloader
  , gets 3 balls
  , moves back on high goal,
  , scores 7 balls if succesful*/
}

void HighGoalLB();
void HighGoalRB();
void MHighGoalLR();

void drive_test();
void turn_test();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();