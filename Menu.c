#include "Menu.h"

// somente para ter um gerente/adm
void PrimeiroGerente() {
  Funcionario fun;
  fun.cargo = 1;
  strcpy(fun.nome, "Sou o primeiro");
  strcpy(fun.endereco.bairro, "primeiro bairro");
  strcpy(fun.endereco.cidade, "primeira cidade");
  strcpy(fun.endereco.estado, "DF");
  fun.cpf = 1234567;
  fun.codigo = 987654;
  fun.endereco.cep = 1234567;
  fun.senha = 12345;
  fun.telefone = 334567;
  fun.data.dia = 7;
  fun.data.mes = 6;
  fun.data.ano = 2024;
  Insere_arquivoF(fun, sub);
}
void StarWars() {
  /* FILE *fp = popen("telnet towel.blinkenlights.nl", "w+"); */
  /* fclose(fp); */
  printf("teste\n");
  system("telnet towel.blinkenlights.nl");
}

void OpcaoInvalida() { // para o default, talvez colocar um
  printf("Opcao invalida, digite um numero valido!\n");
  WhileKey();
}

void Menu_Principal() {
  int escolha = 0;
  int flag = 0, senha = 0;
  int AGORA = 0; // para a minha loucura
  do {
    Limpa_Tela();
    PrintarDarthVaderGrande();
    PrintarTituloDoBanco();
    PrimeiroGerente();
    printf("1 - Funcionario.\n"
           "2 - Cliente.\n"
           "3 - Sair do Programa.\n");
    scanf("%d", &escolha);
    switch (escolha) {
    case 1:
      printf("Digite o CPF ou o codigo do funcionario:\n");
      scanf("%d", &flag);

      printf("Digite a senha do funcionario:\n");
      scanf("%d", &senha);

      Funcionario fun = PesquisarFuncionario(flag, 3);

      if (fun.codigo == 0 || fun.cpf == 0)
        OpcaoInvalida();
      else {
        if (fun.codigo == flag && fun.senha == senha) {
          Principal_Funcionario();
        } else if (fun.cpf == flag && fun.senha == senha) {
          Principal_Funcionario();
        } else {
          SenhaInvalida();
        }
      }
      break;
    case 2:
      printf("Digite o CPF ou o numero da conta do cliente:\n");
      scanf("%d", &flag);

      printf("Digite a senha do cliente:\n");
      scanf("%d", &senha);
      if (VerificaSenha(senha) == false)
        SenhaInvalida();

      int existe = PesquisarCliente(flag);
      if (0 == existe) {
        printf("Nao existe essa conta ou CPF!\n");
        return;
      } else {
        Principal_Cliente();
      }
      break;
    case 3:
      printf("Encerrando o programa...\n\n");
      PrintarDarthVaiderRealista();
      PrintarFrase();
      WhileKey();
      exit(1);
    case 4:
      Principal_Tools();
      break;
    case 5:
      StarWars();
      break;
    default:
      OpcaoInvalida();
      break;
    }
  } while (1);
}

void LimpaBuffer() {
#if defined(__MINGW32__) || defined(_MSC_VER)
  fflush(stdin);
#else
#include <stdio_ext.h>
  __fpurge(stdin);
  /* while ((getchar()) != '\n' || getchar() == EOF) */
  /*   ; */

#endif
}

void WhileKey() {
#if defined(__MINGW32__) || defined(_MSC_VER)
  system("pause");
#else
  system("read -rsp $'Pressione qualquer tecla para continuar...\n' -n 1 key");
#endif
}

void Limpa_Tela() {
#if defined(__MINGW32__) || defined(_MSC_VER)
  system("cls");
#else
  system("clear");
#endif
}

void Planilha() {
#if defined(__MINGW32__) || defined(_MSC_VER)
  system("start excel extrato.csv");
#else
  system("libreoffice --calc extrato.csv");
#endif
}

int Testando_SenhaCC(int flag, int senha) {
  Conta_Corrente cc = PesquisarClienteCC(cc.senha, 3);
  if (cc.cpf == 0 || cc.numConta == 0) {
    return false;
  } else {
    if (senha == cc.senha && flag == cc.numConta) {
      return true;
    } else if (senha == cc.senha && flag == cc.numConta) {
      return true;
    } else {
      SenhaInvalida();
      return false;
    }
  }
}

int Testando_SenhaCP(int flag, int senha) {
  Conta_Poupanca cp = PesquisarClienteCP(cp.senha, 3);
  if (cp.cpf == 0 || cp.numConta == 0) {
    return false;
  } else {
    if (senha == cp.senha && flag == cp.numConta) {
      return true;
    } else if (senha == cp.senha && flag == cp.numConta) {
      return true;
    } else {
      SenhaInvalida();
      return false;
    }
  }
}

int Testando_SenhaF(int flag, int senha) {
  Funcionario fun = PesquisarFuncionario(fun.senha, 3);
  if (fun.cpf == 0 || fun.codigo == 0) {
    return false;
  } else {
    if (senha == fun.senha && flag == fun.codigo) {
      return true;
    } else if (senha == fun.senha && flag == fun.codigo) {
      return true;
    } else {
      SenhaInvalida();
      return false;
    }
  }
}

int VerificaGerente(int senha) {
  Funcionario fun = PesquisarFuncionario(senha, 3);
  if (fun.cpf == 0 || fun.codigo == 0) {
    return false;
  } else {
    if (senha == fun.senha) {
      return true;
    } else {
      return false;
    }
  }
}

void SenhaInvalida() {
  printf("Senha invalida! Por favor, tente novamente com a senha correta.\n");
}
