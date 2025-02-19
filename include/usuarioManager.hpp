#pragma once

#include <usuarioDAO.hpp>
#include <usuarioDVO.hpp>
#include <atendenteDVO.hpp>
#include <gerenteDVO.hpp>
#include <personalTrainerDVO.hpp>
#include <stdexcept>
#include <vector>


class UsuarioManager {
private:
    std::shared_ptr<UsuarioDAO> usuarioDAO;
public:
    UsuarioManager(std::shared_ptr<UsuarioDAO> dao) : usuarioDAO(dao) { }

    void cadastrarUsuario(const std::shared_ptr<Usuario> usuario) {
        if (usuario->getNome().empty())
            throw std::invalid_argument("Nome do cliente nao pode ser vazio");
        if (!usuarioDAO->adicionar(usuario))
            throw std::runtime_error("Falha ao cadastrar cliente");
    }
    
    std::shared_ptr<Usuario> getUsuario(const std::shared_ptr<Usuario> usuario) {
        return usuarioDAO->buscarPorLogin(usuario->getLogin());
    }

    std::shared_ptr<Usuario> getUsuarioId(int id) {
        return usuarioDAO->buscarPorId(id);
    }
    
    void atualizarUsuario(const std::shared_ptr<Usuario> usuario) {
        usuarioDAO->atualizar(usuario);
    }
    
    void removerUsuario(int id) {
        usuarioDAO->remover(id);
    }
    
    std::vector<std::shared_ptr<Usuario>> getUsuarios() {
        return usuarioDAO->login();
    }
};