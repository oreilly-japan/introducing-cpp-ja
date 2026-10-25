#include <iostream>
#include <memory>
#include <print>

#include "asset.h"
#include "historical_prices.h"
#include "stock.h"
#include "trade.h"

int main(int argc, char *argv[])
{
    using namespace stock_prices;
    test_trades();

    std::unique_ptr<Asset> asset{
        std::make_unique<Stock>("Coffee", 4.8, 0.0113)
    };
    Exchange exchange{1, std::move(asset)};
    auto profit = trading_game(exchange);
    std::println("Total profit ${:.2f}", profit);
    std::println("Game over");
    std::println("Rerun? [y]es n[o]?");
    char choice;
    std::cin >> choice;

    if (choice == 'y')
    {
        Exchange historical_exchange{ 1,
            std::make_unique<HistoricalPrices>(exchange.get_prices())
        };
        profit = trading_game(historical_exchange);
        std::println("Total profit ${:.2f}", profit);
        std::println("Game over");
    }
}
