#include "../include/Vec2.h"
#include <math.h>

Vec2::Vec2(float x, float y) : x(x), y(y) {}

float Vec2::GetLength() const
{
    return sqrt(x * x + y * y);
}

Vec2 Vec2::GetUnit() const
{
    return Vec2(x / GetLength(), y / GetLength());
}

float Vec2::GetDistance(const Vec2 vec) const
{
    Vec2 diff = *this - vec;
    return diff.GetLength();
}

float Vec2::GetAngle() const
{
    return atan2(y, x);
}

float Vec2::GetAngle(const Vec2 vec) const
{
    Vec2 diff = *this - vec;
    return diff.GetAngle();
}

Vec2 Vec2::GetRotated(float angle) const
{
    return Vec2(x * cos(angle) - y * sin(angle),
                y * cos(angle) + x * sin(angle));
}

Vec2 Vec2::operator+(const Vec2 vec) const
{
    return Vec2(x + vec.x, y + vec.y);
}

Vec2 &Vec2::operator+=(const Vec2 vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Vec2 Vec2::operator-(const Vec2 vec) const
{
    return Vec2(x - vec.x, y - vec.y);
}

Vec2 &Vec2::operator-=(const Vec2 vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vec2 Vec2::operator*(const int n) const
{
    return Vec2(x * n, y * n);
}

Vec2 &Vec2::operator*=(const int n)
{
    x *= n;
    y *= n;
    return *this;
}

Vec2 Vec2::operator*(const float n) const
{
    return Vec2(x * n, y * n);
}

Vec2 &Vec2::operator*=(const float n)
{
    x *= n;
    y *= n;
    return *this;
}
