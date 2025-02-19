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

void iniciarSistema();

void login(std::shared_ptr<LoginManager> loginManager, std::shared_ptr<ClienteManager> clienteManager, std::shared_ptr<UsuarioManager> usuarioManager);

void menuInicial(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void listarClientesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void cadastrarCliente(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void listarAtendentesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void cadastrarAtendente(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void listarPersonalTrainersCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void cadatrarPersonalTrainer(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void listarClientesCadastradosPersonalTrainer(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);

void cadastroCliente(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager, int id);

void cadastroClientePersonalTrainer(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager, int idCliente);

void relatorioFrequencia(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager);