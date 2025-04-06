#include <stdio.h>
#include <math.h>

// Function to convert marker position based on a correction offset
void convert_marker_position(double x, double y, double z, double correction_offset, 
                             double *x_final, double *y_final, double *z_final) {
    // Calculate the length of the direction vector in the XY plane
    double magnitude = sqrt(x * x + y * y);

    // Avoid division by zero
    if (magnitude == 0) {
        *x_final = x;
        *y_final = y;
    } else {
        // Find unit vector in the same direction as (x, y)
        double unit_x = x / magnitude;
        double unit_y = y / magnitude;

        // Apply the correction offset in the same direction
        *x_final = x + correction_offset * unit_x;
        *y_final = y + correction_offset * unit_y;
    }

    // No change in Z
    *z_final = z;
}

// Function to calculate Euclidean distance between two 3D points
double calculate_distance(double x1, double y1, double z1, 
                          double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + 
                pow(y2 - y1, 2) + 
                pow(z2 - z1, 2));
}

int main() {
    double x, y;
    double z = -60;  // Fixed z-coordinate (marker is 60 cm below camera level)
    double correction_offset = 55;  // Rover stops 55 cm behind the marker

    // Get input from the user
    printf("Enter marker x and y coordinates: ");
    scanf("%lf %lf", &x, &y);

    // Variables to store corrected position
    double x_final, y_final, z_final;

    // Apply correction
    convert_marker_position(x, y, z, correction_offset, &x_final, &y_final, &z_final);

    // Compute distances before and after correction
    double original_distance = calculate_distance(0, 0, 0, x, y, z);
    double adjusted_distance = calculate_distance(0, 0, 0, x_final, y_final, z_final);

    // Print results
    printf("New Marker Position relative to Rover: (%.2f, %.2f, %.2f)\n", x_final, y_final, z_final);
    printf("Distance to Original Marker: %.2f cm\n", original_distance);
    printf("Distance to Adjusted Position: %.2f cm\n", adjusted_distance);

    return 0;
}
