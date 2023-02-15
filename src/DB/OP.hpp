//
//  OP.hpp
//  SQLiteDataAccessLayer
//
//  Created by Julian Koksal on 2023-02-15.
//

#ifndef OP_hpp
#define OP_hpp

#include <string>

namespace DB
{

/**
 * @brief Represents a comparison operator for query conditions.
 */
enum class OP : const char
{
    EQ,
    NEQ,
    GT,
    GTE,
    LT,
    LTE,
    IN,
    CONTAINS,
    STARTSWITH,
    ENDSWITH
};

/**
 * @brief Gets string representation of the operator as an SQLite operator.
 *
 * @param op operator
 *
 * @return string representation of operator as an SQLite operator
 */
const std::string opStr(OP op);

}

#endif /* OP_hpp */
