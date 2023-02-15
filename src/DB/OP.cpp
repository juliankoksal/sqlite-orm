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
    using enum OP;
    switch (op)
    {
        case EQ:
            return "=";
        case NEQ:
            return "!=";
        case GT:
            return ">";
        case GTE:
            return ">=";
        case LT:
            return "<";
        case LTE:
            return "<=";
        case IN:
            return "IN";
        case CONTAINS:
            return "LIKE";
        case STARTSWITH:
            return "LIKE";
        case ENDSWITH:
            return "LIKE";
    }
}
