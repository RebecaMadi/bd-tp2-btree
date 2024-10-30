#ifndef BLOCK_H
#define BLOCK_H

#define BLOCK_SIZE_T 4096

#define MAX_RECORD_COUNTER 5

#include "../Record/Record.hpp"
#include "../Utils/Utils.hpp"

namespace Block {

class Block {

    public:
        unsigned int id;
        unsigned short record_counter;
        char* bytes_block;
        int currentOffset;
        int freeSize;
        int able;
        Record::Record *records;
        
        Block(unsigned int id, unsigned short record_counter);

        void addRecord(Record::Record rec);
        void deserializedBlock();
};

}

#endif
