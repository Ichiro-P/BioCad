#pragma once
#include <string>
#include <vector>

enum class TipoUsuario {
    ATENDENTE,
    PERSONAL_TRAINER,
    GERENTE
};

class Usuario {
    int id;
    std::string login;
    std::string senha;
    std::string nome;
    TipoUsuario tipo;
public:
    Usuario() : id(0), login(""), senha(""), nome(""), tipo(TipoUsuario::ATENDENTE) { }
    Usuario(int id, const std::string &login, const std::string &senha,
            const std::string &nome, TipoUsuario tipo)
        : id(id), login(login), senha(senha), nome(nome), tipo(tipo) { }
    
    virtual ~Usuario() { }
    
    int getId() const { return id; }
    std::string getLogin() const { return login; }
    std::string getSenha() const { return senha; }
    std::string getNome() const { return nome; }
    TipoUsuario getTipo() const { return tipo; }

    void setLogin(const std::string& novoLogin) { login = novoLogin; }
    void setSenha(const std::string& novaSenha) { senha = novaSenha; }
    void setNome(const std::string& novoNome) { nome = novoNome; }
    void setTipo(TipoUsuario novoTipo) { tipo = novoTipo; }
    
    virtual std::vector<std::string> getInterface() const { return {"achou que teria algo"}; };
};