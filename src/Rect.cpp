#include "../include/Rect.h"

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

bool Rect::Contains(Vec2 point) const
{
    return (point.x >= x && point.x <= x + w) && (point.y >= y && point.y <= y + h);
}

Vec2 Rect::GetCenter() const
{
    return Vec2(x + w / 2.0, y + h / 2.0);
}

Vec2 Rect::GetOrigin() const
{
    return Vec2(x, y);
}

float Rect::GetDistance(Rect other) const
{
    return GetCenter().GetDistance(other.GetCenter());
}

Rect Rect::operator+(const Vec2 vec) const
{
    return Rect(x, y, w + vec.x, h + vec.y);
}

Rect &Rect::operator+=(const Vec2 vec)
{
    w += vec.x;
    h += vec.y;
    return *this;
}