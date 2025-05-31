# Homework #3 – Serialización y Programación Genérica
**Materia:** I102 – Paradigmas de Programación  
**Estudiante:** Vallejos Candela Anahí  
**Fecha límite:** 31/05/2025

## Ejercicio I – Serialización de mediciones de vuelo

**Desarrollo:**  
Se diseñó un sistema orientado a objetos para representar dos tipos de mediciones: posición (latitud, longitud, altitud, tiempo) y presión (estática, dinámica, tiempo).

Cada medición incluye un campo de tiempo de medición, que debe tener propiedad exclusiva mediante `std::unique_ptr<float>`.
Como el unique_ptr no puede copiarse por defecto, para permitir copiar objetos de `Position` y `Pressure` (por ejemplo, al pasarlos a SaveFlightData), se implementó un constructor de copia profundo.
Este constructor crea una nueva instancia del tiempo con `std::make_unique<float>(*other.measurementTime)`, evitando usar `std::move` como solicitaba el enunciado.

Los datos se escriben a un archivo binario con `std::ofstream::write()` y se recuperan con `std::ifstream::read()`. Se usaron conversiones con reinterpret_cast para manipular los datos de tipo float.

**Archivos incluidos:**

- `Exercise_I.hpp`
- `Exercise_I.cpp`
- `main.cpp`

**Compilación:**

```
g++ main.cpp Exercise_I.cpp -Wall -g -std=c++20 -o exerI
```

**Prueba implementada:**
El programa crea una posición y una presión (solicitadas en el propio .pdf), guarda los datos en un archivo binario y luego los lee nuevamente mostrando los resultados.

## Ejercicio II – Figuras geométricas y templates

**Desarrollo:**  
Se crearon clases `Point`, `Circle`, `Ellipse` y `Rectangle`. Luego, se definió la clase plantilla `FigureProcessor<T>` y se usaron especializaciones de plantilla (`template<>`) para calcular el área según el tipo de figura.
Esto permite definir un comportamiento específico por tipo, sin necesidad de condicionales dentro del mismo código genérico.

Las funciones especializadas (`area(...)`) se movieron del archivo `.hpp` al `.cpp`, ya que el linker genera errores si las definiciones completas de especialización se encuentran en archivos de cabecera incluidos desde varios lugares.

**Archivos incluidos:**

- `Exercise_II.hpp`
- `Exercise_II.cpp`
- `main.cpp`

**Compilación:**

```
g++ main.cpp Exercise_II.cpp -Wall -g -std=c++20 -o exerII
```

**Prueba implementada:**
El programa instancia un objeto de cada figura, calcula su área usando `FigureProcessor<T>::area(...)` y muestra el resultado por pantalla.

## Ejercicio III – Generación de JSON con templates

**Desarrollo**  
Se construyó un objeto JSON con tres variables:

- `"vecDoubles"`: lista de `double`

- `"words"`: lista de `std::string`

- `"lists"`: matriz de enteros `std::vector<std::vector<int>>`

Se usaron dos clases:
1) `JsonDataBuilder<T>`: clase plantilla para construir arrays JSON a partir de datos numéricos o strings.
2) `JsonAssembler`: clase encargada de ensamblar el JSON final a partir de etiquetas y contenido generado.

Para aplicar comportamiento distinto según el tipo T en tiempo de compilación se utilizó `if constexpr`, como lo solicitaba la actividad.

**Archivos incluidos:**

- `Exercise_III.hpp`
- `Exercise_III.cpp`
- `main.cpp`

**Compilación:**

```
g++ main.cpp Exercise_III.cpp -Wall -g -std=c++20 -o exerIII
```

**Prueba implementada:**
Se agregan manualmente los valores `1.3`, `2.1`, `3.2`, `"Hola"`, `"Mundo"` y la matriz `{ {1, 2}, {3, 4} }`. El JSON generado es impreso por pantalla y cumple con el formato solicitado.
