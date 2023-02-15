//
//  Object.hpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-12.
//

#ifndef Object_h
#define Object_h

#include <map>
#include <set>
#include <string>
#include <vector>

#include "Datatype.hpp"

namespace DB
{

/**
 * @brief Represents a row of a database table/view.
 */
class Object
{
    friend class Handle;
private:
    /**
     * @brief Gets the name of the table.
     *
     * @return table name
     */
    virtual const std::string& table() const = 0;
    
    /**
     * @brief Gets the columns of the table in the correct order.
     *
     * @return table columns in the correct order
     */
    virtual const std::vector<std::string>& columns() const = 0;
    
    /**
     * @brief Gets the primary key(s) of the table.
     *
     * @return table primary keys
     */
    virtual const std::set<std::string>& keys() const = 0;
    
    /**
     * @brief Does the table have an autogenerated INTEGER PRIMARY KEY.
     *
     * @return true if the table has an autogenerated key, false otherwise
     */
    virtual bool isAutoGeneratedKey() const = 0;
    
    /**
     * @brief Gets a map representation of this object.
     *
     * The map should have an entry for each column of the table with the value
     * set to the value of the corresponding member of the object.
     */
    virtual std::map<std::string, Datatype> toMap() const = 0;
    
    /**
     * @brief Gets a new object created from a map representation.
     *
     * The map should be one previously created by toMap().
     *
     * @param dbObjectMap map representation of the object to create
     *
     * @return new object with values initialized according to the map
     */
    virtual Object* fromMap(const std::map<std::string, Datatype>& dbObjectMap) const = 0;
};

}

#endif /* Object_h */
