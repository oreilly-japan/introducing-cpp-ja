#include <memory>
#include <print>

#include "asset.h"
#include "stock.h"
#include "trade.h"

int main(int argc, char *argv[])
{
    using namespace stock_prices;
    test_stock(); //<1>
    test_trades(); //<2>

    std::unique_ptr<Asset> asset{
        std::make_unique<Stock>("Coffee", 4.8, 0.0113) //<3>
    };
    Exchange exchange{1, std::move(asset)}; //<4>
    auto profit = trading_game(exchange); //<5>
    std::println("Total profit ${:.2f}", profit); //<6>
    std::println("Game over");
}
