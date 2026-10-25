#include <iostream>
#include <print>
#include <stdexcept>

#include "input.h"

void trading_game(const std::vector<double> & prices)
{
    const double initial_funds{100.0};
    double funds{initial_funds};
    int number_of_shares{};

    for(auto price : prices)
    {
        auto status = std::format("Funds ${:.2f}, Shares {}",
                                   funds, number_of_shares); //<1>
        std::println("{}", status);
        auto price_message = std::format("Current price: ${:.2f}", price); //<2>
        std::println("{: >{}}", price_message, status.size()); //<3>
        std::println("Press (s) to sell, (b) to buy");
        std::print("or something else to continue>"); //<4>
        char choice{};
        std::cin >> choice; //<5>

        if (choice == 's') //<6>
        {
            if(number_of_shares > 0) //<7>
            {
                --number_of_shares;
                funds += price;
            }
            else
            {
                std::println("No stock to sell");
            }
        }
        else if(choice == 'b') //<8>
        {
            if(price <= funds) //<9>
            {
                ++number_of_shares;
                funds -= price;
            }
            else
            {
                std::println("Insufficient funds");
            }
        }
    }
    std::println("Total profit ${:.2f}", funds - initial_funds); //<10>
    std::cout << "Game over\n"; 
}

void write_to_file_improved(const std::vector<double> & prices,
        const std::string & filename)
{
    const std::filesystem::path path = std::filesystem::current_path();
    const auto fully_pathed_filename = path / filename;
    std::ofstream file{filename};
    if(file)
    {
        for(auto price: prices)
        {
            std::println(file, "{:.2f}", price); //<1>
        }
        std::println("Wrote to {}", fully_pathed_filename.string()); //<2>
    }
    else
    {
        throw std::runtime_error(
                   std::format("Failed to write to {}", //<3>
                       fully_pathed_filename.string() //<4>
                   )
        ); // ❹
    }
}

int main(int argc, char *argv[])
{
    using namespace stock_prices;
    const auto prices = (argc>1) ? read_from_file(argv[1]) :
                                   get_prices(100.0, 10, 0.05);
    write_to_file_improved(prices, argv[1]);
    trading_game(prices); //<1>
}
