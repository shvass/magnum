#ifndef  TRANSLATE_HPP
#define TRANSLATE_HPP

#include <math.h>


// max cords of joystick
#define X_MAX 1.0
#define Y_MAX 1.0

// max speed of wheel 
#define MAX_SPEED 1.0


/**
 * @brief 
 *  calculate wheels speed, for translating the body
 * based on joystick input cords
 * 
 * @param x joystick x cords
 * @param y joystick y cords
 * @param speeds array of speeds for wheels
 *  speeds[0]  ->  A
 *  speeds[1]  ->  B
 *  speeds[2]  ->  C
 *  speeds[3]  ->  D
 */
void translate(float x, float y, float* speeds){
    // normalized coords
    float normCords[] = { x / X_MAX, y / Y_MAX };

    double theta = atan2(normCords[1], normCords[0]);
    theta += M_PI / 4;

    speeds[0] = speeds[2] = MAX_SPEED * sin(theta);
    speeds[1] = speeds[3] = MAX_SPEED * cos(theta);
}


#endif //TRANSLATE_HPP