#pragma once

#include <loginManager.hpp>
#include <clienteManager.hpp>
#include <usuarioManager.hpp>
#include <clienteDAO.hpp>
#include <usuarioDAO.hpp>
#include <clienteDVO.hpp>
#include <usuarioDVO.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>

extern int contadorId;
extern int contadorIdUsuarios;

void telaClientesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void telaCadastrarCliente(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void telaAtendentesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void telaCadastrarAtendente(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void telaPersonalTrainersCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void telaCadastrarPersonalTrainer(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void telaClientesCadastradosPersonalTrainer(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void telaInicial(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);