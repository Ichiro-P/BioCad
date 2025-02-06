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
    UsuarioDAO* usuarioDAO;
public:
    UsuarioManager(UsuarioDAO* dao) : usuarioDAO(dao) { }

    void cadastrarUsuario(const std::shared_ptr<Usuario> usuario) {
        if (usuario->getNome().empty())
            throw std::invalid_argument("Nome do cliente não pode ser vazio");
        if (!usuarioDAO->adicionar(usuario))
            throw std::runtime_error("Falha ao cadastrar cliente");
    }
    
    std::shared_ptr<Usuario> obterUsuario(const std::shared_ptr<Usuario> usuario) {
        return usuarioDAO->buscarPorLogin(usuario->getLogin());
    }

    std::shared_ptr<Usuario> obterUsuarioId(int id) {
        return usuarioDAO->buscarPorId(id);
    }
    
    void atualizarUsuario(const std::shared_ptr<Usuario> usuario) {
        usuarioDAO->atualizar(usuario);
    }
    
    void removerUsuario(int id) {
        usuarioDAO->remover(id);
    }
    
    std::vector<std::shared_ptr<Usuario>> listarUsuarios() {
        return usuarioDAO->listar();
    }
};