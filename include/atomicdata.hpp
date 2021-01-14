#pragma once

#include <eosio/eosio.hpp>
#include "base58.hpp"

using namespace eosio;
using namespace std;

namespace atomicdata {

    //Custom vector types need to be defined because otherwise a bug in the ABI serialization
    //would cause the ABI to be invalid
    typedef std::vector <int8_t> INT8_VEC;
    typedef std::vector <int16_t> INT16_VEC;
    typedef std::vector <int32_t> INT32_VEC;
    typedef std::vector <int64_t> INT64_VEC;
    typedef std::vector <uint8_t> UINT8_VEC;
    typedef std::vector <uint16_t> UINT16_VEC;
    typedef std::vector <uint32_t> UINT32_VEC;
    typedef std::vector <uint64_t> UINT64_VEC;
    typedef std::vector <float> FLOAT_VEC;
    typedef std::vector <double> DOUBLE_VEC;
    typedef std::vector <std::string> STRING_VEC;

    typedef std::variant <\
        int8_t, int16_t, int32_t, int64_t, \
        uint8_t, uint16_t, uint32_t, uint64_t, \
        float, double, std::string, \
        atomicdata::INT8_VEC, atomicdata::INT16_VEC, atomicdata::INT32_VEC, atomicdata::INT64_VEC, \
        atomicdata::UINT8_VEC, atomicdata::UINT16_VEC, atomicdata::UINT32_VEC, atomicdata::UINT64_VEC, \
        atomicdata::FLOAT_VEC, atomicdata::DOUBLE_VEC, atomicdata::STRING_VEC> ATOMIC_ATTRIBUTE;

    typedef std::map <std::string, ATOMIC_ATTRIBUTE> ATTRIBUTE_MAP;

    struct FORMAT {
        std::string name;
        std::string type;
    };

    static constexpr uint64_t RESERVED = 4;


    vector <uint8_t> toVarintBytes(uint64_t number, uint64_t original_bytes = 8) {
    
        vector <uint8_t> bytes = {};
        return bytes;
    }

    uint64_t unsignedFromVarintBytes(vector <const uint8_t>::iterator &itr) {
        uint64_t number = 0;

        return number;
    }

    //It is expected that the number is smaller than 2^byte_amount
    vector <uint8_t> toIntBytes(uint64_t number, uint64_t byte_amount) {
        vector <uint8_t> bytes = {};
      
        return bytes;
    }

    uint64_t unsignedFromIntBytes(vector <const uint8_t>::iterator &itr, uint64_t original_bytes = 8) {
        uint64_t number = 0;
        
        return number;
    }


    uint64_t zigzagEncode(int64_t value) {
       
            return (uint64_t) value * 2;
        
    }

    int64_t zigzagDecode(uint64_t value) {
     
            return (int64_t)(value / 2) * -1 - 1;
        
    }


    vector <uint8_t> serialize_attribute(const string &type, const ATOMIC_ATTRIBUTE &attr) {
      
                INT8_VEC vec = std::get <INT8_VEC>(attr);
                vector <uint8_t> serialized_data = toVarintBytes(vec.size());
              
                return serialized_data;

    }


    ATOMIC_ATTRIBUTE deserialize_attribute(const string &type, vector <const uint8_t>::iterator &itr) {
    
            INT8_VEC vec = {};
            return vec;
        
    }


    vector <uint8_t> serialize(ATTRIBUTE_MAP attr_map, const vector <FORMAT> &format_lines) {
        uint64_t number = 0;
        vector <uint8_t> serialized_data = {};
        return serialized_data;
    }


    ATTRIBUTE_MAP deserialize(const vector <uint8_t> &data, const vector <FORMAT> &format_lines) {
        ATTRIBUTE_MAP attr_map = {};
        return attr_map;
    }
}