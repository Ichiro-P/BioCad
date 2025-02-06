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

// Metodos para chamar tela e torna-la mais responsiva


void telaClientesCadastrados(std::shared_ptr<Usuario> usuario);
void telaCadastrarCliente(std::shared_ptr<Usuario> usuario);
void telaAtendentesCadastrados(std::shared_ptr<Usuario> usuario);
void telaCadastrarAtendente(std::shared_ptr<Usuario> usuario);
void telaPersonalTrainersCadastrados(std::shared_ptr<Usuario> usuario);
void telaCadastrarPersonalTrainer(std::shared_ptr<Usuario> usuario);

static int contadorId = 0;
static int contadorIdUsuarios = 0;

auto clienteDAO = std::make_unique<ClienteDAO>();
ClienteManager clienteManager(clienteDAO.get());

auto usuarioDAO = std::make_unique<UsuarioDAO>();
UsuarioManager usuarioManager(usuarioDAO.get());

void telaInicial(std::shared_ptr<Usuario> usuario) {
    int entrada;

    std::cout << "Bem-vindo " << usuario->getNome() << '\n';
    std::vector<std::string> usuarioOpcoes = usuario->getInterfaceOptions();
    for(const auto& opcao: usuarioOpcoes) {
        std::cout << opcao;
    }

    std::cin >> entrada;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(usuario->getTipo() == TipoUsuario::ATENDENTE) {
        switch(entrada) {
            case 1: telaClientesCadastrados(usuario); break;
            case 2: telaCadastrarCliente(usuario); break;
            case 0: break;
            default:
            std::cout << "Opcao Invalida.\n"; telaInicial(usuario);
        }
    } else if(usuario->getTipo() == TipoUsuario::GERENTE) {
        switch(entrada) {
            case 1: telaClientesCadastrados(usuario); break;
            case 2: telaCadastrarCliente(usuario); break;
            case 3: telaAtendentesCadastrados(usuario); break;
            case 4: telaCadastrarAtendente(usuario); break;
            case 5: telaPersonalTrainersCadastrados(usuario); break;
            case 6: telaCadastrarPersonalTrainer(usuario); break;
            case 0: break;
            default:
            std::cout << "Opcao Invalida.\n"; telaInicial(usuario);
        }   
    }
}

void telaClientesCadastrados(std::shared_ptr<Usuario> usuario) {
    int entrada2;
    std::cout << "Clientes cadastrados:" << std::endl;
    for (const auto &c : clienteManager.listarClientes()) std::cout << "Id: " << c.getId() << " - " << c.getNome() << '\n';
    std::cout << "Selecione um cliente pelo Id: ";
    std::cin >> entrada2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Cliente clienteDAO = clienteManager.obterCliente(entrada2);
    std::cout << "Id: " << clienteDAO.getId() << "\nNome : " << clienteDAO.getNome() << "\nCpf: " << clienteDAO.getCpf() << "\nEndereco: " << clienteDAO.getEndereco() << "\nTelefone: " << clienteDAO.getTelefone() << '\n';
    std::cout << "Selecione uma opcao:\n1 - Atualizar dados;\n2-Remover cliente;\n0 - Voltar.\n";
    std::cin >> entrada2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch(entrada2) {
        case 1:{
            std::string dadoEntrada;
            std::cout << "Selecione uma das opcoes:\n1 - Nome;\n2 - Cpf;\n3 - Endereco\n4 - Telefone.\n";
            std::cin >> entrada2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(entrada2) {
                case 1:
                std::cout << "Informe o novo nome: ";
                std::getline(std::cin, dadoEntrada);
                clienteDAO.setNome(dadoEntrada);
                break;
                case 2:
                std::cout << "Informe o novo cpf: ";
                std::getline(std::cin, dadoEntrada);
                clienteDAO.setCpf(dadoEntrada);
                break;
                case 3:
                std::cout << "Informe o novo endereco: ";
                std::getline(std::cin, dadoEntrada);
                clienteDAO.setEndereco(dadoEntrada);
                break;
                case 4:
                std::cout << "Informe o novo telefone: ";
                std::getline(std::cin, dadoEntrada);
                clienteDAO.setTelefone(dadoEntrada);
                break;
            }
            std::cout << "Dados atualizados com sucesso.\nRetornando a tela inicial.\n";
            telaInicial(usuario);
        }
        break;
        case 2:
            clienteManager.removerCliente(entrada2);
            std::cout << "Cliente removido com sucesso.\nRetornando a tela inicial.\n";
            telaInicial(usuario);
        break;
        case 0:
            telaInicial(usuario);
        break;
        default:
            std::cout << "Opcao invalida.\n"; telaClientesCadastrados(usuario);
    }
}

void telaCadastrarCliente(std::shared_ptr<Usuario> usuario) {
    std::string nomeCliente, cpfCliente, telefoneCliente, enderecoCliente;
    std::cout << "Informe o Nome do cliente: ";
    std::getline(std::cin, nomeCliente);
            
    std::cout << "Informe o cpf do cliente: ";
    std::getline(std::cin, cpfCliente);

    std::cout << "Informe o telefone do cliente: ";
    std::getline(std::cin, telefoneCliente);

    std::cout << "Informe o endereco do cliente: ";
    std::getline(std::cin, enderecoCliente);

    Cliente novoCliente = Cliente(contadorId++, nomeCliente, cpfCliente, enderecoCliente, telefoneCliente);
    clienteManager.cadastrarCliente(novoCliente);
    std::cout << "Cliente cadastrado: " << novoCliente.getNome() << '\n';

    telaInicial(usuario);
}

void telaAtendentesCadastrados(std::shared_ptr<Usuario> usuario) {
    int entrada2;
    std::cout << "Atendentes cadastrados:" << std::endl;
    for (const auto &u : usuarioManager.listarUsuarios()) {
        if(u->getTipo() == TipoUsuario::ATENDENTE) std::cout << "Id: " << u->getId() << " - " << u->getNome() << '\n';
    }
    std::cout << "Selecione um atendente pelo Id: ";
    std::cin >> entrada2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::shared_ptr<Usuario> usuarioDAO = usuarioManager.obterUsuarioId(entrada2);
    std::cout << "Id: " << usuarioDAO->getId() << "\nNome : " << usuarioDAO->getNome() << '\n';
    std::cout << "Selecione uma opcao:\n1 - Atualizar dados;\n2-Remover atendente;\n0 - Voltar.\n";
    std::cin >> entrada2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch(entrada2) {
        case 1:{
            std::string dadoEntrada;
            std::cout << "Selecione uma das opcoes:\n1 - Nome;\n2 - Login;\n3 - Senha.\n";
            std::cin >> entrada2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(entrada2) {
                case 1:
                std::cout << "Informe o novo nome: ";
                std::getline(std::cin, dadoEntrada);
                usuarioDAO->setNome(dadoEntrada);
                break;
                case 2:
                std::cout << "Informe o novo login: ";
                std::getline(std::cin, dadoEntrada);
                usuarioDAO->setSenha(dadoEntrada);
                break;
                case 3:
                std::cout << "Informe a nova senha: ";
                std::getline(std::cin, dadoEntrada);
                usuarioDAO->setSenha(dadoEntrada);
                break;
            }
            std::cout << "Dados atualizados com sucesso.\nRetornando a tela inicial.\n";
            telaInicial(usuario);
        }
        break;
        case 2:
            clienteManager.removerCliente(entrada2);
            std::cout << "Cliente removido com sucesso.\nRetornando a tela inicial.\n";
            telaInicial(usuario);
        break;
        case 0:
            telaInicial(usuario);
        break;
        default:
            std::cout << "Opcao invalida.\n"; telaClientesCadastrados(usuario);
    }
}

void telaCadastrarAtendente(std::shared_ptr<Usuario> usuario) {
    std::string nomeAtendente, loginAtendente, senhaAtendente;
    std::cout << "Informe o Nome do atendente: ";
    std::getline(std::cin, nomeAtendente);
            
    std::cout << "Informe o login do atendente: ";
    std::getline(std::cin, loginAtendente);

    std::cout << "Informe a senha do atendente: ";
    std::getline(std::cin, senhaAtendente);

    std::shared_ptr<Usuario> novoUsuario = std::make_shared<Atendente>(contadorIdUsuarios++, loginAtendente, senhaAtendente, nomeAtendente);
    usuarioManager.cadastrarUsuario(novoUsuario);
    std::cout << "Atendente cadastrado: " << novoUsuario->getNome() << '\n';

    telaInicial(usuario);
}

void telaPersonalTrainersCadastrados(std::shared_ptr<Usuario> usuario) {
    int entrada2;
    std::cout << "Personal Trainers cadastrados:" << std::endl;
    for (const auto &u : usuarioManager.listarUsuarios()) {
        if(u->getTipo() == TipoUsuario::PERSONAL_TRAINER) std::cout << "Id: " << u->getId() << " - " << u->getNome() << '\n';
    }
    std::cout << "Selecione um atendente pelo Id: ";
    std::cin >> entrada2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::shared_ptr<Usuario> usuarioDAO = usuarioManager.obterUsuarioId(entrada2);
    std::cout << "Id: " << usuarioDAO->getId() << "\nNome : " << usuarioDAO->getNome() << '\n';
    std::cout << "Selecione uma opcao:\n1 - Atualizar dados;\n2-Remover atendente;\n0 - Voltar.\n";
    std::cin >> entrada2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch(entrada2) {
        case 1:{
            std::string dadoEntrada;
            std::cout << "Selecione uma das opcoes:\n1 - Nome;\n2 - Login;\n3 - Senha.\n";
            std::cin >> entrada2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(entrada2) {
                case 1:
                std::cout << "Informe o novo nome: ";
                std::getline(std::cin, dadoEntrada);
                usuarioDAO->setNome(dadoEntrada);
                break;
                case 2:
                std::cout << "Informe o novo login: ";
                std::getline(std::cin, dadoEntrada);
                usuarioDAO->setSenha(dadoEntrada);
                break;
                case 3:
                std::cout << "Informe a nova senha: ";
                std::getline(std::cin, dadoEntrada);
                usuarioDAO->setSenha(dadoEntrada);
                break;
            }
            std::cout << "Dados atualizados com sucesso.\nRetornando a tela inicial.\n";
            telaInicial(usuario);
        }
        break;
        case 2:
            clienteManager.removerCliente(entrada2);
            std::cout << "Cliente removido com sucesso.\nRetornando a tela inicial.\n";
            telaInicial(usuario);
        break;
        case 0:
            telaInicial(usuario);
        break;
        default:
            std::cout << "Opcao invalida.\n"; telaClientesCadastrados(usuario);
    }
}

void telaCadastrarPersonalTrainer(std::shared_ptr<Usuario> usuario) {
    std::string nomePersonalTrainer, loginPersonalTrainer, senhaPersonalTrainer;
    std::cout << "Informe o Nome do personal trainer: ";
    std::getline(std::cin, nomePersonalTrainer);
            
    std::cout << "Informe o login do personal trainer: ";
    std::getline(std::cin, loginPersonalTrainer);

    std::cout << "Informe a senha do personal trainer: ";
    std::getline(std::cin, senhaPersonalTrainer);

    std::shared_ptr<Usuario> novoUsuario = std::make_shared<PersonalTrainer>(contadorIdUsuarios++, loginPersonalTrainer, senhaPersonalTrainer, nomePersonalTrainer);
    usuarioManager.cadastrarUsuario(novoUsuario);
    std::cout << "Personal Trainer cadastrado: " << novoUsuario->getNome() << '\n';

    telaInicial(usuario);
}