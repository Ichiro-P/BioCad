#include <usuarioDAO.hpp>
#include <atendenteDVO.hpp>
#include <personalTrainerDVO.hpp>
#include <gerenteDVO.hpp>

UsuarioDAO::UsuarioDAO() {
    usuarios.push_back(std::make_shared<Atendente>(1, "eduardo", "maromba", "Eduardo"));
    usuarios.push_back(std::make_shared<PersonalTrainer>(2, "suteam", "mateus", "Matheus Vinicius"));
    usuarios.push_back(std::make_shared<Gerente>(3, "root", "root", "Administrador"));
}

std::shared_ptr<Usuario> UsuarioDAO::buscarPorLogin(const std::string &login) {
    for (auto &u : usuarios) {
        if (u->getLogin() == login)
            return u;
    }
    return nullptr;
}