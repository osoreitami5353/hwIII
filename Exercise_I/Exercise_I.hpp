#ifndef Exercise_I_HPP
#define Exercise_I_HPP

#include <iostream>
#include <fstream>
#include <memory>

// Interfaz para mediciones
class IMeasurements {
    public:
        virtual void serialize(std::ofstream& out) const = 0;
        virtual void deserialize(std::ifstream& in) = 0;
        virtual ~IMeasurements() = default;
};

// Clase abstracta base para todas las mediciones
class BaselineMeasurement : public IMeasurements {
    protected:
        std::unique_ptr<float> measurementTime;

    public:
        BaselineMeasurement() = default;
        BaselineMeasurement(float t) : measurementTime(std::make_unique<float>(t)) {}
        float getTime() const { return *measurementTime; }
        virtual void print() const = 0;
};

// Clase Presión
class Pressure : public BaselineMeasurement {
    public:
        float staticPressure;
        float dynamicPressure;

        Pressure() = default;
        Pressure(float p, float q, float t) 
                : BaselineMeasurement(t), staticPressure(p), dynamicPressure(q) {}
        
        // Constructor de depth copy para permitir copiar objetos con unique_ptr
        Pressure(const Pressure& other);

        void serialize(std::ofstream& out) const override;

        void deserialize(std::ifstream& in) override;

        void print() const override;
};

// Clase Posición
class Position : public BaselineMeasurement {
    public:
        float latitude;
        float longitude;
        float altitude;

        Position() = default;
        Position(float lat, float lon, float alt, float t) 
                : BaselineMeasurement(t), latitude(lat), longitude(lon), altitude(alt) {}
        
        // Constructor de copia profundo para permitir copiar objetos con unique_ptr
        Position(const Position& other);

        void serialize(std::ofstream& out) const override;

        void deserialize(std::ifstream& in) override;

        void print() const override;
};

// Clase SaveFlightData
class SaveFlightData {
    private:
        Position position;
        Pressure pressure;

    public:
        SaveFlightData() = default;

        // El constructor recibe las mediciones por referencia constante para evitar copias.
        // El uso de referencias evita copiar objetos con unique_ptr.
        SaveFlightData(const Position& pos, const Pressure& pre)
                      : position(pos), pressure(pre) {}

        void serialize(std::ofstream& out) const;

        void deserialize(std::ifstream& in);

        void print() const;
};

#endif // Exercise_I_HPP