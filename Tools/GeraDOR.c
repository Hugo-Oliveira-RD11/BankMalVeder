//
// Created by hugo on 12/06/24.
//

#include "./GeraDOR.h"
int global = 0;

void definirGlobal() {
  printf("digite um numero para o global>\n");
  scanf("%d", &global);
}

void Gera_DOR(int i) {
  global = i;
  Conta_Corrente cc[i];
  Conta_Poupanca cp[i];
  Funcionario fun[i];
  SaldoCC saldoCC[i];
  SaldoCP saldoCP[i];
  for (int j = 1, k = 100; j < i; j++, k++) {

    // conta corrente
    cc[j].agencia = j;
    cc[j].cpf = j;
    cc[j].data.dia = 13;
    cc[j].data.mes = 13;
    cc[j].data.ano = 1313;
    cc[j].vencimento.dia = 14;
    cc[j].vencimento.mes = 14;
    cc[j].vencimento.ano = 1414;
    cc[j].limite = j;
    cc[j].numConta = j;
    cc[j].telefone = j;
    cc[j].senha = 12345;
    strcpy(cc[j].nome, "E SO UM TESTE FI!! CC");
    strcpy(cc[j].endereco.bairro, "bairro dos testes!!");
    strcpy(cc[j].endereco.cidade, "cidade dos testes!!");
    strcpy(cc[j].endereco.estado, "TS");
    cc[j].endereco.cep = j;
    cc[j].endereco.numCasa = j;

    Insere_arquivoCC(cc[j], CC);

    // conta poupança
    cp[j].agencia = j;
    cp[j].cpf = j;
    cp[j].numConta = j;
    cp[j].telefone = j;
    cp[j].data.dia = 15;
    cp[j].data.mes = 15;
    cp[j].data.ano = 1515;
    cp[j].senha = 54321;
    cp[j].endereco.cep = j;
    cp[j].endereco.numCasa = j;
    strcpy(cp[j].nome, "E SO UM TESTE FI!! CP");
    strcpy(cp[j].endereco.bairro, "bairro dos testes!!");
    strcpy(cp[j].endereco.cidade, "cidade dos testes!!");
    strcpy(cp[j].endereco.estado, "TS");

    Insere_arquivoCP(cp[j], CP);

    // funcionario
    fun[j].cpf = j;
    fun[j].codigo = j;
    fun[j].telefone = j;
    fun[j].data.dia = 15;
    fun[j].data.mes = 15;
    fun[j].data.ano = 1515;
    fun[j].senha = 54321;
    strcpy(fun[j].nome, "E SO UM TESTE FI!! FN");
    strcpy(fun[j].endereco.bairro, "bairro dos testes!!");
    strcpy(fun[j].endereco.cidade, "cidade dos testes!!");
    strcpy(fun[j].endereco.estado, "TS");
    fun[j].endereco.cep = j;
    fun[j].endereco.numCasa = j;

    Insere_arquivoF(fun[j], sub);

    // Saldo Conta corrente
    saldoCC[j].antigoSaldo = j;
    saldoCC[j].saldoAtual = k;
    saldoCC[j].cpf = cc[j].cpf;
    saldoCC[j].numConta = cc[j].numConta;
    saldoCC[j].limite = cc[j].limite;
    saldoCC[j].data.dia = j;
    saldoCC[j].data.mes = j;
    saldoCC[j].data.ano = j;

    Insere_SaldoCC(saldoCC[j]);

    // saldo poupanca
    saldoCP[j].antigoSaldo = j;
    saldoCP[j].saldoAtual = k;
    saldoCP[j].cpf = cc[j].cpf;
    saldoCP[j].numConta = cc[j].numConta;
    saldoCP[j].data.dia = j;
    saldoCP[j].data.mes = j;
    saldoCP[j].data.ano = j;

    Insere_SaldoCP(saldoCP[j]);
  }
}

void Pesquisar(int i) {
  Conta_Corrente cc = PesquisarClienteCC(i, 3);
  Conta_Poupanca cp = PesquisarClienteCP(i, 3);
  Funcionario fun = PesquisarFuncionario(i, 3);
  MostrarSaldoCC(i, i);
  MostrarSaldoCP(i, i);

  printf("conta: %d, CPF: %d\n", cc.numConta, cc.cpf);
  printf("conta: %d, CPF: %d\n", cp.numConta, cp.cpf);
  printf("conta: %d, CPF: %d\n", fun.codigo, fun.cpf);
}

void Deletar(int i) {
  /* Conta_Corrente cc = PesquisarClienteCC(i, 3); */
  Conta_Poupanca cp = PesquisarClienteCP(i, 3);
  /* Funcionario F = PesquisarFuncionario(i,3); */

  /* DeletarCC(cc.numConta); */
  DeletarCP(cp.numConta);
  /* DeletarF(F.codigo); */
}

void DeletarTUDO() {
  FILE *fl = fopen("ClienteCC.txt", "w+");
  FILE *fl1 = fopen("ClienteCP.txt", "w+");
  FILE *fl2 = fopen("Funcionarios.txt", "w+");
  FILE *fl3 = fopen("SaldosCC.txt", "w+");
  FILE *fl4 = fopen("SaldosCP.txt", "w+");
}

void Principal_Tools() {
  int a = 0, num = 0;
  Limpa_Tela();
  definirGlobal();
  printf("parabens, vc achou um ferramnte de facilidade do codigo\n1 - gerador "
         "de todas as contas automaticas\n2 - deletar todas as contas\n");
  scanf("%d", &a);

  if (a == 1) {
    printf("vc irar querer quantas contas?\n");
    scanf("%d", &num);
    Gera_DOR(num);
  }
  if (a == 2) {
    printf("deseja deletar tudo [1 - para sim/2 - para escolhar]\n");
    scanf("%d", &num);
    if (num == 1) {
      DeletarTUDO();
      return;
    } else {
      int i;
      printf("digite um numero para excluir\n");
      scanf("%d", &i);
      Deletar(i);
    }
  }
  if (a == 3) {
    int i;
    printf("digite o numero para a pesquisa\n");
    scanf("%d", &i);

    Pesquisar(i);
  }
}
