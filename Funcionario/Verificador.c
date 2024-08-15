// Created by laram on 10/06/2024.

#include "Verificador.h"

int VerificaNome(char string[LIM]) {
  if (strlen(string) == 3 || strlen(string) > 100) {
    return false;
  }
  return true;
}

int VerificaCb(char string[LIM]) {
  if (strlen(string) == 2 || strlen(string) > 100) {
    return false;
  }
  return true;
}

int VerificaEstado(char string[LIM]) {
  if (strlen(string) != 2) {
    return false;
  }
  return true;
}

int VerificaCPF(char string[LIM]) {
  if (strlen(string) != 11) {
    return false;
  }
  return true;
}

int VerificaNum(int num, int ver) {
  int cont = 0;
  while (num != 0) {
    cont++;
    num /= 10;
  }
  if (cont == ver) {
    return true;
  }
  return false;
}

int VerificaSenha(int num) {
  int cont = 0;
  while (num != 0) {
    cont++;
    num /= 10;
  }
  if (cont < 4 && cont > 6) {
    return false;
  }
  return true;
}
