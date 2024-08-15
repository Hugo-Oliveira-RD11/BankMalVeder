#ifndef DATA_H_
#define DATA_H_

#include "../GLOBAL.h"

// função "privada", utilizada para a seleção de abertura de arquivo
FILE *Abrindo_Arquivo(int escolha);

void Insere_arquivoF(Funcionario f, int op);
void Insere_arquivoCC(Conta_Corrente c, int op);
void Insere_arquivoCP(Conta_Poupanca c, int op);
//
// caso retorne 0 no cpf e na numConta e porque não achou
// op == 1 e cpf da pessoa
// op == 2 e numConta para cliente ou codigo para funcionario
// op == 3 significa que vai procurar nas duas opçãos
Conta_Corrente PesquisarClienteCC(int flag, int op);
Conta_Poupanca PesquisarClienteCP(int flag, int op);
Funcionario PesquisarFuncionario(int flag, int op);
int PesquisarCliente(int flagCPF);

void DeletarCC(int flag);
void DeletarCP(int flag);
void DeletarF(int flag);

// saldo
void Insere_SaldoCP(SaldoCP saldo);
void Insere_SaldoCC(SaldoCC saldo);

SaldoCP MostrarSaldoCP(int flag, int op);
SaldoCC MostrarSaldoCC(int flag, int op);

void ExtratoSaldoCC(int flag, int op);
void ExtratoSaldoCP(int flag, int op);
double ContaLimite(Conta_Corrente cc);

#endif // DATA_H_
