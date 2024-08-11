#include <iostream>
#include <string>
#include <stdlib.h>

std::string menu() {
    printf(" +--------------------------------+\n");
    printf(" |     === TRAVEL PLANNER ===     |\n");
    printf(" +--------------------------------+\n");
    printf(" | [1] Cadastrar Viagem           |\n");
    printf(" | [2] Visualizar Viagens         |\n");
    printf(" | [3] Adicionar Participante     |\n");
    printf(" | [4] Visualizar Participantes   |\n");
    printf(" | [5] Notificar Participantes    |\n");
    printf(" +--------------------------------+\n");

    printf("  Opcao: ");
    std::string opcao;
    std::getline (std::cin, opcao);

    return opcao;
}
