#include <iostream>
#include <clienteDVO.hpp>

Contrato::Contrato(const Plano &planoVigente) : planoVigente(planoVigente) {
    // Valores baseados no tipo de plano
    float valorBase = 150.0f;
    int duracao = 1;
    
    switch(planoVigente.getTipo()) {
        case TipoPlano::SEMESTRAL:
            valorBase = 130.0f;
            duracao = 6;
            break;
        case TipoPlano::ANUAL:
            valorBase = 110.0f;
            duracao = 12;
            break;
        case TipoPlano::TRIMESTRAL:
            valorBase = 140.0f;
            duracao = 3;
            break;
        case TipoPlano::MENSAL:
        default:
            duracao = 1;
    }

    for(int i = 0; i < duracao; ++i) {
        mensalidades.push_back(Mensalidade(i+1, valorBase));
    }
}

std::string planoString(const TipoPlano &plano) {
    if(plano == TipoPlano::ANUAL) {
        return "anual";
    } else if(plano == TipoPlano::SEMESTRAL) {
        return "semestral";
    } else if(plano == TipoPlano::TRIMESTRAL) {
        return "trimestral";
    } else return "mensal";
}