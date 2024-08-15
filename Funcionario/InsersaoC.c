#include "./InsersaoC.h"

void Definir_Info_Conta_Corrente(Conta_Corrente conta2) {
  PrintarDarthVaderPequeno();
  int choice = 0;
  while (choice != 15 && choice != 16) {
    choice = 0;
    printf("1 - Definir agencia.\n"
           "2 - Definir limite da conta.\n"
           "3 - Definir data de vencimento.\n"
           "4 - Definir conta.\n"
           "5 - Definir CPF.\n"
           "6 - Definir nome.\n"
           "7 - Definir telefone.\n"
           "8 - Definir CEP.\n"
           "9 - Definir numero da casa.\n"
           "10 - Definir o bairro.\n"
           "11 - Definir a cidade.\n"
           "12 - Definir o Estado.\n"
           "13 - Definir data atual.\n"
           "14 - Definir senha.\n"
           "15 - Confirmar informacoes.\n"
           "16 - Voltar.\n"
           "Escolha a opção desejada:\n");
    scanf("%d", &choice);

    if (choice == 1) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da agencia:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 6) == false) {
          printf("O numero de agencia deve possuir apenas 6 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta2.agencia = ver;
        break;
      }
      continue;
    }

    if (choice == 2) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      printf("Digite o limite da conta:\n");
      scanf("%d", &conta2.limite);
      continue;
    }

    if (choice == 3) {
      int verDia, verMes, verAno = 0;
      LimpaBuffer();
      Limpa_Tela();
      printf("Digite a data de vencimento, do limite da conta:\n");
      scanf("%d %d %d", &conta2.vencimento.dia, &conta2.vencimento.mes,
            &conta2.vencimento.ano);
      continue;
    }

    if (choice == 4) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da conta:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 7) == false) {
          printf("O numero da conta deve possuir apenas 7 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta2.numConta = ver;
        break;
      }
      continue;
    }

    if (choice == 5) {
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero do CPF:\n");
        scanf("%d", &conta2.cpf);
        /* if (VerificaCPF(conta2.cpf) == false) { */
        /*   printf("O CPF deve possuir apenas 11 números!\n"); */
        /*   OpcaoInvalida(); */
        /*   continue; */
        /* } */
        break;
      }
      continue;
    }

    if (choice == 6) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o nome:\n");
        scanf("%100[^\n]", ver);
        if (VerificaNome(ver) == false) {
          printf("O nome deve possuir apenas 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta2.nome, ver);
        break;
      }
      continue;
    }

    if (choice == 7) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero de telefone:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 9) == false) {
          printf("O numero de telefone deve possuir apenas 9 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta2.telefone = ver;
        break;
      }
      continue;
    }

    if (choice == 8) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero do CEP:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 8) == false) {
          printf("O numero do CEP deve conter apenas 8 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta2.endereco.cep = ver;
        break;
      }
      continue;
    }

    if (choice == 9) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da casa:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 2) == false) {
          printf("O numero da casa deve possuir apenas 2 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta2.endereco.numCasa = ver;
        break;
      }
      continue;
    }

    if (choice == 10) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o nome do bairro:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(conta2.endereco.bairro) == false) {
          printf("O bairro deve possuir apenas 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta2.endereco.bairro, ver);
        break;
      }
      continue;
    }

    if (choice == 11) {
      char ver[LIM];
      while (1) {
        LimpaBuffer();
        Limpa_Tela();
        printf("Digite a cidade:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("O cidade deve possuir apenas 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta2.endereco.cidade, ver);
        break;
      }
      continue;
    }

    if (choice == 12) {
      char ver[2];
      while (1) {
        LimpaBuffer();
        Limpa_Tela();
        printf("Digite o Estado: (DF - SP - RJ)\n");
        scanf("%2[^\n]", ver);
        if (VerificaEstado(ver) == false) {
          printf("Estado deve conter apenas 2 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta2.endereco.estado, ver);
        break;
      }
      continue;
    }

    if (choice == 13) {
      LimpaBuffer();
      printf("Digite a data de hoje: (dd/mm/aaaa)\n");
      scanf("%d %d %d", &conta2.data.dia, &conta2.data.mes, &conta2.data.ano);
      continue;
    }

    if (choice == 14) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a senha do cliente:\n");
        scanf("%d", &ver);
        if (VerificaSenha(ver) == false) {
          printf("A senha deve possuir de 4 a 6 numeros!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta2.senha = ver;
        break;
      }
      continue;
    }
    if (choice == 15) {
      // so para não apresentar mensagem de erro
      return;
    }
    if (choice == 16) {
      // voltando para o laço
      continue;
    } else {
      OpcaoInvalida();
      continue;
    }
  }
  if (choice == 15) {
    Insere_arquivoCC(conta2, CC);
    printf("Conta criada com sucesso!\n");
    WhileKey();
    return;
  }
  printf("Erro na tentativa de criar a conta!\n");
  WhileKey();
  return;
}
void Definir_Info_Conta_Poupanca(Conta_Poupanca conta) {
  PrintarDarthVaderPequeno();
  int choice = 0;
  while (choice != 13 && choice != 14) {
    choice = 0;
    printf("1 - Definir CPF.\n"
           "2 - Definir agencia.\n"
           "3 - Definir conta.\n"
           "4 - Definir nome.\n"
           "5 - Definir telefone.\n"
           "6 - Definir CEP.\n"
           "7 - Definir o numero da casa.\n"
           "8 - Definir bairro.\n"
           "9 - Definir cidade.\n"
           "10 - Definir Estado.\n"
           "11 - Definir data atual.\n"
           "12 - Definir senha.\n"
           "13 - Confirmar informacoes.\n"
           "14 - Voltar.\n"
           "Escolha a opcao desejada:\n");
    scanf("%d", &choice);
    if (choice == 1) {
      LimpaBuffer();
      while (1) {
        printf("Digite o CPF:\n");
        scanf("%d", &conta.cpf);
        /* if (VerificaCPF(conta.cpf) == false) { */
        /*   printf("O CPF deve possuir apenas 11 digítos!\n"); */
        /*   OpcaoInvalida(); */
        /*   continue; */
        /* } */
        break;
      }
      continue;
    }

    if (choice == 2) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a agencia:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 6) == false) {
          printf("O numero da agencia deve conter apenas 6 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta.agencia = ver;
        break;
      }
      continue;
    }

    if (choice == 3) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da conta:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 7) == false) {
          printf("O numero da conta deve possuir apenas 7 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta.numConta = ver;
        break;
      }
      continue;
    }

    if (choice == 4) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o nome:\n");
        scanf("%100[^\n]", ver);
        if (VerificaNome(ver) == false) {
          printf("O nome deve possuir apenas 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta.nome, ver);
        break;
      }
      continue;
    }

    if (choice == 5) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero de telefone:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 9) == false) {
          printf("O numero de telefone deve possuir apenas 9 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta.telefone = ver;
        break;
      }
      continue;
    }

    if (choice == 6) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o CEP:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 8) == false) {
          printf("O numero do CEP deve conter apenas 8 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta.endereco.cep = ver;
        break;
      }
      continue;
    }

    if (choice == 7) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da casa:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 2) == false) {
          printf("O numero da casa deve possuir apenas 2 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta.endereco.numCasa = ver;
        break;
      }
      continue;
    }

    if (choice == 8) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o bairro:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("O bairro deve conter apenas 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta.endereco.bairro, ver);
        break;
      }
      continue;
    }

    if (choice == 9) {
      char ver[LIM];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a cidade:\n");
        scanf("%100[^\n]", ver);
        if (VerificaCb(ver) == false) {
          printf("O nome da cidade deve conter apenas 100 caracteres!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta.endereco.cidade, ver);
        break;
      }
      continue;
    }

    if (choice == 10) {
      char ver[2];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o Estado: (DF - SP - RJ)\n");
        scanf("%2[^\n]", ver);
        if (VerificaEstado(ver) == false) {
          printf("Estado deve conter apenas 2 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        strcpy(conta.endereco.estado, ver);
        break;
      }
      continue;
    }

    if (choice == 11) {
      LimpaBuffer();
      Limpa_Tela();
      printf("Digite a data de hoje: (dd/mm/aaaa)\n");
      scanf("%d %d %d", &conta.data.dia, &conta.data.mes, &conta.data.ano);
      continue;
    }
    if (choice == 12) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a senha do cliente:\n");
        scanf("%d", &ver);
        if (VerificaSenha(ver) == false) {
          printf("A senha deve conter de 4 a 6 numeros!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        conta.senha = ver;
        break;
      }
      continue;
    } else if (choice == 13) {
      LimpaBuffer();
      if (FunConfirmacao() == true) {
        Insere_arquivoCP(conta, CP);
        return;
      }
      printf("Os dados apresentados nao seram inseridos!\n");
      WhileKey();
      return;
    } else if (choice == 14) {
      return;
    } else {
      OpcaoInvalida();
      continue;
    }
  }
  Insere_arquivoCP(conta, CP);
  printf("Conta criada com sucesso!\n");
  WhileKey();
}

void MFuncionario_Abertura() {
  PrintarDarthVaderPequeno();
  Conta_Poupanca conta;
  Conta_Corrente conta2;
  int escolha;
  do {
    escolha = 0;
    printf("1 - Conta poupanca (CP).\n"
           "2 - Conta corrente (CC).\n"
           "3 - Voltar.\n");
    scanf(" %d", &escolha);

    switch (escolha) {
    case 1:
      Definir_Info_Conta_Poupanca(conta);
      break;
    case 2:
      Definir_Info_Conta_Corrente(conta2);
      break;
    case 3:
      Principal_Funcionario();
      break;
    default:
      OpcaoInvalida();
      WhileKey();
      break;
    }
  } while (escolha != 3);
}
