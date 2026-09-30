#include "Vehicle.hpp"

#include <iostream>

int main()
{
    Vehicle vehicle;

    vehicle.setSteeringAngle(10.0);

    constexpr double dt = 0.1;
    constexpr double simulation_time = 10.0;

    for (double t = 0.0; t < simulation_time; t += dt)
    {
        vehicle.update(dt);

        std::cout
            << "t: " << t + dt
            << ", ";

        vehicle.printState();
    }

    return 0;
}