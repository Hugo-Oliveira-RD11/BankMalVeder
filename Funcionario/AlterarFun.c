//
// Created by hugo on 17/06/24.
//

#include "AlterarFun.h"
void Alterar(Funcionario novaFun, Funcionario antigoFun) {
  novaFun.cargo = antigoFun.cargo;
  novaFun.cpf = antigoFun.cpf;
  novaFun.codigo = antigoFun.codigo;
  novaFun.data.dia = antigoFun.data.dia;
  novaFun.data.mes = antigoFun.data.mes;
  novaFun.data.ano = antigoFun.data.ano;
  novaFun.senha = antigoFun.senha;
  novaFun.telefone = antigoFun.telefone;
  novaFun.endereco.cep = antigoFun.endereco.cep;
  novaFun.endereco.numCasa = antigoFun.endereco.numCasa;
  strcpy(novaFun.endereco.bairro, novaFun.endereco.bairro);
  strcpy(novaFun.endereco.estado, novaFun.endereco.estado);
  strcpy(novaFun.endereco.cidade, novaFun.endereco.cidade);
  strcpy(novaFun.nome, novaFun.nome);

  DeletarF(antigoFun.cpf);
  Insere_arquivoF(novaFun, sub);

  Limpa_Tela();
  printf("Codigo: %d\n", novaFun.codigo);
}

void Alterar_Conta_Funcionario() {
  int escolha, flag = 0;
  Funcionario fun, delete;
  printf("Digite o CPF ou codigo do funcionario:\n");
  scanf("%d", &flag);
  delete = PesquisarFuncionario(flag, sub);
  if (delete.codigo == 0 || delete.cpf == 0) {
    printf("Essa conta nao existe!\n");
    WhileKey();
    return;
  }
  while (escolha != 13 || escolha != 14) {
    Limpa_Tela();
    printf("\t\t------------>ALTERAR FUNCIONARIO<--------\n"
           "1 - Codigo do funionario.\n"
           "2 - Cargo.\n"
           "3 - Nome.\n"
           "4 - Telefone.\n"
           "5 - Numero da casa.\n"
           "6 - CEP.\n"
           "7 - Estado.\n"
           "8 - Bairro.\n"
           "9 - Cidade.\n"
           "10 - Confirmar.\n"
           "11 - Voltar.\n");
    scanf("%d", &escolha);
    if (escolha == 1) {
      int ver = 0;
      while (1) {
        printf("Digite o codigo:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 8) == false) {
          printf("O codigo deve conter 8 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        fun.codigo = ver;
        break;
      }
      continue;
    }
    if (escolha == 2) {
      int ver = 0;
      while (1) {
        printf("Digite o cargo:\n");
        scanf("%d", &ver);
        if (ver != 1 || ver != 2) {
          OpcaoInvalida();
          continue;
        }
        fun.cargo = ver;
        break;
      }
      continue;
    }
    if (escolha == 3) {
      char ver[LIM];
      while (1) {
        printf("Digite o nome:\n");
        scanf("%100[^\n]", ver);
        if (VerificaNome(ver) == false) {
          printf("O nome deve possuir de 3 a 100 caracteres!");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(fun.nome, ver);
        break;
      }
      continue;
    }
    if (escolha == 4) {
      int ver = 0;
      while (1) {
        printf("Digite o telefone:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 9) == false) {
          printf("O numero deve possuir 9 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        fun.telefone = ver;
        break;
      }
      continue;
    }
    if (escolha == 5) {
      int ver = 0;
      while (1) {
        printf("Digite o numero da casa:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 2) == false) {
          printf("O numero da casa deve possuir 2 numeros!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        fun.endereco.numCasa = ver;
        break;
      }
      continue;
    }
    if (escolha == 6) {
      int ver = 0;
      while (1) {
        printf("Digite o CEP:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 8) == false) {
          printf("O CEP deve possuir 8 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        fun.endereco.cep = ver;
        break;
      }
      continue;
    }
    if (escolha == 7) {
      char ver[2];
      while (1) {
        printf("Digite o Estado: (DF - SP - RJ - MG)\n");
        scanf("%2[^\n]", ver);
        if (VerificaEstado(ver) == false) {
          printf("O Estado deve possuir 2 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(fun.endereco.estado, ver);
        break;
      }
      continue;
    }
    if (escolha == 8) {
      char ver[LIM];
      while (1) {
        printf("Digite o bairro:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("O bairro deve possuir de 3 a 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(fun.endereco.bairro, ver);
        break;
      }
      continue;
    }
    if (escolha == 9) {
      char ver[LIM];
      while (1) {
        printf("Digite a cidade:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("A cidade deve possuir de 3 a 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(fun.endereco.cidade, ver);
        break;
      }
      continue;
    }
    if (escolha == 10) {
      // so para n mostrar menssagem de erro.
    }
    if (escolha == 11) {
      continue;
    }
  }
  Alterar(fun, delete);
}
