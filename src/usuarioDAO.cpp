#include <usuarioDAO.hpp>
#include <atendenteDVO.hpp>
#include <personalTrainerDVO.hpp>
#include <gerenteDVO.hpp>

#include <algorithm>

UsuarioDAO::UsuarioDAO(std::vector<std::shared_ptr<Usuario>>& vetorUsuarios) {
    for(const auto& it: vetorUsuarios) {
        usuarios.push_back(it);
    }
}

std::shared_ptr<Usuario> UsuarioDAO::buscarPorLogin(const std::string &login) {
    for (auto &u : usuarios) {
        if (u->getLogin() == login)
            return u;
    }
    return nullptr;
}

std::shared_ptr<Usuario> UsuarioDAO::buscarPorId(int id) {
    for (auto &u : usuarios) {
        if (u->getId() == id)
            return u;
    }
    return nullptr;
}

bool UsuarioDAO::adicionar(const std::shared_ptr<Usuario> usuario) {
    usuarios.push_back(usuario);
    return true;
}

bool UsuarioDAO::atualizar(const std::shared_ptr<Usuario> usuario) {
    for (auto &u : usuarios) {
        if (u->getId() == usuario->getId()) {
            u = usuario;
            return true;
        }
    }
    return false;
}

bool UsuarioDAO::remover(int id) {
    auto it = std::remove_if(usuarios.begin(), usuarios.end(), [id](const std::shared_ptr<Usuario> u) { return u->getId() == id; });
    if (it != usuarios.end()) {
        usuarios.erase(it, usuarios.end());
        return true;
    }
    return false;
}

std::vector<std::shared_ptr<Usuario>> UsuarioDAO::listar() {
    return usuarios;
}