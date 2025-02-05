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

bool gerente::validarGerente(const std::string &hash) {
    return hash == (senha + id);
}