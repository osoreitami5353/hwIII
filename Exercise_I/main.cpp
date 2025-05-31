#include "Exercise_I.hpp"
#include <fstream>
#include <iostream>

int main() {
    Position originalPosition(-34.6f, -58.4f, 950.0f, 5.3f);
    Pressure originalPressure(101.3f, 5.8f, 6.1f);

    SaveFlightData flightDataOut(originalPosition, originalPressure);

    std::ofstream outFile("flightdata.bin", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return 1;
    }

    flightDataOut.serialize(outFile);
    outFile.close();

    std::cout << "=================================================================\n" << std::endl;

    std::cout << "Datos de vuelo serializados correctamente.\n" << std::endl;

    SaveFlightData flightDataIn;

    std::ifstream inFile("flightdata.bin", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return 1;
    }

    flightDataIn.deserialize(inFile);
    inFile.close();

    std::cout << "Datos de vuelo deserializados correctamente:\n" << std::endl;
    flightDataIn.print();

    return 0;
}
