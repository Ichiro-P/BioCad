#include <ctime>
#include <dadosTeste.hpp>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <limits>
#include <vector>
#include <sistemaManager.hpp>


namespace TestData {

    // ----- CheckInDVO -----
    CheckInDVO checkIn1("111.111.111-11");
    CheckInDVO checkIn2("222.222.222-22");
    CheckInDVO checkIn3("333.333.333-33");
    CheckInDVO checkIn4("444.444.444-44");
    CheckInDVO checkIn5("555.555.555-55");
    CheckInDVO checkIn6("666.666.666-66");

    // ----- CheckOutDVO -----
    CheckOutDVO checkOut1("111.111.111-11");
    CheckOutDVO checkOut2("222.222.222-22");
    CheckOutDVO checkOut3("333.333.333-33");
    CheckOutDVO checkOut4("444.444.444-44");
    CheckOutDVO checkOut5("555.555.555-55");
    CheckOutDVO checkOut6("666.666.666-66");

    // ----- ClienteDVO -----
    ClienteDVO cliente1("111.111.111-11", "Alice Silva", "(11) 91234-1111", "Rua das Acácias, 100", 5, 3, 1980);
    ClienteDVO cliente2("222.222.222-22", "Bruno Costa", "(21) 92345-2222", "Avenida Central, 200", 12, 7, 1985);
    ClienteDVO cliente3("333.333.333-33", "Carla Souza", "(31) 93456-3333", "Rua dos Lírios, 300", 23, 9, 1990);
    ClienteDVO cliente4("444.444.444-44", "Daniel Pereira", "(41) 94567-4444", "Av. dos Pinheiros, 400", 15, 5, 1992);
    ClienteDVO cliente5("555.555.555-55", "Elisa Ramos", "(51) 95678-5555", "Rua das Orquídeas, 500", 8, 11, 1988);
    ClienteDVO cliente6("666.666.666-66", "Fábio Lima", "(61) 96789-6666", "Avenida das Palmeiras, 600", 30, 1, 1995);

    // ----- PlanoFinanceiroDVO -----
    PlanoFinanceiroDVO plano1("Básico", TipoPlanoFinanceiro::MENSAL);
    PlanoFinanceiroDVO plano2("Premium", TipoPlanoFinanceiro::ANUAL);
    PlanoFinanceiroDVO plano3("Executivo", TipoPlanoFinanceiro::MENSAL);
    PlanoFinanceiroDVO plano4("Avançado", TipoPlanoFinanceiro::ANUAL);
    PlanoFinanceiroDVO plano5("Standard", TipoPlanoFinanceiro::MENSAL);
    PlanoFinanceiroDVO plano6("Especial", TipoPlanoFinanceiro::ANUAL);

    // ----- ContratoDVO -----
    ContratoDVO contrato1("111.111.111-11", "Alice Silva", CondicaoContrato::ATIVO, plano1, 1, 1, 2023);
    ContratoDVO contrato2("222.222.222-22", "Bruno Costa", CondicaoContrato::ATIVO, plano2, 2, 2, 2023);
    ContratoDVO contrato3("333.333.333-33", "Carla Souza", CondicaoContrato::ATIVO, plano3, 3, 3, 2023);
    ContratoDVO contrato4("444.444.444-44", "Daniel Pereira", CondicaoContrato::ATIVO, plano4, 4, 4, 2023);
    ContratoDVO contrato5("555.555.555-55", "Elisa Ramos", CondicaoContrato::ATIVO, plano5, 5, 5, 2023);
    ContratoDVO contrato6("666.666.666-66", "Fábio Lima", CondicaoContrato::ATIVO, plano6, 6, 6, 2023);

    // ----- MensalidadeDVO -----
    MensalidadeDVO mensalidade1("111.111.111-11", 101);
    MensalidadeDVO mensalidade2("222.222.222-22", 102);
    MensalidadeDVO mensalidade3("333.333.333-33", 103);
    MensalidadeDVO mensalidade4("444.444.444-44", 104);
    MensalidadeDVO mensalidade5("555.555.555-55", 105);
    MensalidadeDVO mensalidade6("666.666.666-66", 106);

    // ----- PlanoDeTreinoDVO -----
    PlanoDeTreinoDVO treino1("111.111.111-11", "Alice Silva", {"Hipertrofia", "Resistência"}, {"Nenhuma"}, "Funcional");
    PlanoDeTreinoDVO treino2("222.222.222-22", "Bruno Costa", {"Emagrecimento"}, {"Diabetes"}, "Aeróbico");
    PlanoDeTreinoDVO treino3("333.333.333-33", "Carla Souza", {"Flexibilidade", "Equilíbrio"}, {"Nenhuma"}, "Alongamento");
    PlanoDeTreinoDVO treino4("444.444.444-44", "Daniel Pereira", {"Força", "Resistência"}, {"Lesão no joelho"}, "Treino de Força");
    PlanoDeTreinoDVO treino5("555.555.555-55", "Elisa Ramos", {"Cardio"}, {"Hipertensão"}, "Circuito");
    PlanoDeTreinoDVO treino6("666.666.666-66", "Fábio Lima", {"Definição muscular"}, {"Nenhuma"}, "Crossfit");

    // ----- RelatorioDVO -----

    std::tm inicio1 = []{
        std::tm t = {}; 
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;      // Janeiro (0-indexado)
        t.tm_mday = 1;
        return t;
    }();
    std::tm fim1 = []{
        std::tm t = {}; 
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 1;
        t.tm_hour = 23;
        t.tm_min  = 59;
        t.tm_sec  = 59;
        return t;
    }();
    RelatorioDVO relatorio1(inicio1, fim1, { checkIn1 }, { checkOut1 });

    std::tm inicio2 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 2;
        return t;
    }();
    std::tm fim2 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 2;
        t.tm_hour = 23;
        t.tm_min  = 59;
        t.tm_sec  = 59;
        return t;
    }();
    RelatorioDVO relatorio2(inicio2, fim2, { checkIn2 }, { checkOut2 });

    std::tm inicio3 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 3;
        return t;
    }();
    std::tm fim3 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 3;
        t.tm_hour = 23;
        t.tm_min  = 59;
        t.tm_sec  = 59;
        return t;
    }();
    RelatorioDVO relatorio3(inicio3, fim3, { checkIn3 }, { checkOut3 });

    std::tm inicio4 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 4;
        return t;
    }();
    std::tm fim4 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 4;
        t.tm_hour = 23;
        t.tm_min  = 59;
        t.tm_sec  = 59;
        return t;
    }();
    RelatorioDVO relatorio4(inicio4, fim4, { checkIn4 }, { checkOut4 });

    std::tm inicio5 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 5;
        return t;
    }();
    std::tm fim5 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 5;
        t.tm_hour = 23;
        t.tm_min  = 59;
        t.tm_sec  = 59;
        return t;
    }();
    RelatorioDVO relatorio5(inicio5, fim5, { checkIn5 }, { checkOut5 });

    std::tm inicio6 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 6;
        return t;
    }();
    std::tm fim6 = []{
        std::tm t = {};
        t.tm_year = 2025 - 1900;
        t.tm_mon  = 0;
        t.tm_mday = 6;
        t.tm_hour = 23;
        t.tm_min  = 59;
        t.tm_sec  = 59;
        return t;
    }();
    RelatorioDVO relatorio6(inicio6, fim6, { checkIn6 }, { checkOut6 });
}