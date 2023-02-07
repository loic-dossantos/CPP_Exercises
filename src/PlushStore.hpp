#pragma once
#include "Plush.hpp"

#include <optional>
#include <string>
#include <vector>

class PlushStore
{
public:
    PlushStore(std::string name)
        : _name(name) {}

    std::string get_name() const { return _name; }

    int get_wealth_amount() const { return _wealth_amount; }

    int get_stock_size() const { return _stock_size; }

    int get_debt_amount() const { return _debt_amount; }

    void loan(int money) {
        _wealth_amount += money;
        _debt_amount += 1.1 * money;
    }

    int make_plush(int plush_cost) {
        if (_wealth_amount > 0) {
            Plush plush = Plush(plush_cost);
            _stock.emplace_back(plush);
            _stock_size++;
            _wealth_amount -= plush_cost;
            _experience++;
            if (_wealth_amount < 0) {
                auto res       = _wealth_amount;
                _wealth_amount = 0;
                return plush_cost - res + _experience;
            }
            return plush_cost + _experience;
        }
        return 0;
    }

    int get_experience() const { return _experience; }

    std::optional<Plush> buy(int money) {
        money++;
        _stock.emplace_back(Plush(5));
        return std::nullopt;
    }

private:
    std::string        _name {};
    int                _wealth_amount { 0 };
    int                _debt_amount { 0 };
    int                _stock_size { 0 };
    int                _experience { 0 };
    std::vector<Plush> _stock {};
};