//
//  OP.cpp
//  SQLiteDataAccessLayer
//
//  Created by Julian Koksal on 2023-02-15.
//

#include "OP.hpp"

using namespace DB;

const std::string DB::opStr(OP op)
{
    switch (op)
    {
        case OP::EQ:
            return "=";
        case OP::NEQ:
            return "!=";
        case OP::GT:
            return ">";
        case OP::GTE:
            return ">=";
        case OP::LT:
            return "<";
        case OP::LTE:
            return "<=";
        case OP::IN:
            return "IN";
        case OP::CONTAINS:
            return "LIKE";
        case OP::STARTSWITH:
            return "LIKE";
        case OP::ENDSWITH:
            return "LIKE";
    }
}
