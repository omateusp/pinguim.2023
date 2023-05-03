#pragma once

class Vec2
{
public:
    float x;
    float y;

    Vec2(float x = 0, float y = 0);

    float GetLength() const;
    Vec2 GetUnit() const;
    float GetDistance(const Vec2 other) const;
    float GetAngle() const;
    float GetAngle(const Vec2 other) const;
    Vec2 GetRotated(float angle) const;

    Vec2 operator+(const Vec2 other) const;
    Vec2 &operator+=(const Vec2 other);
    Vec2 operator-(const Vec2 other) const;
    Vec2 &operator-=(const Vec2 other);
    Vec2 operator*(const int number) const;
    Vec2 &operator*=(const int number);
    Vec2 operator*(const float number) const;
    Vec2 &operator*=(const float number);
};