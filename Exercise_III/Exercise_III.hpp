#ifndef EXERCISE_III
#define EXERCISE_III

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <type_traits>

template<typename T>
class JsonDataBuilder {
    private:
        std::vector<T> data;

    public:
        void add(const T& value){
            data.push_back(value);
        } 

        // Si el tipo de dato es string, se agregan comillas; si es numérico, se deja tal cual.
        std::string buildJsonArray() const {
            // std::ostringstream sirve para construir un string a partir de datos, usando el operador << como si fuera std::cout. Permite armar el texto en memoria en vez de imprimirlo.
            std::ostringstream oss;
            oss << "[";

            for (size_t i = 0; i < data.size(); ++i) {
                if constexpr (std::is_same_v<T, std::string>) {
                    oss << "\"" << data[i] << "\"";
                } else {
                    oss << data[i];
                }

                // Si no es el último elemento, se agrega ", " hasta que se esté en el último valor del vector.
                if (i < data.size() - 1) oss << ", ";
            }

            oss << "]";
            return oss.str();
        }

        const std::vector<T>& getData() const {
            return data;
        }
};

class JsonAssembler {
    private:
        std::string vecDoubles;
        std::string palabras;
        std::string listas;

    public:
        void setDoubles(const std::string& json);

        void setPalabras(const std::string& json);

        void setListas(const std::vector<std::vector<int>>& matrix);

        void printJson() const;
};

#endif // EXERCISE_III