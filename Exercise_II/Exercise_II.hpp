#ifndef EXERCISE_II_HPP
#define EXERCISE_II_HPP

#include <iostream>
#include <cmath>

constexpr float PI = 3.14159265359f;

// ========================== Punto ==========================

class Point {
    private:
        float x, y;

    public:
        Point();
        // Es una convención común usar "x_" y "y_" para distinguir los nombres de los parámetros de los nombres de atributos de la clase.
        Point(float x_, float y_);

        float getX() const;
        float getY() const;

        void setX(float x_);
        void setY(float y_);
};

// ========================== Círculo ==========================

class Circle {
    private:
        Point center;
        float radius;

    public:
        Circle();
        Circle(Point c, float r);

        Point getCenter() const;
        float getRadius() const;

        void setCenter(Point c);
        void setRadius(float r);
};

// ========================== Elipse ==========================

class Ellipse {
    private:
        Point center;
        float a;
        float b;

    public:
        Ellipse();
        Ellipse(Point c, float a_, float b_);

        Point getCenter() const;
        float getA() const;
        float getB() const;

        void setCenter(Point c);
        void setA(float a_);
        void setB(float b_);
};

// ========================== Rectángulo ==========================

class Rectangle {
    private:
        Point bottomLeft;
        float width, height;

    public:
        Rectangle();
        Rectangle(Point p, float w, float h);

        Point getBottomLeft() const;
        float getWidth() const;
        float getHeight() const;

        void setBottomLeft(Point p);
        void setWidth(float w);
        void setHeight(float h);
};

// ===================== Plantilla para área =====================

template <typename T>
class FigureProcessor {
public:
    static float area(const T& figure);
};

#endif // EXERCISE_II_HPP