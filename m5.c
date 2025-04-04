#include <stdio.h>
#include <math.h>


void eulerToQuaternion(double yaw, double pitch, double roll, double *w, double *x, double *y, double *z) {
  
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    
    *w = cr * cp * cy + sr * sp * sy;
    *x = sr * cp * cy - cr * sp * sy;
    *y = cr * sp * cy + sr * cp * sy;
    *z = cr * cp * sy - sr * sp * cy;
}

int main() {
    double yaw, pitch, roll;
    double w, x, y, z;

   
    printf("Enter Yaw (degrees): ");
    scanf("%lf", &yaw);
    printf("Enter Pitch (degrees): ");
    scanf("%lf", &pitch);
    printf("Enter Roll (degrees): ");
    scanf("%lf", &roll);

  
    double pi = 3.141592653589793;
    yaw = yaw * (pi / 180.0);
    pitch = pitch * (pi / 180.0);
    roll = roll * (pi / 180.0);

    
    eulerToQuaternion(yaw, pitch, roll, &w, &x, &y, &z);

        printf("Quaternion: w = %.6lf, x = %.6lf, y = %.6lf, z = %.6lf\n", w, x, y, z);

    return 0;
}