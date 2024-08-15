#ifndef MENU_H_
#define MENU_H_
#include "GLOBAL.h"

#define true 1
#define false 0
#define LIM 100

#define ger 1
#define sub 2
#define CC 3
#define CP 4

/* op == 1 cliente */
/* op == 2 SubGerente */
/* op == 3 Gerente */
void PrimeiroGerente();
int Digite_Senha(int op);
void SenhaInvalida();
void Menu_Principal();

void WhileKey();
void LimpaBuffer();
void Limpa_Tela();
void OpcaoInvalida();
void Planilha();

int Testando_SenhaF(int flag, int senha);
int Testando_SenhaCC(int flag, int senha);
int Testando_SenhaCP(int flag, int senha);
int VerificaGerente(int senha);

#endif // MENU_H_
