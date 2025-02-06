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

static int contadorId = 5;
static int contadorIdUsuarios = 3;

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

void telaInicial(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    int entrada = -1;
    while (entrada != 0) {
        std::cout << "\nBem-vindo " << usuario->getNome() << "\n";
        auto usuarioOpcoes = usuario->getInterfaceOptions();
        for (const auto& opcao : usuarioOpcoes)
            std::cout << opcao;
        std::cout << "Digite a opcao desejada: ";

        if (!(std::cin >> entrada)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (usuario->getTipo() == TipoUsuario::ATENDENTE) {
            switch (entrada) {
                case 1:
                    telaClientesCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 2:
                    telaCadastrarCliente(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 0:
                    std::cout << "Saindo...\n";
                    break;
                default:
                    std::cout << "Opcao invalida.\n";
            }
        } else if (usuario->getTipo() == TipoUsuario::GERENTE) {
            switch (entrada) {
                case 1:
                    telaClientesCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 2:
                    telaCadastrarCliente(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 3:
                    telaAtendentesCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 4:
                    telaCadastrarAtendente(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 5:
                    telaPersonalTrainersCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 6:
                    telaCadastrarPersonalTrainer(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 0:
                    std::cout << "Saindo...\n";
                    break;
                default:
                    std::cout << "Opcao invalida.\n";
            }
        } else {
            switch (entrada) {
                case 1:
                    telaClientesCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 0:
                    std::cout << "Saindo...\n";
                    break;
                default:
                    std::cout << "Opcao invalida.\n";
            }
        }
    }
}

void telaClientesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    while (true) {
        std::cout << "\nClientes cadastrados:\n";
        for (const auto &c : clienteManager->listarClientes()) {
            std::cout << "Id: " << c.getId() << " - " << c.getNome() << '\n';
        }
        std::cout << "Selecione um cliente pelo Id (ou 0 para voltar): ";
        int idCliente;
        if (!(std::cin >> idCliente)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (idCliente == 0)
            break;

        Cliente cliente = clienteManager->obterCliente(idCliente);
        std::cout << "\nDetalhes do cliente:\n"
                  << "Id: " << cliente.getId() << "\nNome: " << cliente.getNome()
                  << "\nCpf: " << cliente.getCpf() << "\nEndereco: " << cliente.getEndereco()
                  << "\nTelefone: " << cliente.getTelefone() << "\n";

        int acao = -1;
        while (true) {
            std::cout << "\nSelecione uma opcao:\n"
                      << "1 - Atualizar dados\n"
                      << "2 - Remover cliente\n"
                      << "0 - Voltar\n"
                      << "Opcao: ";
            if (!(std::cin >> acao)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrada invalida.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (acao == 1) {
                int campo = -1;
                std::cout << "\nSelecione o campo para atualizar:\n"
                          << "1 - Nome\n"
                          << "2 - Cpf\n"
                          << "3 - Endereco\n"
                          << "4 - Telefone\n"
                          << "Opcao: ";
                if (!(std::cin >> campo)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada invalida.\n";
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string novoDado;
                switch (campo) {
                    case 1:
                        std::cout << "Informe o novo nome: ";
                        std::getline(std::cin, novoDado);
                        cliente.setNome(novoDado);
                        break;
                    case 2:
                        std::cout << "Informe o novo cpf: ";
                        std::getline(std::cin, novoDado);
                        cliente.setCpf(novoDado);
                        break;
                    case 3:
                        std::cout << "Informe o novo endereco: ";
                        std::getline(std::cin, novoDado);
                        cliente.setEndereco(novoDado);
                        break;
                    case 4:
                        std::cout << "Informe o novo telefone: ";
                        std::getline(std::cin, novoDado);
                        cliente.setTelefone(novoDado);
                        break;
                    default:
                        std::cout << "Opcao invalida para atualizacao.\n";
                        continue;
                }
                clienteManager->atualizarCliente(cliente);
                std::cout << "Dados atualizados com sucesso.\n";
                break;
            } else if (acao == 2) {
                clienteManager->removerCliente(cliente.getId());
                std::cout << "Cliente removido com sucesso.\n";
                break;
            } else if (acao == 0) {
                break;
            } else {
                std::cout << "Opcao invalida.\n";
            }
        }
        char continuar;
        std::cout << "\nDeseja tratar outro cliente? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (continuar == 'n' || continuar == 'N')
            break;
    }
}

void telaCadastrarCliente(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    std::string nomeCliente, cpfCliente, telefoneCliente, enderecoCliente;
    std::cout << "Informe o Nome do cliente: ";
    std::getline(std::cin, nomeCliente);
            
    std::cout << "Informe o cpf do cliente: ";
    std::getline(std::cin, cpfCliente);

    std::cout << "Informe o telefone do cliente: ";
    std::getline(std::cin, telefoneCliente);

    std::cout << "Informe o endereco do cliente: ";
    std::getline(std::cin, enderecoCliente);

    Cliente novoCliente(contadorId++, nomeCliente, cpfCliente, enderecoCliente, telefoneCliente);
    clienteManager->cadastrarCliente(novoCliente);
    std::cout << "Cliente cadastrado: " << novoCliente.getNome() << '\n';

    telaInicial(usuario, loginManager, clienteManager, usuarioManager);
}

void telaAtendentesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    while (true) {
        std::cout << "\nAtendentes cadastrados:\n";
        for (const auto &u : usuarioManager->listarUsuarios()) {
            if (u->getTipo() == TipoUsuario::ATENDENTE)
                std::cout << "Id: " << u->getId() << " - " << u->getNome() << '\n';
        }
        std::cout << "Selecione um atendente pelo Id (ou 0 para voltar): ";
        int idAtendente;
        if (!(std::cin >> idAtendente)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (idAtendente == 0)
            break;

        std::shared_ptr<Usuario> usuarioSelecionado = usuarioManager->obterUsuarioId(idAtendente);
        if (!usuarioSelecionado) {
            std::cout << "Atendente nao encontrado.\n";
            continue;
        }
        std::cout << "\nDetalhes do atendente:\n"
                  << "Id: " << usuarioSelecionado->getId() << "\nNome: " << usuarioSelecionado->getNome() << "\n";

        int acao = -1;
        while (true) {
            std::cout << "\nSelecione uma opcao:\n"
                      << "1 - Atualizar dados\n"
                      << "2 - Remover atendente\n"
                      << "0 - Voltar\n"
                      << "Opção: ";
            if (!(std::cin >> acao)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrada invalida.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (acao == 1) {
                int campo = -1;
                std::cout << "\nSelecione o campo para atualizar:\n"
                          << "1 - Nome\n"
                          << "2 - Login\n"
                          << "3 - Senha\n"
                          << "Opção: ";
                if (!(std::cin >> campo)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada invalida.\n";
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string novoDado;
                switch (campo) {
                    case 1:
                        std::cout << "Informe o novo nome: ";
                        std::getline(std::cin, novoDado);
                        usuarioSelecionado->setNome(novoDado);
                        break;
                    case 2:
                        std::cout << "Informe o novo login: ";
                        std::getline(std::cin, novoDado);
                        usuarioSelecionado->setLogin(novoDado);
                        break;
                    case 3:
                        std::cout << "Informe a nova senha: ";
                        std::getline(std::cin, novoDado);
                        usuarioSelecionado->setSenha(novoDado);
                        break;
                    default:
                        std::cout << "Opcao invalida para atualizacao.\n";
                        continue;
                }
                usuarioManager->atualizarUsuario(usuarioSelecionado);
                std::cout << "Dados atualizados com sucesso.\n";
                break;
            } else if (acao == 2) {
                usuarioManager->removerUsuario(usuarioSelecionado->getId());
                std::cout << "Atendente removido com sucesso.\n";
                break;
            } else if (acao == 0) {
                break;
            } else {
                std::cout << "Opcao invalida.\n";
            }
        }
        char continuar;
        std::cout << "\nDeseja tratar outro atendente? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (continuar == 'n' || continuar == 'N')
            break;
    }
}

void telaCadastrarAtendente(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    std::string nomeAtendente, loginAtendente, senhaAtendente;
    std::cout << "Informe o Nome do atendente: ";
    std::getline(std::cin, nomeAtendente);
            
    std::cout << "Informe o login do atendente: ";
    std::getline(std::cin, loginAtendente);

    std::cout << "Informe a senha do atendente: ";
    std::getline(std::cin, senhaAtendente);

    // Supondo que 'contadorIdUsuarios' seja uma variável global ou externa
    std::shared_ptr<Usuario> novoUsuario = std::make_shared<Atendente>(contadorIdUsuarios++, loginAtendente, senhaAtendente, nomeAtendente);
    usuarioManager->cadastrarUsuario(novoUsuario);
    std::cout << "Atendente cadastrado: " << novoUsuario->getNome() << '\n';

    telaInicial(usuario, loginManager, clienteManager, usuarioManager);
}

void telaPersonalTrainersCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    while (true) {
        std::cout << "\nPersonal Trainers cadastrados:\n";
        for (const auto &u : usuarioManager->listarUsuarios()) {
            if (u->getTipo() == TipoUsuario::PERSONAL_TRAINER)
                std::cout << "Id: " << u->getId() << " - " << u->getNome() << '\n';
        }
        std::cout << "Selecione um personal trainer pelo Id (ou 0 para voltar): ";
        int idTrainer;
        if (!(std::cin >> idTrainer)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (idTrainer == 0)
            break;

        std::shared_ptr<Usuario> trainerSelecionado = usuarioManager->obterUsuarioId(idTrainer);
        if (!trainerSelecionado) {
            std::cout << "Personal trainer nao encontrado.\n";
            continue;
        }
        std::cout << "\nDetalhes do personal trainer:\n"
                  << "Id: " << trainerSelecionado->getId() << "\nNome: " << trainerSelecionado->getNome() << "\n";

        int acao = -1;
        while (true) {
            std::cout << "\nSelecione uma opcao:\n"
                      << "1 - Atualizar dados\n"
                      << "2 - Remover personal trainer\n"
                      << "0 - Voltar\n"
                      << "Opcao: ";
            if (!(std::cin >> acao)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrada invalida.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (acao == 1) {
                int campo = -1;
                std::cout << "\nSelecione o campo para atualizar:\n"
                          << "1 - Nome\n"
                          << "2 - Login\n"
                          << "3 - Senha\n"
                          << "Opcao: ";
                if (!(std::cin >> campo)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada invalida.\n";
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string novoDado;
                switch (campo) {
                    case 1:
                        std::cout << "Informe o novo nome: ";
                        std::getline(std::cin, novoDado);
                        trainerSelecionado->setNome(novoDado);
                        break;
                    case 2:
                        std::cout << "Informe o novo login: ";
                        std::getline(std::cin, novoDado);
                        trainerSelecionado->setLogin(novoDado);
                        break;
                    case 3:
                        std::cout << "Informe a nova senha: ";
                        std::getline(std::cin, novoDado);
                        trainerSelecionado->setSenha(novoDado);
                        break;
                    default:
                        std::cout << "Opcao invalida para atualizacao.\n";
                        continue;
                }
                usuarioManager->atualizarUsuario(trainerSelecionado);
                std::cout << "Dados atualizados com sucesso.\n";
                break;
            } else if (acao == 2) {
                usuarioManager->removerUsuario(trainerSelecionado->getId());
                std::cout << "Personal trainer removido com sucesso.\n";
                break;
            } else if (acao == 0) {
                break;
            } else {
                std::cout << "Opcao invalida.\n";
            }
        }
        char continuar;
        std::cout << "\nDeseja tratar outro personal trainer? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (continuar == 'n' || continuar == 'N')
            break;
    }
}

void telaCadastrarPersonalTrainer(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    std::string nomePersonalTrainer, loginPersonalTrainer, senhaPersonalTrainer;
    std::cout << "Informe o Nome do personal trainer: ";
    std::getline(std::cin, nomePersonalTrainer);
            
    std::cout << "Informe o login do personal trainer: ";
    std::getline(std::cin, loginPersonalTrainer);

    std::cout << "Informe a senha do personal trainer: ";
    std::getline(std::cin, senhaPersonalTrainer);

    std::shared_ptr<Usuario> novoUsuario = std::make_shared<PersonalTrainer>(contadorIdUsuarios++, loginPersonalTrainer, senhaPersonalTrainer, nomePersonalTrainer);
    usuarioManager->cadastrarUsuario(novoUsuario);
    std::cout << "Personal Trainer cadastrado: " << novoUsuario->getNome() << '\n';

    telaInicial(usuario, loginManager, clienteManager, usuarioManager);
}