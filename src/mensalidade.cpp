#include <mensalidade.hpp>

#include <string>
#include <vector>
#include <memory>
#include <enums.hpp>

MensalidadeDAO::MensalidadeDAO(std::vector<MensalidadeDVO> &mensalidades) {
    for(auto &&it : mensalidades) {
        this->mensalidades.push_back(std::make_unique<MensalidadeDVO>(std::move(it)));
    }
}

void MensalidadeDAO::create(MensalidadeDVO &mensalidade) {
    mensalidade.setId(mensalidades.size()+1);
    mensalidades.push_back(std::make_unique<MensalidadeDVO>(std::move(mensalidade)));
}

void MensalidadeDAO::update(MensalidadeDVO &mensalidade) {
    mensalidades[mensalidade.getId()-1] = std::make_unique<MensalidadeDVO>(std::move(mensalidade));
}

MensalidadeDVO MensalidadeDAO::getMensalidadeDVO(int idMensalidade) {
    return *mensalidades[idMensalidade];
}

std::vector<MensalidadeDVO> MensalidadeDAO::getMensalidades(const std::string &cpfCliente) const& {
    std::vector<MensalidadeDVO> res;
    res.reserve(mensalidades.size());
    for(const auto &it: mensalidades) {
        if(it->getCpfCliente() == cpfCliente) res.push_back(*it);
    }
    return res;
}

bool MensalidadeManager::validarId(int idMensalidade, const std::string &cpfCliente) {
    bool existe = false;
    for(const auto &it: mensalidadeDAO->getMensalidades(cpfCliente)) {
        if(it.getId() == idMensalidade) {
            existe = true;
            break;
        }
    }
    return existe;
}

bool MensalidadeManager::validadrCpf(const std::string &cpfCliente) {
    return mensalidadeDAO->getMensalidades(cpfCliente).size() > 0;
}

MensalidadeDVO MensalidadeManager::getMensalidadeDVO(int idMensalidade) const& {
    return mensalidadeDAO->getMensalidadeDVO(idMensalidade);
}

std::vector<MensalidadeDVO> MensalidadeManager::getMensalidades(const std::string &cpfCliente) const& {
    return mensalidadeDAO->getMensalidades(cpfCliente);
}

std::string MensalidadeManager::getRecibo(int idMensalidade) {
    std::string res = "Mensalidade id: " + std::to_string(idMensalidade) + " paga com sucesso no valor de R$" + std::to_string(mensalidadeDAO->getMensalidadeDVO(idMensalidade).getValor()) + " reais.";
    return res;
}

void MensalidadeManager::atualizarMensalidade(MensalidadeDVO &mensalidade) {
    mensalidadeDAO->update(mensalidade);
}

void MensalidadeManager::adicionarMensalidade(MensalidadeDVO &mensalidade) {
    mensalidadeDAO->create(mensalidade);
}
