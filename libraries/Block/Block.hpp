#ifndef BLOCK_H
#define BLOCK_H

#define BLOCK_SIZE_T 8192
// 2¹³. Cabem no máximo 5 registros no bloco.

#define MAX_RECORD_COUNTER 5

#include "../Record/Record.hpp"
#include "../Utils/Utils.hpp"

namespace Block {

class Block {

    public:
        unsigned int id;
        unsigned short record_counter;
        Record::Record *records;
        
        Block(unsigned int id, unsigned short record_counter);

        void addRecord(Record::Record *rec);

};

}

#endif
