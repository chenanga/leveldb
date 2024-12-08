#include <assert.h>
#include <iostream>
#include "leveldb/db.h"

int main()
{
    leveldb::DB*     db = NULL;
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "../data/test.db", &db);
    std::cout << status.ToString() << std::endl;

    std::string key = "name";
#ifdef WRITE_MODE
    std::string value = "Jeff Dean";
    status            = db->Put(leveldb::WriteOptions(), key, value);
    std::cout << "write key:" << key << " value:" << value << " "
              << status.ToString() << std::endl;
#else
    std::string db_value;
    status = db->Get(leveldb::ReadOptions(), key, &db_value);
    std::cout << "read key:" << key << " value:" << db_value << " "
              << status.ToString() << std::endl;
#endif

    return 0;
}