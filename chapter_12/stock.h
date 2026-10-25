#pragma once

#include <random>
#include <string>

namespace stock_prices
{
    class Stock
    {
        std::string name{}; 
        double last_price{}; 
        double volatility{}; 
        std::default_random_engine gen; 
        std::normal_distribution<double> distrib; 

    public:
        Stock(const std::string & stock_name,
            double start_price,
            double start_volatility);

        Stock(const Stock & other) = delete;
        Stock(Stock && other) noexcept = default;

        Stock & operator = (const Stock & other) = delete;
        Stock & operator = (Stock && other) noexcept = default;

        std::string get_name() const
        {
            return name;
        }

        double get_price() const //<1>
        {
            return last_price;
        }

        double next_price();
    };
}