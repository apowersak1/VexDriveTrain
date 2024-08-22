using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor Motor5;
extern motor Motor6;
extern digital_out DigitalOutA;
extern digital_out DigitalOutH;
extern motor Motor4;
extern motor Motor1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );