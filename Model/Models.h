#ifndef MODELS_H_
#define MODELS_H_

#define LIM 100
#define LimEstado 2
#include "../GLOBAL.h"

typedef enum { Gerente = 1, funcionario = 2 } Cargo;

// TODOS OS MEMBROS DE STRUCT MINUSCULOS

typedef struct {
  int cep;
  int numCasa;
  char bairro[LIM];
  char cidade[LIM];
  char estado[LimEstado];
} Endereco;

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  int codigo;
  int cpf;
  char nome[LIM];
  Data data;
  Endereco endereco;
  Cargo cargo;
  int telefone;
  int senha;
} Funcionario;

typedef struct {
  int agencia;
  int limite;
  Data vencimento;
  int numConta;
  char nome[LIM];
  int cpf;
  Data data;
  int telefone;
  Endereco endereco;
  int senha;
} Conta_Corrente;

typedef struct {
  int agencia;
  int numConta;
  char nome[LIM];
  int cpf;
  Data data;
  int telefone;
  Endereco endereco;
  int senha;
} Conta_Poupanca;

typedef struct {
  int numConta;
  int cpf;
  double antigoSaldo;
  double saldoAtual;
  Data data;
} SaldoCP;

typedef struct {
  int numConta;
  int cpf;
  double limite;
  double antigoSaldo;
  double saldoAtual;
  Data data;
} SaldoCC;

#endif // MODELS_H_
