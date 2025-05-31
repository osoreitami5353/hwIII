#include "Exercise_III.hpp"
#include <iostream>

void JsonAssembler::setDoubles(const std::string& json) { vecDoubles = json; }

void JsonAssembler::setPalabras(const std::string& json) { palabras = json; }

void JsonAssembler::setListas(const std::vector<std::vector<int>>& matrix) {
     // std::ostringstream sirve para construir un string a partir de datos, usando el operador << como si fuera std::cout. Permite armar el texto en memoria en vez de imprimirlo.
    std::ostringstream oss;
    oss << "[\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        oss << "              [";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            oss << matrix[i][j];
            // Si no es el último elemento dentro del vector que está dentro del vector principal, se agrega ", " hasta que se esté en el último valor del vector y pasar al siguiente vector.
            if (j < matrix[i].size() - 1) oss << ", ";
        }
        // Al llegar al último valor del vector que está dentro del vector principal, se agrega "]" y se pasa al siguiente vector.
        oss << "]";
        // Si no es el último vector dentro del vector principal, se agrega ", " hasta que se esté en el último vector y cerrar el vector principal.
        if (i < matrix.size() - 1) oss << ",";
        oss << "\n";
    }
    oss << "             ]";
    // Se pasa el string armado a la variable listas.
    listas = oss.str();
}

void JsonAssembler::printJson() const {
    std::cout << "{\n"
            << "  \"vec_doubles\" : " << vecDoubles << ",\n"
            << "  \"palabras\" : " << palabras << ",\n"
            << "  \"listas\" : " << listas << "\n"
            << "}" << std::endl;
}