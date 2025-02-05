#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <atendente.hpp>

atendente::atendente(const std::string &id, const std::string &senha) : id(id), senha(senha) {}

std::string atendente::getId() const& {
    return id;
}

std::string atendente::getSenha() const& {
    return senha;
}

bool atendente::validarAtendente(const std::vector<std::string>& hashes) {
    std::string tempHash = senha + id;
    for(const auto& hash: hashes) {
        if(hash == tempHash) return true;
    }
    return false;
}