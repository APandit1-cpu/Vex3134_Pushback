#include "vex.h"

using namespace vex;
competition Competition;

motor Left1 = motor(PORT11,ratio6_1,true); 
motor Left2 = motor(PORT14,ratio6_1,true); 
motor Left3 = motor(PORT15,ratio6_1,true); 
motor_group LeftDrive = motor_group(Left1,Left2,Left3); // Left drivetrain
 
motor Right1 = motor(PORT16,ratio6_1,false); 
motor Right2 = motor(PORT17,ratio6_1,false);  
motor Right3 = motor(PORT20,ratio6_1,false); 
motor_group RightDrive = motor_group(Right1,Right2,Right3); // Right drivetrain

motor Intake1 = motor(PORT9,ratio6_1,false); // Has 2 rubber band rollers, 2 flex wheel rollers
motor Intake2 = motor(PORT10, ratio6_1, false); // Has 3 rubber band rollers
motor_group Intake = motor_group(Intake1, Intake2); // Controls all rubber band rollers, 2 flex wheel rollers
inertial InertialSensor = inertial(PORT12); // Used for auton

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
LeftDrive,

//Right Motors:
RightDrive,

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT12,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(!auto_started){
    // Brain.Screen.clearScreen();
    // Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    // Brain.Screen.printAt(5, 40, "Battery Percentage:");
    // Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    // Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    // Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    // Brain.Screen.printAt(5, 120, "Selected Auton:");
    // switch(current_auton_selection){
    //   case 0:
    //     Brain.Screen.printAt(5, 140, "Auton 1");
    //     break;
    //   case 1:
    //     Brain.Screen.printAt(5, 140, "Auton 2");
    //     break;
    //   case 2:
    //     Brain.Screen.printAt(5, 140, "Auton 3");
    //     break;
    //   case 3:
    //     Brain.Screen.printAt(5, 140, "Auton 4");
    //     break;
    //   case 4:
    //     Brain.Screen.printAt(5, 140, "Auton 5");
    //     break;
    //   case 5:
    //     Brain.Screen.printAt(5, 140, "Auton 6");
    //     break;
    //   case 6:
    //     Brain.Screen.printAt(5, 140, "Auton 7");
    //     break;
    //   case 7:
    //     Brain.Screen.printAt(5, 140, "Auton 8");
    //     break;
    // }
    // if(Brain.Screen.pressing()){
    //   while(Brain.Screen.pressing()) {}
    //   current_auton_selection ++;
    // } else if (current_auton_selection == 8){
    //   current_auton_selection = 0;
    // }
    current_auton_selection = 0;
    task::sleep(10); // ignore this error, its meant to be here, otherwise the brain will malfunction.
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  current_auton_selection = 0;
  switch(current_auton_selection){ 
    case 0:
      drive_test();
      break;
    case 1:         
      drive_test();
      break;
    case 2:
      turn_test();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
// define variables used for controlling motors based on controller inputs
//b bool ClampStatus = false; 



    

    // wait before repeating the process for 20 milliseconds

    



/*void arcadeDrive() {
    int deadband = 5;

    int forward = abs(Controller1.Axis1.value()) > deadband ? Controller1.Axis1.value() : 0; 
    int turning = (abs(Controller1.Axis3.value()) > deadband ? Controller1.Axis3.value() : 0) * 0.9; 

    int left_side = (forward + turning > 100) ? 100 : (forward + turning < -100) ? -100 : (forward + turning);
    int right_side = (forward - turning > 100) ? 100 : (forward - turning < -100) ? -100 : (forward - turning);

    double left_side_volts = 12.0 * (left_side / 100.0);
    double right_side_volts = 12.0 * (right_side / 100.0);

    Left1.spin(reverse, left_side_volts, voltageUnits::volt); // fwd
    Left2.spin(reverse, left_side_volts, voltageUnits::volt);
    Left3.spin(reverse, left_side_volts, voltageUnits::volt);

    Right1.spin(reverse, right_side_volts, voltageUnits::volt);
    Right2.spin(reverse, right_side_volts, voltageUnits::volt);
    Right3.spin(reverse, right_side_volts, voltageUnits::volt);
}
*/
void vexcodeInit( void ) {
 /*  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
  Intake1.setVelocity(100,pct); */
  // Roller.setVelocity(100,pct);

  // Intake3.setVelocity(100,pct);
  // nothing to initialize
}


void usercontrol(void) {
  while (1) {
    // arcadeDrive();  // arcade drive control
    chassis.control_arcade();
    Intake.setVelocity(100,pct);

if (isLoad) {
  MatchLoader.set(true);
} 
else {
  MatchLoader.set(false);
}


if(Controller1.ButtonA.pressing()) {
  isLoad = !isLoad;
  waitUntil(!Controller1.ButtonA.pressing());
}



  if (Controller1.ButtonL1.pressing()) {
    Intake.spin(reverse);
  } else if (Controller1.ButtonL2.pressing()) {
    Intake.spin(forward);
  } else {
    Intake.stop();
  }

}

// prevent CPU overuse
wait(20,msec);
}


int main() {
  // Set up callbacks for autonomous and driver control periods.
  // INITIALIZE THE AUTON YOU WANT HERE: (autons are in autons.cpp)
  Competition.autonomous(drive_test);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
