#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

controller Controller1 = controller(primary);


digital_out MatchLoader = digital_out(Brain.ThreeWirePort.A);
digital_out Descorer = digital_out(Brain.ThreeWirePort.B);
digital_out MidScorer = digital_out(Brain.ThreeWirePort.C);


bool isDescorer = false;
bool isLoad = false;
bool isMid = false;


