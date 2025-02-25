#pragma once

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include <chrono>
#include <enums.hpp>

class CheckInDVO {
    std::string cpfCliente = "";
    std::tm dataHora;
    public:
    CheckInDVO() =  default;
    CheckInDVO(const std::string &cpfCliente);
    std::string getCpfCliente() { return cpfCliente; };
    std::tm getDataHora() const&;
};

class CheckInDAO {
    std::vector<std::unique_ptr<CheckInDVO>> checkIns;
    public:
    CheckInDAO() = default;
    void create(const std::string &cpfCliente);
    std::vector<CheckInDVO> getCheckInsDVO() const&;
};

class CheckInManager {
    std::unique_ptr<CheckInDAO> checkInDAO = nullptr;
    public:
    CheckInManager() = default;
    CheckInManager(CheckInDAO &&checkIn) : checkInDAO(std::make_unique<CheckInDAO>(std::move(checkIn))) {};
    void adicionarCheckIn(const std::string &cpfCliente) { if(!cpfCliente.empty()) checkInDAO->create(cpfCliente); };
    std::vector<CheckInDVO> getCheckInsPeriodo(const std::tm &dataInicio, const std::tm &dataFim);
};