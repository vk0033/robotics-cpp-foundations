# Vehicle Kinematics Simulator

A C++ implementation of the kinematic bicycle model for simulating the motion of a vehicle.

This project was developed as part of my robotics software learning path, focusing on C++ software architecture, mathematical modeling, automated testing, and CMake-based builds.

## Overview

The simulator models a vehicle using:

- Vehicle position: `x`, `y`
- Vehicle heading: `theta`
- Vehicle velocity: `v`
- Wheelbase: `L`
- Steering angle: `delta`

The vehicle state is updated using the kinematic bicycle model.

## Mathematical Model

The vehicle motion is described by:

```text
dx/dt     = v * cos(theta)

dy/dt     = v * sin(theta)

dtheta/dt = (v / L) * tan(delta)


x     = x + v * cos(theta) * dt

y     = y + v * sin(theta) * dt

theta = theta + (v / L) * tan(delta) * dt