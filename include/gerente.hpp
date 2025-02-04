#include <string>

class gerente {
    std::string id;
    std::string senha;

    public:
    gerente(const std::string& id, const std::string& senha);
    virtual std::string getId() const&;
    virtual std::string getSenha() const&;
    bool validarGerente(const std::string& caminhoHashes);
};