cmake_minimum_required(VERSION 3.27)

project(MalvaderBank)

add_executable(
  banquinho
  GLOBAL.h
  Menu.c
  Menu.h
  Cliente/MenuC.h
  Cliente/MenuC.c
  DataBase/Data.h
  DataBase/Data.c
  Funcionario/MenuF.h
  Funcionario/MenuF.c
  Model/Models.h
  Program.c
  Funcionario/Verificador.c
  Funcionario/Verificador.h
  Funcionario/AlterarConta.c
  Funcionario/AlterarConta.h
  Funcionario/InsersaoF.h
  Funcionario/InsersaoF.c
  Funcionario/InsersaoC.c
  Funcionario/InsersaoC.h
  Tools/GeraDOR.c
  Tools/GeraDOR.h
  Imagens_ACII/Imagens.h
  Imagens_ACII/Imagens.c
        Funcionario/AlterarFun.c
        Funcionario/AlterarFun.h
        Funcionario/AlterarCliente.c
        Funcionario/AlterarCliente.h)
