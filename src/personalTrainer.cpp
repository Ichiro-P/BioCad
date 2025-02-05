#include <personalTrainer.hpp>
#include <hashes.hpp>

personalTrainer::personalTrainer(const std::string &id, const std::string &senha) : id(id), senha(senha) {}

std::string personalTrainer::getId() const& {
    return id;
}

std::string personalTrainer::getSenha() const& {
    return senha;
}

bool personalTrainer::getAcesso() const& {
    return acessoPermitido;
}

bool personalTrainer::validarPersonalTrainer() {
    std::string tempHash = senha + id;
    for(const auto& hash: hashesPersonalTrainer) {
        if(hash == tempHash) {
            acessoPermitido = true;
            return true;
        }
    }
    return false;
}
