#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <atendente.hpp>
#include <hashes.hpp>

atendente::atendente(const std::string &id, const std::string &senha) : id(id), senha(senha) {}

std::string atendente::getId() const& {
    return id;
}

std::string atendente::getSenha() const& {
    return senha;
}

bool atendente::getAcesso() const& {
    return acessoPermitido;
}

bool atendente::validarAtendente() {
    std::string tempHash = senha + id;
    for(const auto& hash: hashesAtendente) {
        if(hash == tempHash) {
            acessoPermitido = true;
            return true;
        }
    }
    return false;
}