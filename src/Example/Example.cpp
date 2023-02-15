//
//  Example.cpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-12.
//

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "DB/Handle.hpp"
#include "MenuItem.hpp"

void printMenu(std::vector<MenuItem>& menu, std::string header)
{
    std::cout << header << std::endl;
    for (int i = 0; i < menu.size(); i++) {
        std::cout << "  ";
        std::cout << std::left << std::setw(18) << menu[i].name() << "$";
        std::cout << std::right << std::setw(6) << std::fixed << std::setprecision(2) << menu[i].price();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, const char* argv[])
{
    DB::Handle db("data.db");
    
    db.destroyWhere(MenuItem(), {});

    MenuItem m1("Coffee", 2.29);
    MenuItem m2("Latte", 3.00);
    MenuItem m3("Cappuccino", 3.00);
    MenuItem m4("Cookie", 1.49);
    MenuItem m5("Lunch Combo 1", 10.99);
    MenuItem m6("Lunch Combo 2", 11.99);
    MenuItem m7("Breakfast Combo", 9.99);

    /*
     * INSERT
     */
    
    db.insert(m1);
    db.insert(m2);
    db.insert(m3);
    db.insert(m4);
    db.insert(m5);
    db.insert(m6);
    db.insert(m7);

    /*
     * SELECT
     */

    std::vector<MenuItem> menu;

    menu = db.select(MenuItem());
    printMenu(menu, "Menu, unsorted:");

    menu = db.select(MenuItem(), {}, "", {"name"});
    printMenu(menu, "Menu, unsorted, only name selected:");

    menu = db.select(MenuItem(), {}, "price");
    printMenu(menu, "Menu, sorted by ascending price:");

    menu = db.select(MenuItem(), {}, "price,name");
    printMenu(menu, "Menu, sorted by ascending price, then name:");

    menu = db.select(MenuItem(), {
        DB::Condition("price", DB::OP::GTE, 3.00),
        DB::Condition("price", DB::OP::LT, 10.00)
    }, "price DESC");
    printMenu(menu, "Menu where 3.00 <= price < 10.00, sorted by descending price:");

    menu = db.select(MenuItem(), {
        DB::Condition("name", DB::OP::EQ, "Cookie")
    });
    printMenu(menu, "Menu where name = 'cookie', unsorted:");

    menu = db.select(MenuItem(), {
        DB::Condition("name", DB::OP::STARTSWITH, "co")
    });
    printMenu(menu, "Menu where name starts with 'co', unsorted:");

    menu = db.select(MenuItem(), {
        DB::Condition("name", DB::OP::CONTAINS, "combo")
    }, "price");
    printMenu(menu, "Menu where name contains 'combo', sorted by ascending price.");

    menu = db.select(MenuItem(), {
        DB::Condition("name", DB::OP::IN, std::vector<std::string>({
            "Coffee", "Latte"
        }))
    });
    printMenu(menu, "Menu where name in ('Coffee', 'Latte'), unsorted.");

    /*
     * UPDATE
     */

    m6.price(69.99);
    db.update(m6);
    menu = db.select(MenuItem());
    printMenu(menu, "Menu after Lunch Combo 2 price was updated to 69.99, unsorted:");

    MenuItem updatedModel = MenuItem("", 29.99);
    db.updateWhere(updatedModel, {
        DB::Condition("price", DB::OP::GT, 9.99)
    }, {"price"});
    menu = db.select(MenuItem());
    printMenu(menu, "Menu after price was updated to 29.99 where price > 9.99, unsorted:");

    /*
     * DELETE
     */

    db.destroy(m6);
    menu = db.select(MenuItem());
    printMenu(menu, "Menu after Lunch Combo 2 was deleted, unsorted:");

    db.destroyWhere(MenuItem(), {
        DB::Condition("price", DB::OP::LTE, 5.00)
    });
    menu = db.select(MenuItem());
    printMenu(menu, "Menu after everything with price <= 5.00 was deleted, unsorted:");

    db.destroyWhere(MenuItem(), {});
    menu = db.select(MenuItem());
    printMenu(menu, "Menu after everything was deleted:");

    return 0;
}
