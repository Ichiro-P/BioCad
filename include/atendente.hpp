#include <string>

class atendente {
    std::string id;
    std::string senha;

    public:
    atendente(const std::string& id, const std::string& senha);
    virtual std::string getId() const&;
    virtual std::string getSenha() const&;
    bool validarAtendente(const std::string& caminhoHashes);
};