#pragma once

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include <chrono>
#include <checkIn.hpp>
#include <checkOut.hpp>
#include <enums.hpp>

class RelatorioDVO {
    std::tm dataInicio;
    std::tm dataFim;
    std::vector<CheckInDVO> checkInsPeriodo;
    std::vector<CheckOutDVO> checkOutsPeriodo;
    public:
    RelatorioDVO() = default;
    RelatorioDVO(const std::tm &dataInicio, const std::tm &dataFim, const std::vector<CheckInDVO> &checkInsPeriodo, const std::vector<CheckOutDVO> &checkOutsPeriodo)
        : dataInicio(dataInicio), dataFim(dataFim), checkInsPeriodo(checkInsPeriodo), checkOutsPeriodo(checkOutsPeriodo) {};
    
    std::tm getDataInicio() const& { return dataInicio; };
    std::tm getDataFim() const& { return dataFim; };
    std::vector<CheckInDVO> getCheckInsPeriodo() const& { return checkInsPeriodo; };
    std::vector<CheckOutDVO> getCheckoutsPeriodo() const& { return checkOutsPeriodo; };
};

class RelatorioManager {
    public:
    bool validarPeriodo(const std::tm &dataInicio, const std::tm &dataFim);
    RelatorioDVO gerarRelatorioFrequencia(const std::tm &dataInicio, const std::tm &dataFim, const std::vector<CheckInDVO> &checkInsPeriodo, const std::vector<CheckOutDVO> &checkOutsPeriodo);
};