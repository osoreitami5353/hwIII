#include "Exercise_III.hpp"

int main() {
    JsonDataBuilder<double> builderDoubles;
    // Agrega los valores tipo double al vector data de builderDoubles
    builderDoubles.add(1.3);
    builderDoubles.add(2.1);
    builderDoubles.add(3.2);

    JsonDataBuilder<std::string> builderWords;
    // Agrega los valores tipo string al vector data de builderWords
    builderWords.add("\033[4mHola\033[0m");
    // "\033[4m" es un código ANSI para subrayar el texto en la terminal, finalizando con "\033[0m" para resetear el formato.
    // El subrayado fue totalmente innecesario, pero en la clase se mencionó que el .pdf del Homework III tenía un error
    // en el que se mostraba "Hola" subrayado, y se decidió replicar ese error en el código solo por diversión.
    // Si se quisiera evitar el subrayado, se podría haber utilizado simplemente "Hola" sin los códigos ANSI.
    builderWords.add("Mundo");

    std::vector<std::vector<int>> lists = {
        {1, 2},
        {3, 4}
    };

    JsonAssembler assembler;
    // Se utiliza la función buildJsonArray() con el objeto builderDoubles y esto se settea en assembler que es un objeto de tipo JsonAssembler.
    // De esta manera se guardan los valores doubles en la variable vecDoubles de assembler.
    // Lo mismo ocurre con el objeto builderWords y la variable palabras de assembler.
    // Finalmente se setea la variable listas de assembler con el vector de vectores listas.
    assembler.setDoubles(builderDoubles.buildJsonArray());
    assembler.setWords(builderWords.buildJsonArray());
    assembler.setIntegerLists(lists);

    assembler.printJson();

    return 0;
}
