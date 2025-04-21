#include "minunit.h"
#include "../src/bilhetes_zoo.h"
#include <stdio.h>
#include <math.h>

/* Implementação da função de comparação de floats */
int mu_assert_float_eq(float expected, float actual) {
    const float epsilon = 0.001f;
    if (fabs(expected - actual) < epsilon) return 0;
    printf("expected %f but was %f\n", expected, actual);
    return 1;
}

/* 1. Testes de determinação de preço unitário */
MU_TEST(test_determinar_preco_unitario) {
    // Teste para crianças
    mu_assert_float_eq(10.0f, determinar_preco_unitario(5));
    mu_assert_float_eq(10.0f, determinar_preco_unitario(12));
    
    // Teste para adultos
    mu_assert_float_eq(30.0f, determinar_preco_unitario(13));
    mu_assert_float_eq(30.0f, determinar_preco_unitario(30));
    mu_assert_float_eq(30.0f, determinar_preco_unitario(59));
    
    // Teste para idosos
    mu_assert_float_eq(15.0f, determinar_preco_unitario(60));
    mu_assert_float_eq(15.0f, determinar_preco_unitario(80));
}

/* 2. Testes de validação de quantidade */
MU_TEST(test_quantidade_valida) {
    // Quantidades válidas
    mu_assert(quantidade_valida(1), "1 deve ser válido");
    mu_assert(quantidade_valida(3), "3 deve ser válido");
    mu_assert(quantidade_valida(5), "5 deve ser válido");
    
    // Quantidades inválidas
    mu_assert(!quantidade_valida(0), "0 não deve ser válido");
    mu_assert(!quantidade_valida(6), "6 não deve ser válido");
    mu_assert(!quantidade_valida(-1), "-1 não deve ser válido");
}

/* 3. Testes de cálculo de preço total */
MU_TEST(test_calcular_preco_total) {
    // Testes com quantidades válidas
    mu_assert_float_eq(50.0f, calcular_preco_total(10, 5));  // 5 crianças
    mu_assert_float_eq(60.0f, calcular_preco_total(30, 2));  // 2 adultos
    mu_assert_float_eq(30.0f, calcular_preco_total(65, 2));  // 2 idosos
    
    // Testes com quantidades inválidas
    mu_assert_float_eq(-1.0f, calcular_preco_total(20, 6));  // quantidade inválida
    mu_assert_float_eq(-1.0f, calcular_preco_total(15, 0));  // quantidade inválida
    mu_assert_float_eq(-1.0f, calcular_preco_total(40, -3)); // quantidade inválida
}

/* 4. Testes de valores limite */
MU_TEST(test_valores_limite) {
    // Limites de idade
    mu_assert_float_eq(10.0f, determinar_preco_unitario(12));  // limite superior criança
    mu_assert_float_eq(30.0f, determinar_preco_unitario(13));  // limite inferior adulto
    mu_assert_float_eq(30.0f, determinar_preco_unitario(59));  // limite superior adulto
    mu_assert_float_eq(15.0f, determinar_preco_unitario(60));  // limite inferior idoso
    
    // Limites de quantidade
    mu_assert(quantidade_valida(1), "1 deve ser válido (limite inferior)");
    mu_assert(quantidade_valida(5), "5 deve ser válido (limite superior)");
    mu_assert(!quantidade_valida(6), "6 não deve ser válido (acima do limite)");
}

/* 5. Testes de combinações especiais */
MU_TEST(test_combinacoes_especiais) {
    // Combinação criança + quantidade máxima
    mu_assert_float_eq(50.0f, calcular_preco_total(10, 5));
    
    // Combinação idoso + quantidade 1
    mu_assert_float_eq(15.0f, calcular_preco_total(70, 1));
    
    // Combinação adulto + quantidade média
    mu_assert_float_eq(90.0f, calcular_preco_total(25, 3));
    
    // Idade inválida (negativa)
    mu_assert_float_eq(30.0f, determinar_preco_unitario(-5)); // Assume comportamento padrão para idade inválida
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_determinar_preco_unitario);
    MU_RUN_TEST(test_quantidade_valida);
    MU_RUN_TEST(test_calcular_preco_total);
    MU_RUN_TEST(test_valores_limite);
    MU_RUN_TEST(test_combinacoes_especiais);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}