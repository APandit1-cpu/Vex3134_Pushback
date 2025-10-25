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

/**
 * The expected behavior is to return to the start position.
 */

// write auton code here. only use driver test for now.
void frontRR(){ 
  chassis.set_heading(0);
Intake.spin(reverse, 100, percent);
chassis.drive_max_voltage = 8;
chassis.drive_distance(38);
wait(2, sec);
chassis.drive_distance(-12);
wait(20, msec);

Intake.stop();
chassis.turn_to_angle(-66);
wait(100, msec);
chassis.drive_max_voltage = 12;
chassis.drive_distance(15);
Intake.spin(forward, 40, percent);
wait(3, sec);     

}

void frontL(){
  chassis.set_heading(0);
  Intake1.spin(forward, 100, percent); 
  chassis.drive_max_voltage = 7;
  chassis.drive_distance(32);
  wait(20, msec);
  Intake1.stop();
  chassis.drive_distance(-3);
  wait(20, msec);
  chassis.turn_to_angle(249);
  wait(100, msec);
  chassis.drive_max_voltage = 12;
  wait(1, sec);
  chassis.drive_distance(11);
  Intake1.spin(reverse, 67, percent);
  wait(3, sec);
}

void HighGoalLR();
void HighGoalRR();
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