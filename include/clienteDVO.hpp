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

std::string planoString(const TipoPlano& plano);

class Treino {
    std::string objetivos;
    std::string condicaoEspecial;
    std::string tipoTreino;

    public:
    Treino(const std::string& objetivos = "Ganho de massa", const std::string& condicaoEspecial = "Nenhuma", const std::string& tipoTreino = "Flexao a rodo")
        : objetivos(objetivos), condicaoEspecial(condicaoEspecial), tipoTreino(tipoTreino) {};

    virtual ~Treino() = default;
    std::string getObjetivos() const { return objetivos; };
    std::string getCondicaoEspecial() const { return condicaoEspecial; };
    std::string getTipoTreino() const { return tipoTreino; };

    void setObjetivos(const std::string& novoObjetivo) { objetivos = novoObjetivo; };
    void setCondicaoEspecial(const std::string& novaCondicaoEspecial) { condicaoEspecial = novaCondicaoEspecial; };
    void setTipoTreino(const std::string& novoTipoTreino) { tipoTreino = novoTipoTreino; };
};

class Mensalidade {
    int dataVencimentoRelativa;
    float valor;
    Status status;
    
    public:
    Mensalidade(int dataVencimentoRelativa = 2, float valor = 150.f, const Status& status = Status::PENDENTE)
     : dataVencimentoRelativa(dataVencimentoRelativa), valor(valor), status(status) {};
    virtual ~Mensalidade() = default;

    int getDataVencimentoRelativa() const { return dataVencimentoRelativa; };
    float getValor() const { return valor; };
    Status getStatus() const { return status; };

    void setDataVencimentoRelativa(int novaDuracao) { this->dataVencimentoRelativa = novaDuracao; };
    void setValor(float novoValor) { this->valor = novoValor; };
    void setStatus(const Status& novoStatus) { this->status = novoStatus; };
};

class Plano {
    std::string nome;
    TipoPlano tipo;

    public:
    Plano(const std::string& nome = "Mensal", const TipoPlano& tipo = TipoPlano::MENSAL) : nome(nome), tipo(tipo) {};
    virtual ~Plano() = default;

    std::string getNome() const { return this->nome; };
    TipoPlano getTipo() const { return this->tipo; };

    void setNome(const std::string& novoNome) { this->nome = novoNome; };
    void setTipo(const TipoPlano& novoTipo) { this->tipo = novoTipo; };
};

class Contrato {
    Plano planoVigente;
    std::vector<Mensalidade> mensalidades;

    public:
    Contrato(const Plano& planoVigente = Plano());
    virtual ~Contrato() = default;

    void mensalidadesNaoPagas();
    Plano getPlanoVigente() const { return planoVigente; };
    void pagarMensalidade(int index) { mensalidades[index].setStatus(Status::PAGO); };

    void setPlanoVigente(const Plano& novoPlano) { planoVigente = novoPlano; };
    
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
    Treino planoDeTreino;
public:
    Cliente() : id(-1), nome(""), cpf(""), endereco(""), telefone(""), dataNascimento(""), dataCadastro(""), contratoVigente(Contrato()), planoDeTreino(Treino()) {}
    Cliente(int id, const std::string &nome, const std::string &cpf, const std::string &endereco, const std::string &telefone, const std::string &dataNascimento, const std::string &dataCadastro, const Contrato& contratoVigente = Contrato(), const Treino& planodeTreino = Treino())
     : id(id), nome(nome), cpf(cpf), telefone(telefone), endereco(endereco), dataNascimento(dataNascimento), dataCadastro(dataCadastro), contratoVigente(contratoVigente), planoDeTreino(Treino()) { }
    
    virtual ~Cliente() = default;

    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getCpf() const { return cpf; }
    std::string getEndereco() const { return endereco; }
    std::string getTelefone() const { return telefone; }
    std::string getDataNascimento() const { return dataNascimento; }
    std::string getDataCadastro() const { return dataCadastro; }
    Contrato getContratoVigente() const { return contratoVigente; }
    Treino getPlanoDeTreino() const { return planoDeTreino; }

    void setNome(const std::string &novoNome) { nome = novoNome; }
    void setCpf(const std::string &novoCpf) { cpf = novoCpf; }
    void setEndereco(const std::string &novoEndereco) { endereco = novoEndereco; }
    void setTelefone(const std::string &novoTelefone) { telefone = novoTelefone; }
    void setDataNascimento(const std::string &novaDataNascimento) { dataNascimento = novaDataNascimento; }
    void setDatacadastro(const std::string &novaDataCadastro) { dataCadastro = novaDataCadastro; }
    void setContratoVigente(const Contrato& novoContrato) { contratoVigente = novoContrato; }
    void setPlanoDeTreino(const Treino& novoTreino) { planoDeTreino = novoTreino; }
};