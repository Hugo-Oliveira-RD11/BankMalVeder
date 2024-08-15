#include "../GLOBAL.h"

//!!!!DESCOBRIR PQ O CLION TA DIZENDO QUE AS FUNCOES JA FORAM DECLARADAS!!!!
void Alterar_Data_Vencimento(Conta_Corrente conta_corrente) {
  int verDia = 0, verMes = 0, verAno = 0;
  printf("Data de vencimento atual: %d/%d/%d\n", conta_corrente.data.dia,
         conta_corrente.data.mes, conta_corrente.data.ano);

  printf("Digite a nova data de vencimento: (dd/mm/aaaa)\n");
  scanf("%d %d %d", &verDia, &verMes, &verAno);
  DeletarCC(conta_corrente.cpf);
  Insere_arquivoCC(conta_corrente, CC);
}
void Alterar_ContaCorrente(
    Conta_Corrente nova_conta_corrente,
    Conta_Corrente antiga_conta_corrente) { // PASSAR TUDO EXCETO LIMITE PQ ELE
                                            // JA FOI DEFINIDO
  nova_conta_corrente.cpf = antiga_conta_corrente.cpf;
  strcpy(nova_conta_corrente.nome, antiga_conta_corrente.nome);
  nova_conta_corrente.numConta = antiga_conta_corrente.numConta;
  nova_conta_corrente.agencia = antiga_conta_corrente.agencia;
  nova_conta_corrente.data.dia = antiga_conta_corrente.data.dia;
  nova_conta_corrente.data.mes = antiga_conta_corrente.data.mes;
  nova_conta_corrente.data.ano = antiga_conta_corrente.data.ano;
  nova_conta_corrente.telefone = antiga_conta_corrente.telefone;
  nova_conta_corrente.endereco.cep = nova_conta_corrente.endereco.cep;
  nova_conta_corrente.endereco.numCasa = antiga_conta_corrente.endereco.numCasa;
  strcpy(nova_conta_corrente.endereco.bairro,
         antiga_conta_corrente.endereco.bairro);
  strcpy(nova_conta_corrente.endereco.cidade,
         antiga_conta_corrente.endereco.cidade);
  strcpy(nova_conta_corrente.endereco.estado,
         antiga_conta_corrente.endereco.estado);
  DeletarCC(antiga_conta_corrente.numConta);
  Insere_arquivoCC(nova_conta_corrente, CC);
}
void Conta_Corrente_Para_Poupanca(int cpf) {

  Conta_Corrente conta_corrente = PesquisarClienteCC(cpf, 1);
  Conta_Poupanca nova_conta_poupanca;
  nova_conta_poupanca.cpf = conta_corrente.cpf;
  strcpy(nova_conta_poupanca.nome, conta_corrente.nome);
  nova_conta_poupanca.numConta = conta_corrente.numConta;
  nova_conta_poupanca.agencia = conta_corrente.agencia;
  nova_conta_poupanca.data.dia = conta_corrente.data.dia;
  nova_conta_poupanca.data.mes = conta_corrente.data.mes;
  nova_conta_poupanca.data.ano = conta_corrente.data.ano;
  nova_conta_poupanca.telefone = conta_corrente.telefone;
  nova_conta_poupanca.endereco.cep = conta_corrente.endereco.cep;
  nova_conta_poupanca.endereco.numCasa = conta_corrente.endereco.numCasa;
  strcpy(nova_conta_poupanca.endereco.bairro, conta_corrente.endereco.bairro);
  strcpy(nova_conta_poupanca.endereco.cidade, conta_corrente.endereco.cidade);
  strcpy(nova_conta_poupanca.endereco.estado, conta_corrente.endereco.estado);
  DeletarCC(conta_corrente.numConta);
  Insere_arquivoCP(nova_conta_poupanca, CP);
}
void Conta_Poupanca_Para_Corrente(int cpf) {
  int lim = 0, verDia = 0, verMes = 0, verAno = 0;
  Conta_Corrente nova_conta_corrente;
  printf("Digite o limite da conta corrente:\n");
  scanf("%d", &lim);

  printf("Digite a data de vencimento da fatura: (dd/mmm/aaaa)\n");
  scanf("%d %d %d", &verDia, &nova_conta_corrente.vencimento.mes,
        &nova_conta_corrente.vencimento.ano);
  if (VerificaNum(verDia, 2) == false) {
    printf("O dia deve ter 2 digitos!\n");
    WhileKey();
    return;
  }
  if (VerificaNum(verMes, 2) == false) {
    printf("O mes deve ter 2 digitos!\n");
    WhileKey();
    return;
  }
  if (VerificaNum(verAno, 4) == false) {
    printf("O ano deve ter 4 digtos!\n");
    WhileKey();
    return;
  }
  nova_conta_corrente.vencimento.dia = verDia;
  nova_conta_corrente.vencimento.mes = verMes;
  nova_conta_corrente.vencimento.ano = verAno;

  Conta_Poupanca conta_poupanca = PesquisarClienteCP(cpf, 1);
  nova_conta_corrente.cpf = conta_poupanca.cpf;
  strcpy(nova_conta_corrente.nome, conta_poupanca.nome);
  nova_conta_corrente.numConta = conta_poupanca.numConta;
  nova_conta_corrente.agencia = conta_poupanca.agencia;
  nova_conta_corrente.data.dia = conta_poupanca.data.dia;
  nova_conta_corrente.data.mes = conta_poupanca.data.mes;
  nova_conta_corrente.data.ano = conta_poupanca.data.ano;
  nova_conta_corrente.telefone = conta_poupanca.telefone;
  nova_conta_corrente.endereco.cep = conta_poupanca.endereco.cep;
  nova_conta_corrente.endereco.numCasa = conta_poupanca.numConta;
  strcpy(nova_conta_corrente.endereco.bairro, conta_poupanca.endereco.bairro);
  strcpy(nova_conta_corrente.endereco.cidade, conta_poupanca.endereco.cidade);
  strcpy(nova_conta_corrente.endereco.estado, conta_poupanca.endereco.estado);

  DeletarCP(conta_poupanca.numConta);
  Insere_arquivoCC(nova_conta_corrente, CC);
}
void Alterar_Conta_Cliente() { // FUNCAO PARA DIGITAR SENHA DE ADM, USAR
                               // FUNCAO DE SENHA INVALIDA TBM
                               // alterar o nome da função
  int senha = 0, cpf = 0;
  printf("Digite a senha de administrador:\n");
  scanf("%d", &senha);

  if (VerificaGerente(senha) == 0) {
    SenhaInvalida();
    return;
  } else {
    printf("Digite seu CPF:\n");
    scanf("%d", &cpf);

    int ver = PesquisarCliente(cpf);
    if (ver == 0) {
      printf("CPF invalido!\n");
      return;
    }

    if (ver == 1) { // se for 1 é conta poupança
      int option;
      printf("Deseja alterar sua conta poupanca para conta corrente?\n"
             "1 - Sim.\n"
             "2 - Nao.\n"
             "3 - Voltar.\n");
      scanf("%d", &option);

      switch (option) {
      case 1:
        Conta_Poupanca_Para_Corrente(cpf);
        printf("Sua conta poupanca foi alterada para conta corrente com sucesso!\n");
        return;
      case 2:
        printf("Operacao cancelada.\n");
        return;
      case 3:
        return;
      default:
        OpcaoInvalida();
        return;
      }
    }
    if (ver == 2) { // se for 2 é conta corrente
      int option;
      printf("1 - Alterar conta corrente para conta poupanca.\n"
             "2 - Alterar limite disponivel.\n"
             "3 - Alterar data de vencimento.\n"
             "4 - Voltar.\n");
      scanf("%d", &option);

      if (option == 1) {
        printf("Deseja alterar sua conta corrente para conta poupanca?\n"
               "1 - Sim.\n2 - Nao.\n3 - Voltar.\n");
        scanf("%d", &option);

        switch (option) {
        case 1:
          Conta_Corrente_Para_Poupanca(cpf);
          printf("Sua conta corrente foi alterada para conta poupanca com sucesso!\n");
          return;
        case 2:
          printf("Operacao cancelada.\n");
          return;
        case 3:
          return;
        default:
          OpcaoInvalida();
          return;
        }
      }

      if (option == 2) {
        Conta_Corrente antiga_conta_corrente = PesquisarClienteCC(cpf, 1);
        Conta_Corrente nova_conta_corrente;
        printf("Seu limite disponivel e de R$%d. Digite o novo limite:\n",
               antiga_conta_corrente.limite);
        scanf("%d", &nova_conta_corrente.limite);
        Alterar_Data_Vencimento(nova_conta_corrente);
        printf("Limite alterado com sucesso.\n");
        return;
        /*1 - PROCURAR O LIMITE DA CONTA CORRENTE NO ARQUIVO
          2 - INFORMAR O LIMITE ATUAL E PEDIR PRA PESSOA DIGITAR O NOVO LIMITE
          3 - PASSAR O LIMITE NOVO PRO ARQUIVO
          4 - APAGAR O VELHO LIMITE*/
      }

      if (option == 3) {
        /*1 - PROCURAR DATA DE VENCIMENTO NO ARQUIVO
          2 - INFORMAR A DATA ATUAL E PEDIR PRA PESSOA DIGITAR A NOVA DATA
          3 - PASSAR A NOVA DATA PRO ARQUIVO
          4 - APAGAR A VELHA DATA*/
      }

      if (option == 4) {
        return;
      }
    }
    if (PesquisarCliente(cpf) == 3) { // se for 3 é para ambos as contas
      Limpa_Tela();
      int option;
      printf("Voce possui duas contas diferentes. Uma conta corrente e uma conta poupanca.\n"
             "1 - Para alterar sua conta poupanca para conta corrente.\n"
             "2 - Para alterar sua conta corrente para conta poupanca.\n"
             "3 - Voltar");
      scanf("%d", &option);

      switch (option) {
      case 1:
        Conta_Poupanca_Para_Corrente(cpf);
        printf("Sua conta poupanca foi alterada para conta corrente com sucesso!\n");
        WhileKey();
        return;
      case 2:
        Conta_Corrente_Para_Poupanca(cpf);
        printf("Sua conta corrente foi alterada para conta poupanca com sucesso!\n");
        WhileKey();
        return;
      case 3:
        return;
      default:
        OpcaoInvalida();
        WhileKey();
        return;
      }
    }
  }
}
