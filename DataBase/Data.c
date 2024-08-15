#include "Data.h"
// definindo os arquivos e tipos

// MAIOR DOR DA VIDA

char es[2];
#define temp 7

void PRINTANDO_A_MERDA(Conta_Corrente cc);

FILE *Abrindo_Arquivo(int escolha) {
  FILE *fl;
  switch (escolha) {
  case sub:
    fl = fopen("Funcionarios.txt", "a+");
    break;
  case CP:
    fl = fopen("ClienteCP.txt", "a+");
    break;
  case CC:
    fl = fopen("ClienteCC.txt", "a+");
    break;
  case temp:
    fl = fopen("temp.txt", "w+");
  }
  return fl;
}

void Fechando_Arquivo(FILE *fl) { fclose(fl); }

void Insere_arquivoF(Funcionario f, int op) {
  FILE *fl = Abrindo_Arquivo(op);
  fprintf(fl,
          "Codigo: %d,\n"
          "Cargo: %d,\n"
          "CPF: %d,\n"
          "Nome: %s,\n"
          "Telefone: %d,\n"
          "Senha: %d,\n"
          "Estado:%s,\n"
          "Cep: %d,\n"
          "Numero da casa: %d,\n"
          "Bairro %s,\n"
          "Cidade: %s,\n"
          "Nascimento: %d/%d/%d\n\n",
          f.codigo, f.cargo, f.cpf, f.nome, f.telefone, f.senha,
          f.endereco.estado, f.endereco.cep, f.endereco.numCasa,
          f.endereco.bairro, f.endereco.cidade, f.data.ano, f.data.mes,
          f.data.dia);
  Fechando_Arquivo(fl);
}

void Insere_arquivoCC(Conta_Corrente c, int op) {
  FILE *a = Abrindo_Arquivo(op);
  fprintf(a,
          "N conta: %d,\n"
          "agencia : %d,\n"
          "Data de Vencimento: %d/%d/%d,\n"
          "Nome: %s,\n"
          "CPF: %d,\n"
          "Nascimento: %d/%d/%d,\n"
          "Estado: %s,\n"
          "Cep: %d,\n"
          "Numero da casa: %d,\n"
          "Bairro: %s,\n"
          "Cidade: %s,\n"
          "Telefone: %d,\n"
          "Senha: %d,\n\n",
          c.numConta, c.agencia, c.vencimento.dia, c.vencimento.mes,
          c.vencimento.ano, c.nome, c.cpf, c.data.ano, c.data.mes, c.data.dia,
          c.endereco.estado, c.endereco.cep, c.endereco.numCasa,
          c.endereco.bairro, c.endereco.cidade, c.telefone, c.senha);

  fclose(a);

  SaldoCC saldo;
  saldo.numConta = c.numConta;
  saldo.cpf = c.cpf;
  saldo.limite = c.limite;
  saldo.saldoAtual = 0;
  saldo.antigoSaldo = 0;
  saldo.data.dia = c.data.dia;
  saldo.data.mes = c.data.mes;
  saldo.data.ano = c.data.ano;

  Insere_SaldoCC(saldo);
}

void Insere_arquivoCP(Conta_Poupanca c, int op) {

  FILE *a = Abrindo_Arquivo(op);

  fprintf(a,
          "N conta: %d,\n"
          "agencia : %d,\n"
          "Nome: %s,\n"
          "CPF: %d,\n"
          "Nascimento: %d/%d/%d,\n"
          "Estado: %s,\n"
          "Cep: %d,\n"
          "Numero da casa: %d,\n"
          "Bairro: %s,\n"
          "Cidade: %s,\n"
          "Telefone: %d,\n"
          "Senha: %d,\n\n",
          c.numConta, c.agencia, c.nome, c.cpf, c.data.ano, c.data.mes,
          c.data.dia, c.endereco.estado, c.endereco.cep, c.endereco.numCasa,
          c.endereco.bairro, c.endereco.cidade, c.telefone, c.senha);

  Fechando_Arquivo(a);

  SaldoCP saldo;
  saldo.numConta = c.numConta;
  saldo.cpf = c.cpf;
  saldo.antigoSaldo = 0;
  saldo.saldoAtual = 0;
  saldo.data.dia = c.data.dia;
  saldo.data.mes = c.data.mes;
  saldo.data.ano = c.data.ano;

  Insere_SaldoCP(saldo);
}

// TA FUNCIONANDO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
// se return = 0 e porque a pesquisa falhou.
Conta_Corrente PesquisarClienteCC(int flag, int op) {
  Conta_Corrente cc;
  FILE *fl = Abrindo_Arquivo(CC);
  while (17 == fscanf(fl,
                      "N conta: %d,\n"
                      "agencia : %d,\n"
                      "Data de Vencimento: %d/%d/%d,\n"
                      "Nome: %100[^,],\n"
                      "CPF: %d,\n"
                      "Nascimento: %d/%d/%d,\n"
                      "Estado: %2[^,],\n"
                      "Cep: %d,\n"
                      "Numero da casa: %d,\n"
                      "Bairro: %100[^,],\n"
                      "Cidade: %100[^,],\n"
                      "Telefone: %d,\n"
                      "Senha: %d,\n\n",
                      &cc.numConta, &cc.agencia, &cc.vencimento.dia,
                      &cc.vencimento.mes, &cc.vencimento.ano, cc.nome, &cc.cpf,
                      &cc.data.ano, &cc.data.mes, &cc.data.dia,
                      cc.endereco.estado, &cc.endereco.cep,
                      &cc.endereco.numCasa, cc.endereco.bairro,
                      cc.endereco.cidade, &cc.telefone, &cc.senha)) {

    if (op == 1 || op == 3) {
      if (cc.cpf == flag) {
        return cc;
      }
    }
    if (op == 2 || op == 3) {
      if (cc.numConta == flag) {
        return cc;
      }
    }
    if (op == 3) {
      if (cc.senha == flag) {
        return cc;
      }
    }
  }
  Fechando_Arquivo(fl);
  cc.cpf = 0;
  cc.numConta = 0;
  return cc;
}

// se return = 0 e porque a pesquisa falhou.
Conta_Poupanca PesquisarClienteCP(int flag, int op) {
  Conta_Poupanca cp;
  FILE *fl = Abrindo_Arquivo(CP);
  while (14 == fscanf(fl,
                      "N conta: %d,\n"
                      "agencia : %d,\n"
                      "Nome: %100[^,],\n"
                      "CPF: %d,\n"
                      "Nascimento: %d/%d/%d,\n"
                      "Estado: %2[^,],\n"
                      "Cep: %d,\n"
                      "Numero da casa: %d,\n"
                      "Bairro: %100[^,],\n"
                      "Cidade: %100[^,],\n"
                      "Telefone: %d,\n"
                      "Senha: %d,\n\n",
                      &cp.numConta, &cp.agencia, cp.nome, &cp.cpf, &cp.data.ano,
                      &cp.data.mes, &cp.data.dia, cp.endereco.estado,
                      &cp.endereco.cep, &cp.endereco.numCasa,
                      cp.endereco.bairro, cp.endereco.cidade, &cp.telefone,
                      &cp.senha)) {

    if (op == 1 || op == 3) {
      if (cp.cpf == flag) {
        return cp;
      }
    }
    if (op == 2 || op == 3) {
      if (cp.numConta == flag) {
        return cp;
      }
    }
    if (op == 3) {
      if (cp.senha == flag) {
        return cp;
      }
    }
  }
  Fechando_Arquivo(fl);
  cp.cpf = 0;
  cp.numConta = 0;
  return cp;
}

Funcionario PesquisarFuncionario(int flag, int op) {
  Funcionario fn;
  FILE *fl = Abrindo_Arquivo(sub);
  while (14 == fscanf(fl,
                      "Codigo: %d,\n"
                      "Cargo: %d,\n"
                      "CPF: %d,\n"
                      "Nome: %100[^,],\n"
                      "Telefone: %d,\n"
                      "Senha: %d,\n"
                      "Estado:%2[^,],\n"
                      "Cep: %d,\n"
                      "Numero da casa: %d,\n"
                      "Bairro %100[^,],\n"
                      "Cidade: %100[^,],\n"
                      "Nascimento: %d/%d/%d\n",
                      &fn.codigo, &fn.cargo, &fn.cpf, fn.nome, &fn.telefone,
                      &fn.senha, fn.endereco.estado, &fn.endereco.cep,
                      &fn.endereco.numCasa, fn.endereco.bairro,
                      fn.endereco.cidade, &fn.data.ano, &fn.data.mes,
                      &fn.data.dia)) {
    if (op == 1 || op == 3) {
      if (fn.cpf == flag) {
        return fn;
      }
    }
    if (op == 2 || op == 3) {
      if (fn.codigo == flag) {
        return fn;
      }
    }
    if (op == 3) {
      if (fn.senha == flag) {
        return fn;
      }
    }
  }
  Fechando_Arquivo(fl);
  fn.cpf = 0;
  fn.codigo = 0;
  return fn;
}

// ser retornar 0 não existe (404)
// se retornar 1 e CP
// se retornar 2 e CC
// ser retronar 3 tem dois
// FAZ PESQUISA NOS DOIS AGORA.
int PesquisarCliente(int flag) {
  Conta_Corrente cc = PesquisarClienteCC(flag, 1);
  Conta_Poupanca cp = PesquisarClienteCP(flag, 1);
  if (cc.cpf == flag || cc.numConta == flag) {
    if (cp.cpf == flag || cc.numConta == flag)
      return 3;
    else
      return 2;
  } else if (cp.cpf == flag || cc.numConta == flag) {
    return 1;
  } else {
    return false;
  }
}

void DeletarCC(int flag) {
  Conta_Corrente cc;
  Conta_Corrente del = PesquisarClienteCC(flag, 3);
  int achou = 0;
  if (del.numConta == 0 || del.cpf == 0) {
    printf("essa conta não existe, essa conta corrente\n");
    return;
  }

  FILE *fl = Abrindo_Arquivo(CC);

  FILE *delete = Abrindo_Arquivo(temp);
  while (17 == fscanf(fl,
                      "N conta: %d,\n"
                      "agencia : %d,\n"
                      "Data de Vencimento: %d/%d/%d,\n"
                      "Nome: %100[^,],\n"
                      "CPF: %d,\n"
                      "Nascimento: %d/%d/%d,\n"
                      "Estado: %2[^,],\n"
                      "Cep: %d,\n"
                      "Numero da casa: %d,\n"
                      "Bairro: %100[^,],\n"
                      "Cidade: %100[^,],\n"
                      "Telefone: %d,\n"
                      "Senha: %d,\n\n",
                      &cc.numConta, &cc.agencia, &cc.vencimento.dia,
                      &cc.vencimento.mes, &cc.vencimento.ano, cc.nome, &cc.cpf,
                      &cc.data.ano, &cc.data.mes, &cc.data.dia,
                      cc.endereco.estado, &cc.endereco.cep,
                      &cc.endereco.numCasa, cc.endereco.bairro,
                      cc.endereco.cidade, &cc.telefone, &cc.senha)) {
    if (del.numConta == cc.numConta) {
      printf("conta encontrada com o numero de %d\n", cc.numConta);
      achou = 1;
    }
    if (del.numConta != cc.numConta) {
      fprintf(delete,
              "N conta: %d,\n"
              "agencia : %d,\n"
              "Data de Vencimento: %d/%d/%d,\n"
              "Nome: %s,\n"
              "CPF: %d,\n"
              "Nascimento: %d/%d/%d,\n"
              "Estado: %s,\n"
              "Cep: %d,\n"
              "Numero da casa: %d,\n"
              "Bairro: %s,\n"
              "Cidade: %s,\n"
              "Telefone: %d,\n"
              "Senha: %d,\n\n",
              cc.numConta, cc.agencia, cc.vencimento.dia, cc.vencimento.mes,
              cc.vencimento.ano, cc.nome, cc.cpf, cc.data.ano, cc.data.mes,
              cc.data.dia, cc.endereco.estado, cc.endereco.cep,
              cc.endereco.numCasa, cc.endereco.bairro, cc.endereco.cidade,
              cc.telefone, cc.senha);
    }
  }

  // apagar o extrato
  Fechando_Arquivo(delete);
  Fechando_Arquivo(fl);
  remove("ClienteCC.txt");
  rename("temp.txt", "ClienteCC.txt");
}

void DeletarCP(int flag) {
  Conta_Poupanca cp;
  Conta_Poupanca del = PesquisarClienteCP(flag, 3);

  if (del.numConta == 0 || del.cpf == 0) {
    printf("essa conta não existe, essa conta poupanca\n");
    return;
  }
  FILE *fl = Abrindo_Arquivo(CP);
  FILE *delete = Abrindo_Arquivo(temp);

  int Achou = 0;
  while (14 == fscanf(fl,
                      "N conta: %d,\n"
                      "agencia : %d,\n"
                      "Nome: %100[^,],\n"
                      "CPF: %d,\n"
                      "Nascimento: %d/%d/%d,\n"
                      "Estado: %2[^,],\n"
                      "Cep: %d,\n"
                      "Numero da casa: %d,\n"
                      "Bairro: %100[^,],\n"
                      "Cidade: %100[^,],\n"
                      "Telefone: %d,\n"
                      "Senha: %d,\n\n",
                      &cp.numConta, &cp.agencia, cp.nome, &cp.cpf, &cp.data.ano,
                      &cp.data.mes, &cp.data.dia, cp.endereco.estado,
                      &cp.endereco.cep, &cp.endereco.numCasa,
                      cp.endereco.bairro, cp.endereco.cidade, &cp.telefone,
                      &cp.senha)) {
    if (flag == cp.numConta) {
      Achou = 1;
      printf("achou a conta %d\n", Achou);
      Limpa_Tela();
      continue;
    }
    if (flag != cp.numConta) {
      fprintf(delete,
              "N conta: %d,\n"
              "agencia : %d,\n"
              "Nome: %s,\n"
              "CPF: %d,\n"
              "Nascimento: %d/%d/%d,\n"
              "Estado: %s,\n"
              "Cep: %d,\n"
              "Numero da casa: %d,\n"
              "Bairro: %s,\n"
              "Cidade: %s,\n"
              "Telefone: %d,\n"
              "Senha: %d,\n\n",
              cp.numConta, cp.agencia, cp.nome, cp.cpf, cp.data.ano,
              cp.data.mes, cp.data.dia, cp.endereco.estado, cp.endereco.cep,
              cp.endereco.numCasa, cp.endereco.bairro, cp.endereco.cidade,
              cp.telefone, cp.senha);
    }
  }
  // apagar o extrato

  Fechando_Arquivo(delete);
  Fechando_Arquivo(fl);

  if (!Achou) {
    printf("teste, não achou\n");
    remove("temp.txt");
    Limpa_Tela();
  } else {
    remove("ClienteCP.txt");
    rename("temp.txt", "ClienteCP.txt");
    Limpa_Tela();
  }
}

void DeletarF(int flag) {
  Funcionario fn;
  Funcionario del = PesquisarFuncionario(flag, 3);

  if (del.codigo == 0 || del.cpf == 0) {
    printf("essa conta não existe, Funcionario\n");
    return;
  }

  FILE *fl = Abrindo_Arquivo(CP);

  FILE *delete = Abrindo_Arquivo(temp);
  int Achou = 0;
  while (14 == fscanf(fl,
                      "Codigo: %d,\n"
                      "Cargo: %d,\n"
                      "CPF: %d,\n"
                      "Nome: %100[^,],\n"
                      "Telefone: %d,\n"
                      "Senha: %d,\n"
                      "Estado:%2[^,],\n"
                      "Cep: %d,\n"
                      "Numero da casa: %d,\n"
                      "Bairro %100[^,],\n"
                      "Cidade: %100[^,],\n"
                      "Nascimento: %d/%d/%d\n",
                      &fn.codigo, &fn.cargo, &fn.cpf, fn.nome, &fn.telefone,
                      &fn.senha, fn.endereco.estado, &fn.endereco.cep,
                      &fn.endereco.numCasa, fn.endereco.bairro,
                      fn.endereco.cidade, &fn.data.ano, &fn.data.mes,
                      &fn.data.dia)) {
    if (flag != fn.codigo) {
      fprintf(fl,
              "Codigo: %d,\n"
              "Cargo: %d,\n"
              "CPF: %d,\n"
              "Nome: %s,\n"
              "Telefone: %d,\n"
              "Senha: %d,\n"
              "Estado:%s,\n"
              "Cep: %d,\n"
              "Numero da casa: %d,\n"
              "Bairro %s,\n"
              "Cidade: %s,\n"
              "Nascimento: %d/%d/%d\n\n",
              fn.codigo, fn.cargo, fn.cpf, fn.nome, fn.telefone, fn.senha,
              fn.endereco.estado, fn.endereco.cep, fn.endereco.numCasa,
              fn.endereco.bairro, fn.endereco.cidade, fn.data.ano, fn.data.mes,
              fn.data.dia);
    }
    if (flag == fn.codigo) {
      Achou = 1;
      printf("achou a conta %d\n", Achou);
      Limpa_Tela();
      continue;
    }
  }
  Fechando_Arquivo(delete);
  Fechando_Arquivo(fl);

  if (!Achou) {
    printf("teste, não achou\n");
    remove("temp.txt");
    Limpa_Tela();
  } else {
    remove("Funcionarios.txt");
    rename("temp.txt", "Funcionarios.txt");
    Limpa_Tela();
  }
}

/// PARTE CLIENTE

FILE *Abrindo_Saldo(int op) {
  FILE *fl;
  switch (op) {
  case 1:
    fl = fopen("SaldosCP.txt", "a+");
    break;
  case 2:
    fl = fopen("SaldosCC.txt", "a+");
    break;
  }
  return fl;
}

/* void Insere_SaldoCC(Saldo saldo) { FILE *fl = Abrindo_Saldo(cc.numConta); }
 */

void Insere_SaldoCP(SaldoCP saldo) {
  FILE *fl = Abrindo_Saldo(1);
  fprintf(fl,
          "Numero da conta: %d,"
          "CPF: %d,"
          "Angigo Saldo: %lf,"
          "Novo Saldo: %lf,"
          "Data da modificacao: %d/%d/%d,\n",
          saldo.numConta, saldo.cpf, saldo.antigoSaldo, saldo.saldoAtual,
          saldo.data.dia, saldo.data.mes, saldo.data.ano);
  Fechando_Arquivo(fl);
}

void Insere_SaldoCC(SaldoCC saldo) {
  FILE *fl = Abrindo_Saldo(2);
  fprintf(fl,
          "Numero da conta: %d,\n"
          "CPF: %d,\n"
          "Limite: %lf,\n"
          "Angigo Saldo: %lf,\n"
          "Novo Saldo: %lf,\n"
          "Data da modificacao: %d/%d/%d,\n\n",
          saldo.numConta, saldo.cpf, saldo.limite, saldo.antigoSaldo,
          saldo.saldoAtual, saldo.data.dia, saldo.data.mes, saldo.data.ano);
  Fechando_Arquivo(fl);
}

// O QUE E MOSTRAR SALDO EM TELA?
SaldoCP MostrarSaldoCP(int flag, int op) {
  FILE *fl = Abrindo_Saldo(1);
  int achou = 0; // flag
  SaldoCP saldo;
  SaldoCP achouSaldo;
  Limpa_Tela();
  while (7 == fscanf(fl,
                     "Numero da conta: %d,"
                     "CPF: %d,"
                     "Angigo Saldo: %lf,"
                     "Saldo Atual: %lf,"
                     "Data da modificacao: %d/%d/%d,\n",
                     &saldo.numConta, &saldo.cpf, &saldo.antigoSaldo,
                     &saldo.saldoAtual, &saldo.data.dia, &saldo.data.mes,
                     &saldo.data.ano)) {
    if (saldo.numConta == flag) {
      achouSaldo.numConta = saldo.numConta; // vendo se funciona assim!
      achouSaldo.cpf = saldo.cpf;
      achouSaldo.saldoAtual = saldo.saldoAtual;
      achouSaldo.antigoSaldo = saldo.antigoSaldo;
      achouSaldo.data.dia = saldo.data.dia;
      achouSaldo.data.mes = saldo.data.mes;
      achouSaldo.data.ano = saldo.data.ano;
      achou = 1;
    }
  }
  Fechando_Arquivo(fl);
  if (achou == 1) {
    return achouSaldo;
  }
  achouSaldo.numConta = 0;
  achouSaldo.cpf = 0;
  return achouSaldo;
}
SaldoCC MostrarSaldoCC(int flag, int op) {
  FILE *fl = Abrindo_Saldo(2);
  int achou = 0;
  SaldoCC saldo1;
  SaldoCC achouSaldo;
  while (8 == fscanf(fl,
                     "Numero da conta: %d,\n"
                     "CPF: %d,\n"
                     "Limite: %lf,\n"
                     "Angigo Saldo: %lf,\n"
                     "Novo Saldo: %lf,\n"
                     "Data da modificacao: %d/%d/%d,\n\n",
                     &saldo1.numConta, &saldo1.cpf, &saldo1.limite,
                     &saldo1.antigoSaldo, &saldo1.saldoAtual, &saldo1.data.dia,
                     &saldo1.data.mes, &saldo1.data.ano)) {
    if (saldo1.numConta == flag || saldo1.cpf == flag) {
      achouSaldo.numConta = saldo1.numConta; // vendo se funciona assim!
      achouSaldo.cpf = saldo1.cpf;
      achouSaldo.saldoAtual = saldo1.saldoAtual;
      achouSaldo.antigoSaldo = saldo1.antigoSaldo;
      achouSaldo.limite = saldo1.limite;
      achouSaldo.data.dia = saldo1.data.dia;
      achouSaldo.data.mes = saldo1.data.mes;
      achouSaldo.data.ano = saldo1.data.ano;
      achou = 1;
    }
  }
  Fechando_Arquivo(fl);
  if (achou == 1) {
    return achouSaldo;
  }
  achouSaldo.cpf = 0;
  achouSaldo.numConta = 0;
  return achouSaldo;
}
void ExtratoSaldoCP(int flag, int op) {
  FILE *fl = Abrindo_Saldo(1);
  FILE *nada = fopen("extrato.csv", "w+");
  SaldoCP saldo;

  // precia saber o numero magico
  // o cinco ta aqui mas não sei se e isso
  while (7 == fscanf(fl,
                     "Numero da conta: %d,"
                     "CPF: %d,"
                     "Angigo Saldo: %lf,"
                     "Saldo Atual: %lf,"
                     "Data da modificacao: %d/%d/%d,\n",
                     &saldo.numConta, &saldo.cpf, &saldo.antigoSaldo,
                     &saldo.saldoAtual, &saldo.data.dia, &saldo.data.mes,
                     &saldo.data.ano)) {
    if (flag == saldo.numConta) {
      fprintf(nada,
              "Numero da conta: %d,"
              "CPF: %d,"
              "Angigo Saldo: %lf,"
              "Saldo Atual: %lf,"
              "Data da modificacao: %d/%d/%d,\n",
              saldo.numConta, saldo.cpf, saldo.antigoSaldo, saldo.saldoAtual,
              saldo.data.dia, saldo.data.mes, saldo.data.ano);
    }
    Fechando_Arquivo(nada);
    Fechando_Arquivo(fl);

    Planilha();
  }
}

void ExtratoSaldoCC(int flag, int op) {
  FILE *fl = Abrindo_Saldo(2);
  FILE *nada = fopen("extrato.csv", "w+");
  SaldoCC saldo;

  // precia saber o numero magico
  // o cinco ta aqui mas não sei se e isso
  while (8 == fscanf(fl,
                     "Numero da conta: %d,\n"
                     "CPF: %d,\n"
                     "Limite: %lf,\n"
                     "Angigo Saldo: %lf,\n"
                     "Novo Saldo: %lf,\n"
                     "Data da modificacao: %d/%d/%d,\n\n",
                     &saldo.numConta, &saldo.cpf, &saldo.limite,
                     &saldo.antigoSaldo, &saldo.saldoAtual, &saldo.data.dia,
                     &saldo.data.mes, &saldo.data.ano)) {
    if (flag == saldo.numConta || flag == saldo.cpf) {
      fprintf(nada,
              "Numero da conta: %d,\n"
              "CPF: %d,\n"
              "Limite: %lf,\n"
              "Angigo Saldo: %lf,\n"
              "Novo Saldo: %lf,\n"
              "Data da modificacao: %d/%d/%d,\n\n",
              saldo.numConta, saldo.cpf, saldo.limite, saldo.antigoSaldo,
              saldo.saldoAtual, saldo.data.dia, saldo.data.mes, saldo.data.ano);
    }

    Fechando_Arquivo(nada);
    Fechando_Arquivo(fl);
    Planilha();
  }
}

double ContaLimite(Conta_Corrente cc) {
  FILE *fl = Abrindo_Arquivo(CC);
  SaldoCC saldo;
  double gastos = 0;

  while (8 == fscanf(fl,
                     "Numero da conta: %d,\n"
                     "CPF: %d,\n"
                     "Limite: %lf,\n"
                     "Angigo Saldo: %lf,\n"
                     "Novo Saldo: %lf,\n"
                     "Data da modificacao: %d/%d/%d,\n\n",
                     &saldo.numConta, &saldo.cpf, &saldo.limite,
                     &saldo.antigoSaldo, &saldo.saldoAtual, &saldo.data.dia,
                     &saldo.data.mes, &saldo.data.ano)) {
    if (cc.numConta == saldo.numConta) {
      gastos += saldo.saldoAtual;
    }
  }
  fclose(fl);
  return gastos;
}
