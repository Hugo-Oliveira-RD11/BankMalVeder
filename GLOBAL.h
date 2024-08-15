//
// Created by hugo on 12/06/24.
//

#ifndef MALVADERBANK_GLOBAL_H
#define MALVADERBANK_GLOBAL_H
#define LIM 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__MINGW32__) || defined(_MSC_VER)
#include "windows.h"
#else
#include <stdio_ext.h>
#endif
#include "./Model/Models.h"
#include "./DataBase/Data.h"
#include "./Cliente/MenuC.h"
#include "./Funcionario/AlterarConta.h"
#include "./Funcionario/AlterarCliente.h"
#include "./Funcionario/AlterarFun.h"
#include "./Funcionario/InsersaoC.h"
#include "./Funcionario/InsersaoF.h"
#include "./Funcionario/MenuF.h"
#include "./Funcionario/Verificador.h"
#include "./Imagens_ACII/Imagens.h"
#include "./Menu.h"
#include "./Tools/GeraDOR.h"
#endif // MALVADERBANK_GLOBAL_H
