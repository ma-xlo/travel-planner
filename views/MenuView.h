#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <iostream>
#include <string>
#include <stdlib.h>

class MenuView {

public:
    static std::string menu() {
        printf(" +--------------------------------+\n");
        printf(" |     === TRAVEL PLANNER ===     |\n");
        printf(" +--------------------------------+\n");
        printf(" | [1] Cadastrar Viagem           |\n");
        printf(" | [2] Visualizar Viagens         |\n");
        printf(" | [3] Adicionar Convidado        |\n");
        printf(" | [4] Visualizar Convidados      |\n");
        printf(" | [5] Notificar Convidados       |\n");
        printf(" +--------------------------------+\n");

        printf("  Opcao: ");
        std::string opcao;
        std::getline (std::cin, opcao);

        return opcao;
    }
};

#endif