#include "Vehicle.hpp"

#include <cmath>
#include <iostream>

Vehicle::Vehicle()
    : x(0.0),
      y(0.0),
      theta(0.0),
      velocity(10.0),
      wheel_base(2.8),
      steering_angle(0.0)
{
}

void Vehicle::update(double dt)
{
    constexpr double PI = 3.14159265358979323846;

    double steering_angle_rad =
        steering_angle * PI / 180.0;

    double dx =
        velocity * std::cos(theta) * dt;

    double dy =
        velocity * std::sin(theta) * dt;

    double dtheta =
        (velocity / wheel_base) *
        std::tan(steering_angle_rad) * dt;

    x += dx;
    y += dy;
    theta += dtheta;
}

void Vehicle::setSteeringAngle(double angle)
{
    steering_angle = angle;
}

void Vehicle::printState() const
{
    std::cout
        << "x: " << x
        << ", y: " << y
        << ", theta: " << theta
        << std::endl;
}

double Vehicle::getX() const
{
    return x;
}

double Vehicle::getY() const
{
    return y;
}

double Vehicle::getTheta() const
{
    return theta;
}

