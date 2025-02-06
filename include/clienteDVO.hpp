#pragma once
#include <string>
#include <vector>

enum class TipoPlano {
    MENSAL,
    SEMESTRAL,
    ANUAL,
    TRIMESTRAL
};

enum class Status {
    PENDENTE,
    PAGO
};


class Treino {
    std::string objetivos;
    std::string condicaoEspecial;
    std::string tipoTreino;

    public:
    Treino(const std::string& objetivos = "Ganho de massa", const std::string& condicaoEspecial = "Nenhuma", const std::string& tipoTreino = "Flexao a rodo")
        : objetivos(objetivos), condicaoEspecial(condicaoEspecial), tipoTreino(tipoTreino) {};
};

class Mensalidade {
    int dataVencimentoRelativa;
    float valor;
    Status status;
    
    public:
    Mensalidade(int dataVencimentoRelativa = 2, float valor = 150.f, const Status& status = Status::PENDENTE) : dataVencimentoRelativa(dataVencimentoRelativa), valor(valor), status(status) {};
};

class Plano {
    std::string nome;
    TipoPlano tipo;

    public:
    Plano(const std::string& nome = "Mensal", const TipoPlano& tipo = TipoPlano::MENSAL) : nome(nome), tipo(tipo) {};
};

class Contrato {
    Plano planoVigente;
    Treino planoDeTreino;
    std::vector<Mensalidade> mensalidades;

    public:
    Contrato(const Plano& planoVigente = Plano(), const Treino& planoDeTreino = Treino()) : planoVigente(planoVigente), planoDeTreino(planoDeTreino) {

    };
};

class Cliente {
private:
    int id;
    std::string nome;
    std::string cpf;
    std::string endereco;
    std::string telefone;
    std::string dataNascimento;
    std::string dataCadastro;
    Contrato contratoVigente;
public:
    Cliente() : id(-1), nome(""), cpf(""), endereco(""), telefone(""), dataNascimento(""), dataCadastro(""), contratoVigente(Contrato()) {}
    Cliente(int id, const std::string &nome, const std::string &cpf, const std::string &endereco, const std::string &telefone, const std::string &dataNascimento, const std::string &dataCadastro, const Contrato& contratoVigente = Contrato())
     : id(id), nome(nome), cpf(cpf), telefone(telefone), endereco(endereco), dataNascimento(dataNascimento), dataCadastro(dataCadastro), contratoVigente(contratoVigente) { }
    

    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getCpf() const { return cpf; }
    std::string getEndereco() const { return endereco; }
    std::string getTelefone() const { return telefone; }
    std::string getDataNascimento() const { return dataNascimento; }
    std::string getDataCadastro() const { return dataCadastro; }


    void setId(int id) { this->id = id; }
    void setNome(const std::string &nome) { this->nome = nome; }
    void setCpf(const std::string &cpf) { this->cpf = cpf; }
    void setEndereco(const std::string &endereco) { this->endereco = endereco; }
    void setTelefone(const std::string &telefone) { this->telefone = telefone; }
    void setDataNascimento(const std::string &dataNascimento) { this->dataNascimento = dataNascimento; }
    void setDatacadastro(const std::string &dataCadastro) { this->dataCadastro = dataCadastro; }

};