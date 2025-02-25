#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <contrato.hpp>
#include <planoFinanceiro.hpp>

ContratoDVO::ContratoDVO(const std::string &cpfCliente, const std::string &nomeCliente, const CondicaoContrato &condicao, const PlanoFinanceiroDVO &planoDVO, int dia, int mes, int ano) 
 : cpfCliente(cpfCliente), nomeCliente(nomeCliente), condicao(condicao), plano(std::make_shared<PlanoFinanceiroDVO>(planoDVO)) {
    this->cpfCliente.resize(14);
    this->nomeCliente.resize(150);
    std::tm tmp = {};
    tmp.tm_year = ano - 1900;
    tmp.tm_mon = mes - 1;
    tmp.tm_mday = dia;
    dataFim = std::chrono::system_clock::from_time_t(std::mktime(&tmp));
}

void ContratoDVO::setCpfCliente(const std::string &novoCpf) {
    if(!novoCpf.empty()) cpfCliente = novoCpf;
}

void ContratoDVO::setNomeCliente(const std::string &novoNome) {
    if(!novoNome.empty()) nomeCliente = novoNome;
}

void ContratoDVO::setCondicao(const CondicaoContrato &novaCondicao) {
    condicao = novaCondicao;
}

void ContratoDVO::setDataFim(int dia, int mes, int ano) {
    std::tm tmp = {};
    tmp.tm_year = ano - 1900;
    tmp.tm_mon = mes - 1;
    tmp.tm_mday = dia;
    dataFim = std::chrono::system_clock::from_time_t(std::mktime(&tmp));
}

ContratoDAO::ContratoDAO(std::vector<ContratoDVO> &contratos) {
    for(auto &it: contratos) {
        this->contratos.push_back(std::make_unique<ContratoDVO>(std::move(it)));
    }
}

void ContratoDAO::create(ContratoDVO &contrato) {
    if(!contrato.getCpfCliente().empty()) {
        contratos.push_back(std::make_unique<ContratoDVO>(std::move(contrato)));
    }
}

void ContratoDAO::update(ContratoDVO &contrato) {
    if(!contrato.getCpfCliente().empty()) {
        for(auto &&it: contratos) {
            if(it->getCpfCliente() == contrato.getCpfCliente()  &&it->getCondicao() == CondicaoContrato::ATIVO) {
                it = std::make_unique<ContratoDVO>(std::move(contrato));
                break;
            }
        }
    }
}

ContratoDVO ContratoDAO::getContratoDVO(const std::string &cpfCliente) const& {
    for(auto &&it: contratos) {
        if(it->getCpfCliente() == cpfCliente) return *it;
    }
    return ContratoDVO();
}

bool ContratoManager::validarCpf(const std::string &cpf) {
    bool existe = false;
    if(!contratoDAO->getContratoDVO(cpf).getCpfCliente().empty()) existe = true;
    return existe;
}

bool ContratoManager::validarContrato(const ContratoDVO &contrato) {
    bool existe = false;
    if(!contratoDAO->getContratoDVO(contrato.getCpfCliente()).getCpfCliente().empty()) existe = true;
    return existe;
}

void ContratoManager::salvarContrato(ContratoDVO &contrato) {
    if(!contrato.getCpfCliente().empty()) {
        contratoDAO->create(contrato);
    }
}

void ContratoManager::atualizarContrato(ContratoDVO &contrato) {
    if(!contrato.getCpfCliente().empty()) {
        contratoDAO->update(contrato);
    }
}

bool ContratoManager::setContratoCancelado(ContratoDVO &contrato) {
    ContratoDVO temp = contratoDAO->getContratoDVO(contrato.getCpfCliente());
    if(!temp.getCpfCliente().empty()) {
        temp.setCondicao(CondicaoContrato::CANCELADO);
        contratoDAO->update(temp);
        return true;
    }
    return false;
}

ContratoDVO ContratoManager::renovarContrato(ContratoDVO &contrato, const std::tm novaDataFim) const& {
    ContratoDVO temp = contratoDAO->getContratoDVO(contrato.getCpfCliente());
    if(!temp.getCpfCliente().empty()) {
        temp.setDataFim(novaDataFim.tm_mday, novaDataFim.tm_mon, novaDataFim.tm_year + 1900);
        contratoDAO->update(temp);
    }
    return temp;
}

ContratoDVO ContratoManager::getContratoDVO(const std::string &cpfCliente) const& {
    return contratoDAO->getContratoDVO(cpfCliente);
}
