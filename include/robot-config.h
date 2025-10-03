using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern controller Controller1;

extern motor Left1;
extern motor Left2;
extern motor Left3;
extern motor_group LeftDrive;

extern motor Right1;
extern motor Right2;
extern motor Right3;
extern motor_group RightDrive;

extern motor Intake1;
extern motor Lift;
// extern motor Roller;

extern digital_out MatchLoader;
extern digital_out RampExtension;

extern bool isRunning;
extern bool isLoad;
extern bool isExtension;
extern bool isRamp;

void  vexcodeInit( void );