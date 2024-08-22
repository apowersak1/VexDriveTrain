/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

bool PistonState = false;
bool leftState = false;
bool rightState = false;
bool wheel = false;
bool intake = false;
bool outtake = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Drivetrain.drive(forward, 150, rpm);
  wait(1250,msec);
  Drivetrain.drive(reverse,200,rpm);
  wait(2250,msec);
  Drivetrain.turn(left, 100, rpm);
  wait (745,msec);
  Drivetrain.drive(forward,100, rpm);
  wait(1500, msec);
  Drivetrain.stop();
 
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

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    //pneumatics
    if (Controller1.ButtonX.pressing()){
      while(Controller1.ButtonX.pressing()){
        wait(10,msec);
      }
      PistonState = !PistonState;
      DigitalOutA.set(PistonState);
      DigitalOutH.set(PistonState);
    }
   if (Controller1.ButtonY.pressing()){
      while(Controller1.ButtonY.pressing()){
        wait(10,msec);
      }
      leftState = !leftState;
      DigitalOutA.set(leftState); 
  }
  if (Controller1.ButtonA.pressing()){
      while(Controller1.ButtonA.pressing()){
        wait(10,msec);
      }
      rightState = !rightState;
      DigitalOutH.set(rightState); 
    }
    bool buttonB = Controller1.ButtonB.pressing();
    if (buttonB && !wheel){
      wheel = true;
      Motor5.setMaxTorque(1, Nm);
      Motor6.setMaxTorque(1, Nm);
      Motor5.setVelocity(135,rpm);
      Motor6.setVelocity(135, rpm);
      Motor5.spin(reverse); 
      Motor6.spin(forward);
    }
    else if (!buttonB){
      wheel = false;
      Motor5.stop();
      Motor6.stop();
     }
    bool lBump = Controller1.ButtonL1.pressing();
    if (lBump){
      while(Controller1.ButtonL1.pressing()){
        wait(10,msec);
      }
      Motor1.spin(reverse); 
      }
    bool RBump = Controller1.ButtonR1.pressing();
    if (RBump){
      while(Controller1.ButtonR1.pressing()){
        wait(10,msec);
      }
      Motor1.spin(forward, 12, volt); 
      }
    bool R2bump = Controller1.ButtonL2.pressing();
    if (R2bump){
      Motor1.stop();
    }
  }
}



//
// Main will set up the competition functions and callbacks.
//
int main() {
// Set up callbacks for autonomouifs and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
   }
}