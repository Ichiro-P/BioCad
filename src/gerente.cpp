#include <iostream>
#include <fstream>
#include <sstream>
#include <gerente.hpp>

gerente::gerente(const std::string &id, const std::string &senha) : id(id), senha(senha) {}

std::string gerente::getId() const& {
    return id;
}

std::string gerente::getSenha() const& {
    return senha;
}

bool gerente::getAcesso() const& {
    return acessoPermitido;
}

bool gerente::validarGerente(const std::string &hash) {
    if(hash == (senha + id)) {
        acessoPermitido = true;
        return true;
    }
    return false;
}