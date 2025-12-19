#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

controller Controller1 = controller(primary);

// motor Lift = motor(PORT10,ratio6_1,false);
// motor Roller = motor(PORT16,ratio18_1,false);

digital_out MatchLoader = digital_out(Brain.ThreeWirePort.A);
digital_out Doinker = digital_out(Brain.ThreeWirePort.B);
digital_out MidScorer = digital_out(Brain.ThreeWirePort.B);


bool isDoinker = false;
bool isLoad = false;
bool isMid = false;


