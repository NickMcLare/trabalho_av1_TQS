
---

# Atividade de Teste de Qualidade – Venda de Bilhetes

## 🎯 Objetivo

Implementar e testar um algoritmo em linguagem C que calcula o valor total de bilhetes com base na idade do visitante e na quantidade de ingressos solicitados. O programa também deve validar as entradas e seguir critérios de precificação por faixa etária.

---

## 📥 Dados de Entrada

- `idade`: Idade do visitante.
- `quantidade`: Quantidade de bilhetes a serem comprados.

---

## ⚙️ Processamento

- Verificar se a quantidade solicitada está dentro do limite permitido (máximo de 5 bilhetes por pessoa).
- Calcular o preço do bilhete com base na idade:
  - Crianças (0 a 12 anos): **R$ 10,00**
  - Adultos (13 a 59 anos): **R$ 30,00**
  - Idosos (60 anos ou mais): **R$ 15,00**
- Caso a quantidade seja válida, calcular o valor total da compra.
- Se a quantidade for inválida, exibir uma mensagem de erro.

---

## 💡 Saída

- Preço total a ser pago, caso a quantidade de bilhetes seja válida.
- Mensagem de erro se a quantidade exceder o limite ou for inválida.

---

## ✅ Framework de Teste

Os testes foram implementados utilizando o framework **MinUnit** para linguagem C.

---

## 📊 Classes de Equivalência e Casos de Teste

| ID  | Idade  | Quantidade | Faixa Etária | Classe de Valor | Esperado                      |
|-----|--------|------------|--------------|------------------|-------------------------------|
| T01 | 8      | 2          | Criança      | Válido           | Total = R$ 20,00              |
| T02 | 25     | 1          | Adulto       | Válido           | Total = R$ 30,00              |
| T03 | 61     | 3          | Idoso        | Válido           | Total = R$ 45,00              |
| T04 | 35     | 6          | Adulto       | Inválido         | Erro: quantidade inválida     |
| T05 | -1     | 2          | Inválido     | Inválido         | Erro: idade inválida          |
| T06 | 12     | 5          | Criança      | Limite Inferior  | Total = R$ 50,00              |
| T07 | 13     | 1          | Adulto       | Limite Inferior  | Total = R$ 30,00              |
| T08 | 59     | 2          | Adulto       | Limite Superior  | Total = R$ 60,00              |
| T09 | 60     | 2          | Idoso        | Limite Inferior  | Total = R$ 30,00              |
| T10 | 0      | 1          | Criança      | Limite Inferior  | Total = R$ 10,00              |

---

## 🛠 Como Executar os Testes

1. Compile o programa com os testes:
   ```bash
   gcc src/main.c test/test.c -o bin/testes
   ```

2. Execute:
   ```bash
   ./bin/testes
   ```

---

## 📁 Estrutura do Projeto

```
teste_qualidade/
│
├── src/
│   └── main.c              # Código-fonte principal
│
├── test/
│   └── test.c              # Casos de teste com MinUnit
│
├── Makefile                # Automação de build/test
├── readme.md               # Este documento
└── .gitignore
```

---

## 👥 Autores

- **Fernando Gabriel Barbosa Dias** – Matrícula: 202310310311  
- **Nicholas Santana de Sousa** – Matrícula: 202310311011
