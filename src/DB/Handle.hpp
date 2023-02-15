//
//  Handle.hpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-12.
//

#ifndef Handle_hpp
#define Handle_hpp

#include <algorithm>
#include <cstdint>
#include <map>
#include <set>
#include <string>
#include <typeinfo>
#include <vector>

#include <sqlite3.h>

#include "Condition.hpp"
#include "Object.hpp"
#include "OP.hpp"

namespace DB
{

class Handle
{
public:
    Handle(const std::string fileName);
    
    Handle(const Handle& other) = delete;
    
    ~Handle();
    
    Handle& operator=(const Handle& other) = delete;
    
    template<class T, class = std::enable_if<std::is_base_of<Object, T>::value>>
    std::vector<T> select(const T& dbObject,
                          const std::vector<Condition>& conditions = {},
                          const std::string& orderBy = "",
                          const std::set<std::string>& columns = {})
    {
        const std::vector<Object*> helperResult = selectHelper(dbObject,
                                                               conditions,
                                                               orderBy,
                                                               columns);
        std::vector<T> result(helperResult.size());
        std::transform(helperResult.cbegin(), helperResult.cend(),
                       result.begin(), [](Object* o){
            return *((T*)o);
        });
        return result;
    }
    
    std::int64_t insert(const Object& dbObject) const;
    
    void update(const Object& dbObject) const;
    
    void updateWhere(const Object& dbObject,
                     const std::vector<Condition>& conditions,
                     const std::set<std::string>& columns) const;

    void destroy(const Object& dbObject) const;

    void destroyWhere(const Object& dbObject,
                      const std::vector<Condition>& conditions) const;
    
private:
    sqlite3* db;
    
    std::vector<Object*> selectHelper(const Object& dbObject,
                                      const std::vector<Condition>& conditions,
                                      const std::string &orderBy,
                                      const std::set<std::string>& columns) const;
    
    sqlite3_stmt* prepareStatement(const std::string& query) const;
    
    void bindStatementColumns(sqlite3_stmt* statement, const Object& dbObject,
                              const std::vector<std::string>& columns,
                              int& index, const bool isInsert = false) const;
    
    void bindStatementConditions(sqlite3_stmt* statement,
                                 const std::vector<Condition>& conditions,
                                 int& index) const;
    
    void finalizeStatement(sqlite3_stmt *statement,
                           const std::string& errorMessage) const;
    
    void openDB(const std::string fileName);
    
    void closeDB();
    
    static std::string generateWhereClauseFromConditions(const std::vector<Condition>& conditions);
    
    static std::string generateWhereClauseFromKeys(const std::vector<std::string>& keys);
};

}

#endif /* Handle_hpp */
