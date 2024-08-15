//
// Created by laram on 10/06/2024.
//
#ifndef VERIFICADOR_H
#define VERIFICADOR_H

#include "../GLOBAL.h"

int VerificaNome(char string[LIM]);

int VerificaCb(char string[LIM]);

int VerificaEstado(char string[LIM]);

int VerificaCPF(char string[LIM]);

int VerificaNum(int num, int ver);

int VerificaSenha(int num);
#endif // VERIFICADOR_H
