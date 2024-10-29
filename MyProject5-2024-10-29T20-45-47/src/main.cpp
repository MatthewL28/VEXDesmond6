/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Matthew LaLanne, Anderson Smith                           */
/*    Created:      Wed Oct 23 2024                                           */
/*    Description:  VEX Competition Robot, Desmond 6 team                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/


// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                   
// Claw                 motor         7              
// Drivetrain           drivetrain    3, 2           
// Pully                motor         6              
// Pully2               motor         5              
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"


using namespace vex;


// A global instance of competition
competition Competition;


// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


void pre_auton(void) {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
  Drivetrain.setDriveVelocity(100, percent);
 Drivetrain.setTurnVelocity(80, percent);
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
 //autonomous code
 Drivetrain.setDriveVelocity(100, percent);
 Drivetrain.setTurnVelocity(100, percent);
 Drivetrain.driveFor(forward, 18, inches);
 Drivetrain.turnFor(right, 90, degrees);
 Drivetrain.driveFor(forward, 5, inches);
 Drivetrain.turnFor(left, 180, degrees);
 Drivetrain.setTurnVelocity(80, percent);
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
   if(Controller1.ButtonUp.pressing()) {
     autonomous ();
   }


   if(Controller1.ButtonR1.pressing()) {
     Pully.spin(forward);
     Pully2.spin(forward);
   }
   else if(Controller1.ButtonR2.pressing()) {
     Pully.spin(forward);
     Pully2.spin(forward);
   }


   if(Controller1.ButtonA.pressing()) {
     Claw.spinToPosition(90,degrees);
   }
   else {
     Claw.spinToPosition(0,degrees);
   }


   wait(20, msec); // Sleep the task for a short amount of time to
                   // prevent wasted resources.
 }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
 // Set up callbacks for autonomous and driver control periods.
 Competition.autonomous(autonomous);
 Competition.drivercontrol(usercontrol);


 // Run the pre-autonomous function.
 pre_auton();


 // Prevent main from exiting with an infinite loop.
 while (true) {
   wait(100, msec);
 }
}


