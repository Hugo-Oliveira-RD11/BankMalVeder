#include "MenuC.h"

void Principal_Cliente() {
  PrintarDarthVaderPequeno();
  int option = 0;

  do {
    Limpa_Tela();
    printf("1 - Saldo.\n"
           "2 - Deposito.\n"
           "3 - Saque.\n"
           "4 - Extrato.\n"
           "5 - Consultar limite.\n"
           "6 - Sair.");
    scanf("%d", &option);
    switch (option) {
    case 1:
      MCliente_Saldo();
      break;

    case 2:
      LimpaBuffer();
      MCliente_Deposito();
      break;

    case 3:
      LimpaBuffer();
      MCliente_Saque();
      break;

    case 4:
      LimpaBuffer();
      MCliente_Extrato();
      break;

    case 5:
      LimpaBuffer();
      MCliente_Conultar();
      break;

    case 6:
      Menu_Principal();
      break;

    default:
      OpcaoInvalida();
      break;
    }
  } while (option != 6);
}

void MCliente_Saldo() {
  int senha, ver, op;
  printf("Escolha entre conta poupanca ou conta corrente: [1 - Conta poupanca | 2 - Conta corrente]:\n");
  scanf("%d", &op);

  if (op == 1) {
    printf("Digite o CPF ou numero da conta poupanca:\n");
    scanf("%d", &ver);
    printf("Digite a senha:");
    scanf("%d", &senha);
    Conta_Poupanca cp = PesquisarClienteCP(ver, 3);
    if (cp.numConta == 0 || cp.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
      return;
    }
    if (VerificaSenha(senha) == false) {
      OpcaoInvalida();
      return;
    }
    SaldoCP saldocp = MostrarSaldoCP(cp.numConta, 1);
    printf("Seu saldo e de %lf para a conta %d do CPF %d\n", saldocp.saldoAtual,
           saldocp.numConta, saldocp.cpf);
    WhileKey();
    Limpa_Tela();
  }
  if (op == 2) {
    printf("Digite o CPF ou numero da conta corrente:\n");
    scanf("%d", &ver);
    printf("Digite a senha:\n");
    scanf("%d", &senha);
    Conta_Corrente cc = PesquisarClienteCC(ver, 3);
    if (cc.numConta == 0 || cc.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
      return;
    }
    if (VerificaSenha(senha) == false) {
      OpcaoInvalida();
      return;
    }
    SaldoCC saldocc = MostrarSaldoCC(cc.numConta, 1);
    printf("Seu saldo e de %lf e seu limite e de %lf para a conta %d do CPF %d\n",
           saldocc.saldoAtual, saldocc.limite, saldocc.numConta, saldocc.cpf);
    WhileKey();
    Limpa_Tela();
  }
}

void MCliente_Deposito() {
  int senha, ver, op;
  printf("Escolha entre conta corrente ou conta poupanca: [1 - Conta poupanca | 2 - Conta corrente ]:\n");
  scanf("%d", &op);
  if (op == 1) {
    printf("Digite o CPF da conta poupanca:\n");
    scanf("%d", &ver);
    printf("Digite a senha:");
    scanf("%d", &senha);
    Conta_Poupanca cp = PesquisarClienteCP(ver, 3);
    if (cp.numConta == 0 || cp.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
      return;
    }
    if (VerificaSenha(senha) == false) {
      OpcaoInvalida();
      return;
    }
    double deposito = 0;
    SaldoCP saldocp = MostrarSaldoCP(cp.numConta, 1);
    printf("Digite o valor a ser depositado:\nR$:");
    scanf("%lf", &deposito);
    saldocp.antigoSaldo = saldocp.saldoAtual;
    saldocp.saldoAtual = saldocp.saldoAtual + deposito;
    Insere_SaldoCP(saldocp);
    printf("Foi inserido R$%lf na conta poupanca e agora o saldo e: R$%lf, na conta %d",
           deposito, saldocp.saldoAtual, saldocp.numConta);
  }
  if (op == 2) {
    printf("Digite o CPF da conta corrente:\n");
    scanf("%d", &ver);
    printf("Digite a senha:\n");
    scanf("%d", &senha);
    Conta_Corrente cc = PesquisarClienteCC(ver, 3);
    if (cc.numConta == 0 || cc.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
      return;
    }
    if (VerificaSenha(senha) == false) {
      OpcaoInvalida();
      return;
    }
    double deposito = 0;
    SaldoCC saldocc = MostrarSaldoCC(cc.numConta, 1);
    printf("Digite o valor a ser depositado:\nR$:");
    scanf("%lf", &deposito);
    saldocc.antigoSaldo = saldocc.saldoAtual;
    saldocc.saldoAtual = saldocc.saldoAtual + deposito;
    Insere_SaldoCC(saldocc);
    printf("O valor de R$%lf foi depositado na conta %d corrente.\n", deposito,
           saldocc.numConta);
  }
}

void MCliente_Saque() {
  int senha, ver, op;
  printf("Escolha entre conta corrente ou conta poupanca: [1 - Conta poupanca | 2 - Conta poupanca]:\n");
  scanf("%d", &op);
  if (op == 1) {
    printf("Digite o CPF da conta poupanca:\n");
    scanf("%d", &ver);
    printf("Digite a senha:");
    scanf("%d", &senha);
    Conta_Poupanca cp = PesquisarClienteCP(ver, 3);
    if (cp.numConta == 0 || cp.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
      return;
    }
    if (VerificaSenha(senha) == false) {
      OpcaoInvalida();
      return;
    }
    double saque = 0;
    SaldoCP saldocp = MostrarSaldoCP(cp.numConta, 1);
    printf("Digite o valor a ser sacado:\nR$:");
    scanf("%lf", &saque);
    if (saque > saldocp.saldoAtual) {
      printf("Voce esta tentando sacar um valor superior, da conta %d com o saldo atual de %lf",
             saldocp.numConta, saldocp.saldoAtual);
      return;
    }
    saldocp.antigoSaldo = saldocp.saldoAtual;
    saldocp.saldoAtual -= saque;
    Insere_SaldoCP(saldocp);
    printf("Foi retirado R$%lf da conta poupanca e agora o saldo e: R$%lf, na conta %d",
           saque, saldocp.saldoAtual, saldocp.numConta);
    return;
  }
  if (op == 2) {
    printf("Digite o CPF da conta corrente:\n");
    scanf("%d", &ver);
    printf("Digite a senha:\n");
    scanf("%d", &senha);
    Conta_Corrente cc = PesquisarClienteCC(ver, 3);
    if (cc.numConta == 0 || cc.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
    }
    double saque = 0;
    SaldoCC saldocc = MostrarSaldoCC(cc.numConta, 1);
    printf("Digite o valor a ser depositado:\nR$:");
    scanf("%lf", &saque);
    if (saque > saldocc.saldoAtual || saque > saldocc.limite) {
      printf("Na conta %d nao e possivel sacar porque o valor e superior ao saldo com %lf e o limite e de %lf\n",
             saldocc.numConta, saldocc.saldoAtual, saldocc.limite);
      WhileKey();
      Limpa_Tela();
      return;
    }
    saldocc.antigoSaldo = saldocc.saldoAtual;
    saldocc.saldoAtual -= saque;
    Insere_SaldoCC(saldocc);
    printf("Foii sacado R$%lf e agora o saldo e: R$%lf, na conta %d", saque,
           saldocc.saldoAtual, saldocc.numConta);
    return;
  }
}

void MCliente_Extrato() {
  int senha, ver, op;
  printf("Escolha entre conta corrente ou conta poupanca: [1 - Conta poupanca | 2 - Conta corrente]:\n");
  scanf("%d", &op);
  if (op == 1) {
    printf("Digite o CPF ou numero da conta poupanca:\n");
    scanf("%d", &ver);
    printf("Digite a senha:");
    scanf("%d", &senha);
    Conta_Poupanca cp = PesquisarClienteCP(ver, 3);
    if (cp.numConta == 0 || cp.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
      return;
    }
    if (VerificaSenha(senha) == false) {
      OpcaoInvalida();
      return;
    }
    ExtratoSaldoCP(cp.numConta, 1);
    return;
  }
  if (op == 2) {
    printf("Digite o CPF ou numero da conta corrente:\n");
    scanf("%d", &ver);
    printf("Digite a senha:\n");
    scanf("%d", &senha);
    Conta_Corrente cc = PesquisarClienteCC(ver, 3);
    if (cc.numConta == 0 || cc.cpf == 0) {
      printf("Nao existe a conta!\n");
      WhileKey();
      Limpa_Tela();
      return;
    }
    if (VerificaSenha(senha) == false) {
      OpcaoInvalida();
      return;
    }
    ExtratoSaldoCC(cc.numConta, 1);
    return;
  }
}

void MCliente_Conultar() {
  int senha, ver;
  printf("Digite o CPF ou numero da conta corrente:\n");
  scanf("%d", &ver);
  printf("Digite a senha:");
  scanf("%d", &senha);
  Conta_Corrente cc = PesquisarClienteCC(ver, 3);
  if (cc.numConta == 0 || cc.cpf == 0) {
    printf("Nao existe a conta!\n");
    WhileKey();
    Limpa_Tela();
    return;
  }
  if (VerificaSenha(senha) == false) {
    OpcaoInvalida();
    return;
  }
  double limite = ContaLimite(cc);
  printf("Seu limite e de %lf", limite);
  return;
}
