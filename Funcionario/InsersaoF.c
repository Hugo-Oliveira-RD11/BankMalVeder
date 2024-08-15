
#include "InsersaoF.h"

void MFuncionario_CadastroNovoFuncionario() {
  PrintarDarthVaderPequeno();
  int senha, opcao;

  printf("Digite a senha de gerente (administrador):\n");
  scanf("%d", &senha);
  if (false == VerificaGerente(senha)) {
    return;
  }

  Funcionario fun;
  do {
    printf("\n1 - Definir Codigo do Funcionario\n"
           "2 - Definir Cargo\n"
           "3 - Definir Nome\n"
           "4 - Definir CPF\n"
           "5 - Definir Numero da Casa\n"
           "6 - Definir Bairro\n"
           "7 - Definir Cidade\n"
           "8 - Definir Estado\n"
           "9 - Definir Senha do Funcionario\n"
           "10 - Voltar\n"
           "Escolha a opcao desejada:\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o Codigo do Funcionario:\n");
        scanf("%d", &ver);
        if (VerificaNum(ver, 8) == false) {
          printf("O codigo deve possuir apenas 8 digitos!\n");
          OpcaoInvalida();
          WhileKey();
          continue;
        }
        fun.codigo = ver;
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 2) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o cargo do funcionario\n"
               "1 - Para Gerente\n2 - Para Subgerente:\n");
        scanf("%d", &ver);
        if (ver != 1 && ver != 2) {
          OpcaoInvalida();
          continue;
        }
        fun.cargo = ver;
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 3) {
      char ver[101];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o nome do funcionario:\n");
        scanf("%100[^,],", ver);
        if (VerificaNome(ver) == false) {
          printf("Nome muito pequeno (menor que 3 letras) ou muito grande "
                 "(maior que 100 letras)\n");
                 WhileKey();
          continue;
        }
        strcpy(fun.nome, ver);
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 4) {
      int ver = 0;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o CPF do funcionario:\n");
        scanf("%d", &ver);
        // if (VerificaCPF(ver) == false){
        // printf ("CPF invalido!\n");
        // }
        fun.cpf = ver;
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 5) {
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o numero da casa:\n");
        scanf("%d", &fun.endereco.numCasa);
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 6) {
      char ver[101];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o bairro:\n");
        scanf("%100[^,],", ver);
        if (VerificaCb(ver) == false) {
          printf("Nome do Bairro muito pequeno [menor que 3 letras] ou muito "
                 "grande [maior que 100 letras]\n");
                 WhileKey();
          continue;
        }
        strcpy(fun.endereco.bairro, ver);
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 7) {
      char ver[101];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a cidade:\n");
        scanf("%100[^,],", ver);
        if (VerificaCb(ver) == false) {
          printf("Nome da Cidade muito pequeno [menor que 3 letras] ou muito "
                 "grande [maior que 100 letras]\n");
                 WhileKey();
          continue;
        }
        strcpy(fun.endereco.cidade, ver);
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 8) {
      char ver[3];
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite o Estado [Ex: GO, RJ, SP]\n");
        scanf("%2[^,],", ver);
        if (VerificaEstado(ver) == false) {
          printf("O nome do Estado deve conter apenas a abreviacao [Ex: PI, "
                 "MT, AM]\n");
                 WhileKey();
          continue;
        }
        strcpy(fun.endereco.estado, ver);
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao == 9) {
      int ver;
      LimpaBuffer();
      Limpa_Tela();
      while (1) {
        printf("Digite a senha do funcionario:\n");
        scanf("%d", &ver);
        if (VerificaSenha(ver) == false) {
          printf("A senha do funcionario deve conter obrigatoriamente 6 "
                 "digitos\n");
                 WhileKey();
          continue;
        }
        fun.senha = ver;
        printf("Informacao definida com sucesso\n");
        WhileKey();
        break;
      }
    }

    if (opcao < 1 || opcao > 10) {
      OpcaoInvalida();
      return;
    }
  } while (opcao != 10);
  Insere_arquivoF(fun, sub);
  printf("Novo funcionario inserido com sucesso");
  WhileKey();
}
