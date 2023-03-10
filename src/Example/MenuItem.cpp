//
//  MenuItem.cpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-13.
//

#include "MenuItem.hpp"

MenuItem::MenuItem(const std::string& name, const double price)
: name_(name), price_(price)
{
    
}

std::string MenuItem::name() const
{
    return name_;
}

double MenuItem::price() const
{
    return price_;
}

void MenuItem::name(const std::string& value)
{
    name_ = value;
}

void MenuItem::price(const double value)
{
    price_ = value;
}

const std::string& MenuItem::table() const
{
    static const std::string table = "MenuItem";
    return table;
}

const std::vector<std::string>& MenuItem::columns() const
{
    static const std::vector<std::string> columns = {
        "name", "price"
    };
    return columns;
}

const std::set<std::string>& MenuItem::keys() const
{
    static const std::set<std::string> keys = {
        "name"
    };
    return keys;
}

bool MenuItem::isAutoGeneratedKey() const
{
    return false;
}

std::map<std::string, DB::Datatype> MenuItem::toMap() const
{
    static const std::vector<std::string>& cols = columns();
    
    std::map<std::string, DB::Datatype> result;
    
    result[cols[0]] = name_;
    result[cols[1]] = price_;
    
    return result;
}

DB::Object* MenuItem::fromMap(const std::map<std::string,
                              DB::Datatype>& dbObjectMap) const
{
    static const std::vector<std::string>& cols = columns();
    
    std::string name = dbObjectMap.at(cols[0]).cast<std::string>();
    double price = dbObjectMap.at(cols[1]).cast<double>();
    
    return new MenuItem(name, price);
}
