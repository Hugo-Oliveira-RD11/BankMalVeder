#include "MenuF.h"

int FunConfirmacao() {
  int op;
  do {
    Limpa_Tela();
    printf(
        "Você deseja confirmar esta acao? Digite 1 para sim ou 2 para nao.\n");
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("Acao concluida!\n");
      WhileKey();
      return true;
    case 2:
      printf("Acao nao concluida!");
      WhileKey();
      return false;
    }
  } while (1);
}

void MFuncionario_Encerramento() {
  PrintarDarthVaderPequeno();
  int senha;
  printf("Digite a senha:\n");
  scanf("%d", &senha);
  int verifica = VerificaGerente(senha);
  if (verifica == false) {
    SenhaInvalida();
    return;
  }
  printf("Qual tipo de conta deseja deletar? [1 - Conta corrente || 2 - Conta "
         "poupanca]:\n");
  int escolha = 0;
  scanf("%d", &escolha);
  if (escolha == 1) {
    printf("Digite o numero da conta:\n");
    int conta = 0;
    scanf("%d", &conta);
    DeletarCC(conta);
  }
  if (escolha == 2) {
    printf("Digite o numero da conta:\n");
    int conta = 0;
    scanf("%d", &conta);
    DeletarCP(conta);
  }
}

void MFuncionario_Consulta() {
  PrintarDarthVaderPequeno();
  int escolha = 0, escolhaConta = 0;
  do {
    printf("1 - Consultar conta.\n"
           "2 - Consultar funcionário.\n"
           "3 - Consultar cliente.\n"
           "4 - Voltar.\n");
    scanf("%d", &escolha);
    switch (escolha) {
    case 1:
      do {
        printf("Tipo de Conta: [1 - Conta Poupança | 2 - Conta Corrente]\n");
        scanf("%d", &escolhaConta);
        if (escolhaConta == 1) {
          int flag1 = 0;
          printf("Digite o número da conta ou CPF:\n");
          scanf("%d", &flag1);
          Conta_Poupanca cp = PesquisarClienteCP(flag1, 3);
          SaldoCP saldocp = MostrarSaldoCP(cp.cpf, 1);
          if (PesquisarCliente(flag1) != 0) {
            printf("\t\t==========DADOS DA CONTA POUPANCA==========\n");
            printf("Nome: %s\n"
                   "CPF: %d\n"
                   "Saldo da Conta: %lf\n",
                   cp.nome, cp.cpf, saldocp.saldoAtual);
            break;
          }
        } else if (escolhaConta == 2) {
          int flag11 = 0;
          printf("Digite o número da conta ou CPF:\n");
          scanf("%d", &flag11);
          Conta_Corrente cc = PesquisarClienteCC(flag11, 2);
          SaldoCC saldocc = MostrarSaldoCC(cc.cpf, 1);
          printf("\t\t=============DADOS DA CONTA CORRENTE============\n");
          printf("Nome: %s\n"
                 "CPF: %d\n"
                 "Saldo da Conta: %d\n"
                 "Limite Disponivel: %d"
                 "Data de Vencimento: %d/%d/%d",
                 cc.nome, cc.cpf, saldocc.saldoAtual, cc.limite,
                 cc.vencimento.dia, cc.vencimento.mes, cc.vencimento.ano);

          break;
        } else {
          OpcaoInvalida();
          break;
        }
      } while (1);
    case 2:
      int flag2 = 0;
      printf("Digite o CPF do funcionário para realizar a pesquisa:");
      scanf("%d", &flag2);
      Funcionario func_encontrado = PesquisarFuncionario(flag2, 1);
      if (func_encontrado.codigo != 0) {
        printf("\t\t=========INFORMACOES DO FUNCIONARIO========\n");
        printf("Codigo: %d\n"
               "Cargo: %s\n"
               "Nome: %s\n"
               "CPF: %d\n"
               "Numero da casa: %d\n"
               "Bairro: %s\n"
               "Cidade: %s\n"
               "Estado: %s\n",
               func_encontrado.codigo,
               func_encontrado.cargo == 1 ? "Gerente" : "Subgerente",
               func_encontrado.nome, func_encontrado.cpf,
               func_encontrado.endereco.numCasa,
               func_encontrado.endereco.bairro, func_encontrado.endereco.cidade,
               func_encontrado.endereco.estado);
        break;
      } else {
        printf("Funcionario nao encontrado para o CPF informado\n");
      }
      return;
    case 3:
      int flag3 = 0;
      printf("Digite o CPF do cliente para pesquisa:\n");
      scanf("%d", &flag3);
      if (PesquisarCliente(flag3) == 1) { // se retornar 1 ele tem conta
                                          // poupanca
        Conta_Poupanca cliente_encontrado_cp =
            PesquisarClienteCP(flag3, 1); // vai mandar 1 pra procurar cpf
        printf("\t\t==============DADOS DO CLIENTE=============\n");
        printf("Nome: %s\n"
               "CPF: %d\n"
               "Data de Nascimento: %d/%d/%d\n"
               "Telefone: %d\n"
               "Numero da casa: %d\n"
               "CEP: %d\n"
               "Bairro: %s\n"
               "Cidade: %s\n"
               "Estado: %s\n",
               cliente_encontrado_cp.nome, cliente_encontrado_cp.cpf,
               cliente_encontrado_cp.data.dia, cliente_encontrado_cp.data.mes,
               cliente_encontrado_cp.data.ano, cliente_encontrado_cp.telefone,
               cliente_encontrado_cp.endereco.numCasa,
               cliente_encontrado_cp.endereco.cep,
               cliente_encontrado_cp.endereco.bairro,
               cliente_encontrado_cp.endereco.cidade,
               cliente_encontrado_cp.endereco.estado);
      }
      break;
    case 4:
      return;
    default:
      OpcaoInvalida();
      break;
    }

  } while (true);
}

void MFuncionario_Alterar() {
  PrintarDarthVaderPequeno();
  int choice = 0;
  printf("1 - Alterar conta.\n"
         "2 - Alterar funcionario.\n"
         "3 - Alterar cliente.\n"
         "4 - Voltar.\n");
  scanf("%d", &choice);

  while (choice != 4) {
    switch (choice) {
    case 1:
      Alterar_Conta_Cliente();
      break;
    case 2:
      Alterar_Conta_Funcionario();
      break;
    case 3:
      AlterarCliente();
      break;
    case 4:
      return;
    default:
      OpcaoInvalida();
      return;
    }
  }
}

void MFuncionario_Relatorio() {}

void Principal_Funcionario() {
  PrintarDarthVaderPequeno();
  // Digite_Senha(1); precisa fazer a função de pesquisa.

  int escolha = 0, verifica = 0;
  do {
    printf("1 - Abertura de conta.\n"
           "2 - Encerramento de conta.\n"
           "3 - Consulta de dados.\n"
           "4 - Alterar dados.\n"
           "5 - Cadastro de funcionarios.\n"
           "6 - Gerar relatorios.\n"
           "7 - Sair.\n");

    scanf("%d", &escolha);
    switch (escolha) {
    case 1:
      MFuncionario_Abertura();
      break;
    case 2:
      MFuncionario_Encerramento();
      break;
    case 3:
      MFuncionario_Consulta();
      break;
    case 4:
      MFuncionario_Alterar();
      break;
    case 5:
      MFuncionario_CadastroNovoFuncionario();
      break;
    case 6:
      MFuncionario_Relatorio();
      break;
    case 7:
      Menu_Principal();
      break;
    default:
      OpcaoInvalida();
      WhileKey();
      continue;
      break;
    }
  } while (1);
}
