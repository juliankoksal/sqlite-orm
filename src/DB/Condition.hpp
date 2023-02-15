//
//  Condition.hpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-12.
//

#ifndef Condition_hpp
#define Condition_hpp

#include <cstdint>
#include <string>
#include <vector>

#include "Datatype.hpp"
#include "OP.hpp"

namespace DB
{

/**
 * @brief Represents a SQL query condition.
 */
class Condition
{
    friend class Handle;
public:
    /**
     * @brief Constructor.
     *
     * @param field column name
     * @param op operator
     * @param value value
     */
    Condition(const std::string& field, const OP op, const std::int64_t value);
    
    /**
     * @brief Constructor.
     *
     * @param field column name
     * @param op operator
     * @param value value
     */
    Condition(const std::string& field, const OP op, const double value);
    
    /**
     * @brief Constructor.
     *
     * @param field column name
     * @param op operator
     * @param value value
     */
    Condition(const std::string& field, const OP op, const std::string& value);
    
    /**
     * @brief Constructor.
     *
     * @param field column name
     * @param op operator
     * @param value value
     */
    Condition(const std::string& field, const OP op,
              const std::vector<std::int64_t>& value);
    
    /**
     * @brief Constructor.
     *
     * @param field column name
     * @param op operator
     * @param value value
     */
    Condition(const std::string& field, const OP op,
              const std::vector<std::string>& value);
    
private:
    /**
     * @brief Column name.
     */
    std::string field;
    
    /**
     * @brief Operator.
     */
    OP op;
    
    /**
     * @brief Value.
     */
    Datatype value;
    
};

}

#endif /* Condition_hpp */
