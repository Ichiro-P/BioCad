#include <loginManager.hpp>
#include <usuarioDAO.hpp>
#include <usuarioDVO.hpp>
#include <memory>
#include <string>
#include <stdexcept>



std::shared_ptr<Usuario> LoginManager::autenticar(const std::string &login, const std::string &senha) {
    std::shared_ptr<Usuario> usuario = usuarioDAO->buscarPorLogin(login);
    if (usuario && usuario->getSenha() == senha)
        return usuario;
    return nullptr;
}