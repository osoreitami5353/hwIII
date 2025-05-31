#include <iostream>
#include "Exercise_II.hpp"

int main() {
    Circle circle(Point(0, 0), 5.0f);
    Ellipse ellipse(Point(1, -3), 4.0f, 2.0f);
    Rectangle rectangle(Point(-1, 2), 6.0f, 3.0f);
    
    std::cout << "\n=================================================================" << std::endl;

    std::cout << "Área del círculo: " << FigureProcessor<Circle>::area(circle) << std::endl;
    std::cout << "Área de la elipse: " << FigureProcessor<Ellipse>::area(ellipse) << std::endl;
    std::cout << "Área del rectángulo: " << FigureProcessor<Rectangle>::area(rectangle) << std::endl;
    
    std::cout << "=================================================================\n" << std::endl;

    return 0;
}