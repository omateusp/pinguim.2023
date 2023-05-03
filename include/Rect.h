#pragma once
#include "Vec2.h"

class Rect
{
public:
    float x;
    float y;
    float w;
    float h;

    Rect(float x = 0, float y = 0, float w = 0, float h = 0);

    Vec2 GetCenter() const;
    Vec2 GetOrigin() const;

    float GetDistance(const Rect other) const;
    bool Contains(Vec2 point) const;

    Rect operator+(const Vec2 vec) const;
    Rect &operator+=(const Vec2 vec);
};
