#include <eosio/eosio.hpp>
#include <algorithm>

#include <atomicdata.hpp>

using namespace eosio;
using namespace std;
using namespace atomicdata;

/*
This function checks if a vector of FORMAT structs, used to describe a format, is valid

For a format to be valid, three things are checked:
1. The type attribute has to be a valid type. Valid types are:
    int8 / int16 / int32 / int64
    uint8 / uint16 / uint32 / uint64
    fixed8 / fixed16 / fixed32 / fixed64
    float / double / string / image / ipfs / bool / byte

    or any valid type followed by [] to describe a vector
    nested vectors (e.g. uint64[][]) are not allowed

2. Names need to be unique

3. A format line {"name": "name", "type": "string"} needs to be defined
   This could obviously also be done automatically, but we believe that this could lead to confusion


Note: This could all be done a lot cleaner by using regex or similar libraries
      However, using them would bloat up the contract size significantly.
*/
void check_format(vector <FORMAT> lines) {

}