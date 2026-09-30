#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle
{
private:
    double x;
    double y;
    double theta;

    double velocity;
    double wheel_base;
    double steering_angle;

public:
    Vehicle();

    void update(double dt);

    void setSteeringAngle(double angle);

    void printState() const;

    double getX() const;
    double getY() const;
    double getTheta() const;
};

#endif