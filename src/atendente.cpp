#include <iostream>
#include <fstream>
#include <sstream>
#include <atendente.hpp>

atendente::atendente(const std::string &id, const std::string &senha) : id(id), senha(senha) {}

std::string atendente::getId() const& {
    return id;
}

std::string atendente::getSenha() const& {
    return senha;
}

bool atendente::validarAtendente(const std::string &caminhoHashes) {
    std::string tempHash = senha + id;
    std::ifstream arquivoHashes(caminhoHashes);
    std::string linha;
    while(std::getline(arquivoHashes, linha)) {
        if(linha == tempHash) {
            return true;
        }
    }
    return false;
}