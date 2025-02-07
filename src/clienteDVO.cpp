#include <iostream>
#include <clienteDVO.hpp>

Contrato::Contrato(const Plano &planoVigente) : planoVigente(planoVigente){
    for(int i = 0; i < 5; ++i) {
        mensalidades.push_back(Mensalidade(i));
    }
}

void Contrato::mensalidadesNaoPagas() {
    for(int i = 0; i < mensalidades.size(); ++i) {
        if(mensalidades[i].getStatus() == Status::PENDENTE) {
            std::cout <<  "\nIndex : " << i << "; Data de vencimento relativa: " << mensalidades[i].getDataVencimentoRelativa() << "; Valor: " << mensalidades[i].getValor();
        }
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