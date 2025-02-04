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

bool gerente::validarGerente(const std::string &caminhoHashes) {
    std::string tempHash = senha + id;
    std::ifstream arquivoHashes(caminhoHashes);
    if(!arquivoHashes.is_open()) {
        std::cerr << "Erro ao abrir lista de Gerente.\n";
        return false;
    }
    std::string linha;
    while(std::getline(arquivoHashes, linha)) {
        if(linha == tempHash) {
            return true;
        }
    }
    return false;
}