#include "Vehicle.hpp"
#include <cmath>

#include <gtest/gtest.h>

TEST(VehicleTest, StartsAtOrigin)
{
    Vehicle vehicle;

    EXPECT_DOUBLE_EQ(vehicle.getX(), 0.0);
    EXPECT_DOUBLE_EQ(vehicle.getY(), 0.0);
    EXPECT_DOUBLE_EQ(vehicle.getTheta(), 0.0);
}

TEST(VehicleTest, MovesForwardWithZeroSteering)
{
    Vehicle vehicle;

    vehicle.update(1.0);

    EXPECT_NEAR(vehicle.getX(), 10.0, 1e-6);
    EXPECT_NEAR(vehicle.getY(), 0.0, 1e-6);
    EXPECT_NEAR(vehicle.getTheta(), 0.0, 1e-6);
}

TEST(VehicleTest, PositiveSteeringChangesHeading)
{
    Vehicle vehicle;

    vehicle.setSteeringAngle(10.0);
    vehicle.update(1.0);

    EXPECT_GT(vehicle.getTheta(), 0.0);
}

TEST(VehicleTest, NegativeSteeringChangesHeading)
{
    Vehicle vehicle;

    vehicle.setSteeringAngle(-10.0);
    vehicle.update(1.0);

    EXPECT_LT(vehicle.getTheta(), 0.0);
}

TEST(VehicleTest, HeadingMatchesKinematicBicycleModel)
{
    Vehicle vehicle;

    const double steering_angle = 10.0;
    const double dt = 1.0;

    vehicle.setSteeringAngle(steering_angle);
    vehicle.update(dt);

    constexpr double PI = 3.14159265358979323846;

    double steering_angle_rad =
        steering_angle * PI / 180.0;

    double expected_theta =
        (10.0 / 2.8) *
        std::tan(steering_angle_rad) *
        dt;

    EXPECT_NEAR(
        vehicle.getTheta(),
        expected_theta,
        1e-6
    );
}