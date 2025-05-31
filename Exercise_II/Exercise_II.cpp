#include "Exercise_II.hpp"

// ========================== Punto ==========================

Point::Point() : x(0), y(0) {}
Point::Point(float x_, float y_) : x(x_), y(y_) {}

float Point::getX() const { return x; }
float Point::getY() const { return y; }

void Point::setX(float x_) { x = x_; }
void Point::setY(float y_) { y = y_; }

// ========================== Círculo ==========================

Circle::Circle() : center(), radius(1.0) {}
Circle::Circle(Point c, float r) : center(c), radius(r) {}

Point Circle::getCenter() const { return center; }
float Circle::getRadius() const { return radius; }

void Circle::setCenter(Point c) { center = c; }
void Circle::setRadius(float r) { radius = r; }

// ========================== Elipse ==========================

Ellipse::Ellipse() : center(), a(1.0), b(1.0) {}
Ellipse::Ellipse(Point c, float a_, float b_) : center(c), a(a_), b(b_) {}

Point Ellipse::getCenter() const { return center; }
float Ellipse::getA() const { return a; }
float Ellipse::getB() const { return b; }

void Ellipse::setCenter(Point c) { center = c; }
void Ellipse::setA(float a_) { a = a_; }
void Ellipse::setB(float b_) { b = b_; }

// ========================== Rectángulo ==========================

Rectangle::Rectangle() : bottomLeft(), width(1.0), height(1.0) {}
Rectangle::Rectangle(Point p, float w, float h) : bottomLeft(p), width(w), height(h) {}

Point Rectangle::getBottomLeft() const { return bottomLeft; }
float Rectangle::getWidth() const { return width; }
float Rectangle::getHeight() const { return height; }

void Rectangle::setBottomLeft(Point p) { bottomLeft = p; }
void Rectangle::setWidth(float w) { width = w; }
void Rectangle::setHeight(float h) { height = h; }

// =================== Template Specialization ===================

// Especialización: Círculo
template <>
float FigureProcessor<Circle>::area(const Circle& c) {
    return M_PI * std::pow(c.getRadius(), 2);
}

// Especialización: Elipse
template <>
float FigureProcessor<Ellipse>::area(const Ellipse& e) {
    return M_PI * e.getA() * e.getB();
}

// Especialización: Rectángulo
template <>
float FigureProcessor<Rectangle>::area(const Rectangle& r) {
    return r.getWidth() * r.getHeight();
}