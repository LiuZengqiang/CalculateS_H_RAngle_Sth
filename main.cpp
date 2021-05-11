#include "Eigen/eigen"
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

void printVec3(Eigen::Vector3f vec, string pre = "");

float calculateSHRAngle(Eigen::Vector3f receiver, Eigen::Vector3f heliostat, float altitude, float azimuth);

int main() {

//    Eigen::Vector3f v(1, 1, 1);
//    printVec3(v);
//    v.normalize();
//    printVec3(v);


    Eigen::Vector3f receiver(0, 200, 0);
    Eigen::Vector3f heliostat(0, 0, -200);

    float altitude = 47.041;
    float azimuth = 142.400;


    float angle = calculateSHRAngle(receiver, heliostat, altitude, azimuth);

    cout << angle << endl;
    return 0;
}

float calculateSHRAngle(Eigen::Vector3f receiver, Eigen::Vector3f heliostat, float altitude, float azimuth) {
    altitude = altitude / 180.0f * M_PI;
    azimuth = azimuth / 180.0f * M_PI;
    Eigen::Vector3f sun;
    sun.x() = cos(altitude) * sin(azimuth);
    sun.y() = sin(altitude);
    sun.z() = cos(altitude) * cos(azimuth);
    sun.normalize();
    Eigen::Vector3f helio_rec = receiver - heliostat;
    helio_rec.normalize();
    return acos(sun.dot(helio_rec)) / M_PI * 180.0f;
};

void printVec3(Eigen::Vector3f vec, string pre) {
    cout << pre << "(" << vec.x() << "," << vec.y() << "," << vec.z() << ")" << endl;
};