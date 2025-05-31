#include "Exercise_I.hpp"
#include <iostream>
#include <memory>

// ============================================== Presion ==============================================

Pressure::Pressure(const Pressure& other)
                  : BaselineMeasurement(*other.measurementTime), staticPressure(other.staticPressure),
                    dynamicPressure(other.dynamicPressure) {}
// Este constructor hace una depth copy, reconstruyendo el unique_ptr ya que std::unique_ptr no puede copiarse directamente.

void Pressure::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&staticPressure), sizeof(float));
    out.write(reinterpret_cast<const char*>(&dynamicPressure), sizeof(float));
    out.write(reinterpret_cast<const char*>(measurementTime.get()), sizeof(float));
}

void Pressure::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&staticPressure), sizeof(float));
    in.read(reinterpret_cast<char*>(&dynamicPressure), sizeof(float));

    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    // Se crea un nuevo float dinámico con el valor leído y se asigna al unique_ptr.
    // Esto es necesario porque unique_ptr no puede copiarse, solo transferir o reasignar su propiedad.
    measurementTime = std::make_unique<float>(t);
}

void Pressure::print() const {
    std::cout << "Presión Estática: " << staticPressure <<
                 ", Presión Dinámica: " << dynamicPressure <<
                 ", Tiempo: " << getTime() << std::endl;
}

// ============================================== Posición ==============================================

Position::Position(const Position& other)
                  : BaselineMeasurement(*other.measurementTime), latitude(other.latitude),
                    longitude(other.longitude), altitude(other.altitude) {}
// Este constructor hace una depth copy, reconstruyendo el unique_ptr ya que std::unique_ptr no puede copiarse directamente.

void Position::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&latitude), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitude), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitude), sizeof(float));
    out.write(reinterpret_cast<const char*>(measurementTime.get()), sizeof(float));
}

void Position::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&latitude), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitude), sizeof(float));
    in.read(reinterpret_cast<char*>(&altitude), sizeof(float));
    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    // Se crea un nuevo float dinámico con el valor leído y se asigna al unique_ptr.
    // Esto es necesario porque unique_ptr no puede copiarse, solo transferir o reasignar su propiedad.
    measurementTime = std::make_unique<float>(t);
}

void Position::print() const {
    std::cout << "Position (lat, lon, alt): (" << latitude << ", " << longitude << ", " << altitude
            << "), Tiempo: " << getTime() << std::endl;
}

// =========================================== SaveFlightData ===========================================

void SaveFlightData::serialize(std::ofstream& out) const {
    position.serialize(out);
    pressure.serialize(out);
}

void SaveFlightData::deserialize(std::ifstream& in) {
    position.deserialize(in);
    pressure.deserialize(in);
}

void SaveFlightData::print() const {
    std::cout << "========================= Datos de Vuelo =========================" << std::endl;
    position.print();
    pressure.print();
}