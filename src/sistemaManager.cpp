#include <sistemaManager.hpp>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>

int contadorId = 7;
int contadorIdUsuarios = 4;


void iniciarSistema() {
    std::vector<std::shared_ptr<Cliente>> clientes {
        std::make_shared<Cliente>(1, "Joao Silva", "123.456.789-00", "Rua A, 123", "(11) 98765-4321", "01/01/2001", "06/02/2025"),
        std::make_shared<Cliente>(2, "Maria Oliveira", "987.654.321-00", "Rua B, 456", "(11) 91234-5678", "02/01/2001", "02/02/2025"),
        std::make_shared<Cliente>(3, "Carlos Santos", "111.222.333-44", "Av. C, 789", "(11) 99876-5432", "10/01/2001", "06/02/2025"),
        std::make_shared<Cliente>(4, "Ana Paula", "555.666.777-88", "Rua D, 101", "(11) 90000-0000", "01/10/2001", "06/12/2025"),
        std::make_shared<Cliente>(5, "Mariana Costa", "999.888.777-66", "Av. E, 202", "(11) 91111-2222", "01/01/2001", "06/02/2025"),
        std::make_shared<Cliente>(6, "Reginaldo Afonso Padilha", "403.020.123-90", "Av. W 210", "(11) 91111-2222", "01/01/2001", "07/02/2025")
    };

    Atendente eduardo(1, "eduardo", "maromba", "Eduardo");
    PersonalTrainer suteam(2, "suteam", "mateus", "Matheus Vinicius");
    Gerente root(3, "root", "root", "Administrador");

    std::vector<std::shared_ptr<Usuario>> usuarios;
    usuarios.push_back(std::make_shared<Atendente>(eduardo));
    usuarios.push_back(std::make_shared<PersonalTrainer>(suteam));
    usuarios.push_back(std::make_shared<Gerente>(root));

    std::shared_ptr<UsuarioDAO> usuarioDAO = std::make_shared<UsuarioDAO>(UsuarioDAO(usuarios));
    std::shared_ptr<LoginManager> loginManager = std::make_shared<LoginManager>(usuarioDAO);
    std::shared_ptr<UsuarioManager> usuarioManager = std::make_shared<UsuarioManager>(usuarioDAO);

    std::shared_ptr<ClienteManager> clienteManager = std::make_shared<ClienteManager>(std::make_shared<ClienteDAO>(clientes));

    login(loginManager, clienteManager, usuarioManager);
}

void login(std::shared_ptr<LoginManager> loginManager, std::shared_ptr<ClienteManager> clienteManager, std::shared_ptr<UsuarioManager> usuarioManager) {
    std::string login, senha;
    std::cout << "Bem-vindo ao sistema BioCad\n";
    std::cout << "Login: ";
    std::getline(std::cin, login);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);


    std::shared_ptr<Usuario> usuario = loginManager->autenticar(login, senha);
    while(usuario == nullptr) {
        std::cout << "Credenciais incorretas.\nTente novamente:\n";
        std::cout << "Login: ";
        std::getline(std::cin, login);
        std::cout << "Senha: ";
        std::getline(std::cin, senha);
        usuario = loginManager->autenticar(login, senha);
    }

    menuInicial(usuario, loginManager, clienteManager, usuarioManager);
}


void menuInicial(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    int entrada = -1;
    while (entrada != 0) {
        std::cout << "\nBem-vindo " << usuario->getNome() << "\n";
        auto usuarioOpcoes = usuario->getInterface();
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
                    listarClientesCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 2:
                    cadastrarCliente(usuario, loginManager, clienteManager, usuarioManager);
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
                    listarClientesCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 2:
                    cadastrarCliente(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 3:
                    listarAtendentesCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 4:
                    cadastrarAtendente(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 5:
                    listarPersonalTrainersCadastrados(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 6:
                    cadatrarPersonalTrainer(usuario, loginManager, clienteManager, usuarioManager);
                    break;
                case 7:
                    relatorioFrequencia(usuario, loginManager, clienteManager, usuarioManager);
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
                    listarClientesCadastradosPersonalTrainer(usuario, loginManager, clienteManager, usuarioManager);
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

void listarClientesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    while (true) {
        std::cout << "\nClientes cadastrados:\n";
        for (const auto &c : clienteManager->getClientes()) {
            std::cout << "Id: " << c->getId() << " - " << c->getNome() << '\n';
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
        if (idCliente == 0) break;

        cadastroCliente(usuario, loginManager, clienteManager, usuarioManager, idCliente);
        char continuar;
        std::cout << "\nDeseja tratar outro cliente? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (continuar == 'n' || continuar == 'N')
            break;
    }
}

void cadastrarCliente(std::shared_ptr<Usuario> usuario,
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

    std::shared_ptr<Cliente> novoCliente = std::make_shared<Cliente>(contadorId++, nomeCliente, cpfCliente, enderecoCliente, telefoneCliente, "01/01/2001", "01/01/2025");
    clienteManager->cadastrarCliente(novoCliente);
    std::cout << "Cliente cadastrado: " << novoCliente->getNome() << '\n';

}

void listarAtendentesCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    while (true) {
        std::cout << "\nAtendentes cadastrados:\n";
        for (const auto &u : usuarioManager->getUsuarios()) {
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

        std::shared_ptr<Usuario> usuarioSelecionado = usuarioManager->getUsuarioId(idAtendente);
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

void cadastrarAtendente(std::shared_ptr<Usuario> usuario,
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

    std::shared_ptr<Usuario> novoUsuario = std::make_shared<Atendente>(contadorIdUsuarios++, loginAtendente, senhaAtendente, nomeAtendente);
    usuarioManager->cadastrarUsuario(novoUsuario);
    std::cout << "Atendente cadastrado: " << novoUsuario->getNome() << '\n';

}

void listarPersonalTrainersCadastrados(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    while (true) {
        std::cout << "\nPersonal Trainers cadastrados:\n";
        for (const auto &u : usuarioManager->getUsuarios()) {
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

        std::shared_ptr<Usuario> trainerSelecionado = usuarioManager->getUsuarioId(idTrainer);
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

void cadatrarPersonalTrainer(std::shared_ptr<Usuario> usuario,
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
}

void listarClientesCadastradosPersonalTrainer(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {

    while (true) {
        std::cout << "\nClientes cadastrados:\n";
        for (const auto &c : clienteManager->getClientes()) {
            std::cout << "Id: " << c->getId() << " - " << c->getNome() << '\n';
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
        if (idCliente == 0) break;
        cadastroClientePersonalTrainer(usuario, loginManager, clienteManager, usuarioManager, idCliente);
        char continuar;
        std::cout << "\nDeseja tratar outro cliente? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (continuar == 'n' || continuar == 'N')
            break;
    }
}

void cadastroCliente(std::shared_ptr<Usuario> usuario, 
    std::shared_ptr<LoginManager> loginManager, 
    std::shared_ptr<ClienteManager> clienteManager, 
    std::shared_ptr<UsuarioManager> usuarioManager, int idCliente) {

    std::shared_ptr<Cliente> cliente = clienteManager->getCliente(idCliente);
    std::cout << "\n\nDetalhes do cliente:\n"
              << "Id: " << cliente->getId() << "\nNome: " << cliente->getNome()
              << "\nCpf: " << cliente->getCpf() << "\nEndereco: " << cliente->getEndereco()
              << "\nTelefone: " << cliente->getTelefone() << '\n'
              << "\nCheck Ins: " << cliente->getCheckIns() << '\n';
    int acao = -1;
    while (true) {
        std::cout << "\nSelecione uma opcao:\n"
                  << "1 - Atualizar dados\n"
                  << "2 - Visualizar contrato\n"
                  << "3 - Remover cliente\n"
                  << "4 - Realizar Check In\n"
                  << "5 - Realizar Check Out\n"
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
                    cliente->setNome(novoDado);
                    break;
                case 2:
                    std::cout << "Informe o novo cpf: ";
                    std::getline(std::cin, novoDado);
                    cliente->setCpf(novoDado);
                break;
                case 3:
                    std::cout << "Informe o novo endereco: ";
                    std::getline(std::cin, novoDado);
                    cliente->setEndereco(novoDado);
                    break;
                case 4:
                    std::cout << "Informe o novo telefone: ";
                    std::getline(std::cin, novoDado);
                    cliente->setTelefone(novoDado);
                    break;
                default:
                    std::cout << "Opcao invalida para atualizacao.\n";
                    continue;
            }
            clienteManager->atualizarCliente(cliente);
            std::cout << "Dados atualizados com sucesso.\n";
            break;
        } else if(acao == 2) {
            int campo = -1, index;
            Contrato contrato = cliente->getContratoVigente();
            std::cout << "Plano vigente: " << contrato.getPlanoVigente().getNome()
                      << "\nTipo de plano: " << planoString(contrato.getPlanoVigente().getTipo())
                      << "\nMensalidades nao pagas: ";
            contrato.mensalidadesNaoPagas();
            std::cout << "\n1 - Pagar mensalidade"
                      << "\n0 - Voltar"
                      << "\nOpcao: ";
            if (!(std::cin >> campo)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrada invalida.\n";
                continue;
            }
            switch(campo) {
                case 1:
                    std::cout << "Digite o index da mensalidade: ";
                    if (!(std::cin >> index)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Entrada invalida.\n";
                        continue;
                    }
                    contrato.pagarMensalidade(index);
                    cliente->setContratoVigente(contrato);
                    std::cout << "Mensalidade paga com sucesso.";
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Opcao invalida.\n";
                    continue;
            }
        } else if (acao == 3) {
            clienteManager->removerCliente(cliente->getId());
            std::cout << "Cliente removido com sucesso.\n";
            break;
        } else if (acao == 4) {
            clienteManager->checkInCliente(cliente);
            std::cout << "Check In atualizado com sucesso.\n";
        } else if(acao == 5) {
            clienteManager->checkOutCliente(cliente);
            std::cout << "Check Out atualizado com sucesso.\n";
        } else if (acao == 0) {
            break;
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

void cadastroClientePersonalTrainer(std::shared_ptr<Usuario> usuario, 
    std::shared_ptr<LoginManager> loginManager, 
    std::shared_ptr<ClienteManager> clienteManager, 
    std::shared_ptr<UsuarioManager> usuarioManager, int idCliente) {
    std::shared_ptr<Cliente> cliente = clienteManager->getCliente(idCliente);
    std::cout << "\n\nDetalhes do cliente:\n"
              << "Id: " << cliente->getId() << "\nNome: " << cliente->getNome()
              << "\nTreino: " << cliente->getPlanoDeTreino().getTipoTreino()
              << "\nObjetivo: " << cliente->getPlanoDeTreino().getObjetivos()
              << "\nCondicoes especiais: " << cliente->getPlanoDeTreino().getCondicaoEspecial() << "\n";

    int acao = -1;
    while (true) {
        std::cout << "\nSelecione uma opcao:\n"
                  << "1 - Atualizar dados\n"
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
            Treino novoTreino = cliente->getPlanoDeTreino();
            int campo = -1;
            std::cout << "\nSelecione o campo para atualizar:\n"
                      << "1 - Tipo de Treino\n"
                      << "2 - Objetivo\n"
                      << "3 - Condicoes especiais\n"
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
                    std::cout << "Informe o novo tipo de treino: ";
                    std::getline(std::cin, novoDado);
                    novoTreino.setTipoTreino(novoDado);
                    break;
                case 2:
                    std::cout << "Informe o novo objetivo: ";
                    std::getline(std::cin, novoDado);
                    novoTreino.setObjetivos(novoDado);
                    break;
                case 3:
                    std::cout << "Informe a condicao especial: ";
                    std::getline(std::cin, novoDado);
                    novoTreino.setCondicaoEspecial(novoDado);
                    break;
                default:
                    std::cout << "Opcao invalida para atualizacao.\n";
                    continue;
            }
            cliente->setPlanoDeTreino(novoTreino);
            clienteManager->atualizarCliente(cliente);
            std::cout << "Dados atualizados com sucesso.\n";
            break;
        } else if (acao == 0) {
            break;
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

void relatorioFrequencia(std::shared_ptr<Usuario> usuario,
    std::shared_ptr<LoginManager> loginManager,
    std::shared_ptr<ClienteManager> clienteManager,
    std::shared_ptr<UsuarioManager> usuarioManager) {
    
    // Gera o relatorio na login
    std::cout << "\nRelatorio de Frequencia de Clientes\n";
    
    auto clientes = clienteManager->getClientes();
    
    std::stringstream relatorio;
    relatorio << std::left 
              << std::setw(5) << "ID" 
              << std::setw(25) << "Nome"
              << std::setw(15) << "Check-Ins"
              << std::setw(15) << "Check-Outs"
              << "\n";
    
    for (const auto& cliente : clientes) {
        relatorio << std::left
                  << std::setw(5) << cliente->getId()
                  << std::setw(25) << cliente->getNome().substr(0, 24)
                  << std::setw(15) << cliente->getCheckIns()
                  << std::setw(15) << cliente->getCheckOuts()
                  << "\n";
    }
    
    std::cout << relatorio.str();
    
    // Opção de exportação
    char opcao;
    std::cout << "\nDeseja exportar para arquivo texto? (s/n): ";
    std::cin >> opcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (tolower(opcao) == 's') {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::stringstream filename;
        filename << "relatorio_frequencia_"
                 << std::put_time(std::localtime(&now_c), "%Y%m%d_%H%M%S")
                 << ".txt";

        std::ofstream arquivo(filename.str());
        if (arquivo.is_open()) {
            arquivo << "Relatorio de Frequencia - BioCad\n";
            arquivo << "Gerado em: " 
                    << std::put_time(std::localtime(&now_c), "%d/%m/%Y %H:%M:%S") 
                    << "\n\n";
            arquivo << relatorio.str();
            arquivo.close();
            std::cout << "Arquivo salvo como: " << filename.str() << "\n";
        } else {
            std::cout << "Erro ao salvar o arquivo!\n";
        }
    }
}