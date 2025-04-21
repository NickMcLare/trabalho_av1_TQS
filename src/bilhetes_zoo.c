#include "bilhetes_zoo.h"

float determinar_preco_unitario(int idade) {
    if (idade <= 12) return 10.0f;
    else if (idade <= 59) return 30.0f;
    else return 15.0f;
}

bool quantidade_valida(int quantidade) {
    return quantidade > 0 && quantidade <= 5;
}

float calcular_preco_total(int idade, int quantidade) {
    if (!quantidade_valida(quantidade)) return -1.0f;
    return quantidade * determinar_preco_unitario(idade);
}