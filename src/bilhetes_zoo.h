#ifndef BILHETES_ZOO_H
#define BILHETES_ZOO_H

#include <stdbool.h>

float determinar_preco_unitario(int idade);
bool quantidade_valida(int quantidade);
float calcular_preco_total(int idade, int quantidade);

#endif