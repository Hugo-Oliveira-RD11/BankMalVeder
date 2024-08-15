//
// Created by hugo on 17/06/24.
//

#include "AlterarCliente.h"

void AlterarCC(Conta_Corrente antiga) {
  Conta_Corrente nova;
  nova.numConta = antiga.numConta;
  nova.cpf = antiga.cpf;
  nova.telefone = antiga.telefone;
  nova.limite = antiga.limite;
  nova.senha = antiga.senha;
  nova.agencia = antiga.agencia;
  strcpy(nova.nome, antiga.nome);
  strcpy(nova.endereco.bairro, antiga.endereco.bairro);
  strcpy(nova.endereco.cidade, antiga.endereco.cidade);
  strcpy(nova.endereco.estado, antiga.endereco.estado);
  nova.vencimento.dia = nova.vencimento.dia;
  nova.vencimento.mes = nova.vencimento.mes;
  nova.vencimento.ano = nova.vencimento.ano;
  nova.data.dia = antiga.data.dia;
  nova.data.mes = antiga.data.mes;
  nova.data.ano = antiga.data.ano;
  DeletarCC(antiga.numConta);
  Insere_arquivoCC(nova, CC);
  printf("Inserida com sucesso!\n");
}
void AlterarCP(Conta_Poupanca antiga) {
  Conta_Poupanca nova;
  nova.numConta = antiga.numConta;
  nova.cpf = antiga.cpf;
  nova.telefone = antiga.telefone;
  nova.senha = antiga.senha;
  nova.agencia = antiga.agencia;
  strcpy(nova.nome, antiga.nome);
  strcpy(nova.endereco.bairro, antiga.endereco.bairro);
  strcpy(nova.endereco.cidade, antiga.endereco.cidade);
  strcpy(nova.endereco.estado, antiga.endereco.estado);
  nova.data.dia = antiga.data.dia;
  nova.data.mes = antiga.data.mes;
  nova.data.ano = antiga.data.ano;
  DeletarCC(antiga.numConta);
  Insere_arquivoCP(nova, CP);
  printf("Inserida com sucesso!\n");
}

void MenusCC(Conta_Corrente cc) {
  int escolha = 0;
  while (escolha != 8 && escolha != 9) {
    printf("1 - Telefone.\n"
           "2 - Numero da casa.\n"
           "3 - CEP.\n"
           "4 - Bairro.\n"
           "5 - Cidade.\n"
           "6 - Estado.\n");
    scanf("%d", &escolha);
    if (escolha == 1) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero do telefone:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 9) == false) {
          printf("O numero do telefone deve possuir somente 9 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        cc.telefone = ver;
        break;
      }
      continue;
    }
    if (escolha == 2) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da casa:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 2) == false) {
          printf("O numero da casa deve possuir 2 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        cc.endereco.numCasa = ver;
        break;
      }
      continue;
    }
    if (escolha == 3) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o CEP:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 8) == false) {
          printf("O CEP deve possuir 8 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        cc.endereco.cep = ver;
        break;
      }
      continue;
    }

    if (escolha == 4) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o bairro:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("O bairro deve possuir de 3 a 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(cc.endereco.bairro, ver);
        break;
      }
      continue;
    }
    if (escolha == 5) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a cidade:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("A cidade deve possuir de 3 a 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(cc.endereco.cidade, ver);
        break;
      }
      continue;
    }
    if (escolha == 6) {
      char ver[2];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o estado (DF - SP - RJ):\n");
        scanf("%2[^\n]", ver);
        if (VerificaEstado(ver) == false) {
          printf("O Estado tem que possuir 2 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(cc.endereco.cidade, ver);
        break;
      }
      continue;
    }
    if (escolha == 7) {
      // para não mostrar erro
    }
    if (escolha == 8) {
      // para volltar
      return;
    } else {
      OpcaoInvalida();
      WhileKey();
    }
  }
}
void MenusCP(Conta_Poupanca cp) {
  int escolha = 0;
  while (escolha != 8 && escolha != 9) {
    printf("1 - Telefone.\n"
           "2 - Numero da casa.\n"
           "3 - CEP.\n"
           "4 - Bairro.\n"
           "5 - Cidade.\n"
           "6 - Estado.\n");
    scanf("%d", &escolha);
    if (escolha == 1) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero do telefone:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 9) == false) {
          printf("O numero do telefone deve possuir somente 9 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        cp.telefone = ver;
        break;
      }
      continue;
    }
    if (escolha == 2) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da casa:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 2) == false) {
          printf("O numero da casa deve possuir 2 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        cp.endereco.numCasa = ver;
        break;
      }
      continue;
    }
    if (escolha == 3) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o CEP:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 8) == false) {
          printf("O CEP deve possuir 8 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        cp.endereco.cep = ver;
        break;
      }
      continue;
    }

    if (escolha == 4) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o bairro:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("O bairro deve possuir de 3 a 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(cp.endereco.bairro, ver);
        break;
      }
      continue;
    }
    if (escolha == 5) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a cidade:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("A cidade deve possuir de 3 a 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(cp.endereco.cidade, ver);
        break;
      }
      continue;
    }
    if (escolha == 6) {
      char ver[2];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o estado (DF - SP - RJ):\n");
        scanf("%2[^\n]", ver);
        if (VerificaEstado(ver) == false) {
          printf("O Estado deve possuir 2 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(cp.endereco.cidade, ver);
        break;
      }
      continue;
    }
    if (escolha == 7) {
      // para não mostrar erro
    }
    if (escolha == 8) {
      // para volltar
      return;
    } else {
      OpcaoInvalida();
      WhileKey();
    }
  }
}

void AlterarCliente() {
  int flag;
  printf("Digite o CPF ou o numero da conta:\n");
  scanf("%d", &flag);
  int ver = PesquisarCliente(flag);
  if (ver == 0) {
    printf("Essa conta nao existe!\n");
    return;
  }
  if (ver == 1) {
    Conta_Poupanca cp = PesquisarClienteCP(flag, 3);
    MenusCP(cp);
  }
  if (ver == 2) {
    Conta_Corrente cc = PesquisarClienteCC(flag, 3);
    MenusCC(cc);
  }
}
