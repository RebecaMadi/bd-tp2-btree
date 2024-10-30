#include "Block.hpp"
#include <cstring> // Para memcpy
#include <cstdlib> // Para malloc
#include <iostream>

namespace Block {

Block::Block(unsigned int id, unsigned short record_counter) 
    : id(id), record_counter(record_counter), currentOffset(0), freeSize(BLOCK_SIZE_T), able(1) {

    bytes_block = (char*) malloc(BLOCK_SIZE_T);
    memset(bytes_block, 0, BLOCK_SIZE_T);  
    records = new Record::Record[MAX_RECORD_COUNTER];  
}

void Block::addRecord(Record::Record rec) {
    int headerSize = sizeof(id);
    
    auto [serializedRecord, recordSize] = rec.toString();

    if (sizeof(recordSize) + recordSize > freeSize) {
        able = 0;
        std::cerr << "Espaço insuficiente no bloco.\n";
        free(serializedRecord);
        return;
    }

    if (record_counter == 0) {
        memcpy(bytes_block, &id, sizeof(id));
        currentOffset = headerSize;  
    }

    memcpy(bytes_block + currentOffset, &recordSize, sizeof(recordSize));
    currentOffset += sizeof(recordSize);

    memcpy(bytes_block + currentOffset, serializedRecord, recordSize);
    currentOffset += recordSize;

    record_counter++;
    freeSize = BLOCK_SIZE_T - currentOffset; 

    free(serializedRecord);
}

void Block::deserializedBlock() {
    int offset = 0;

    memcpy(&id, bytes_block + offset, sizeof(id));
    offset += sizeof(id);

    records = new Record::Record[record_counter];  

    for (int i = 0; i < record_counter; i++) {
        int recordSize;

        memcpy(&recordSize, bytes_block + offset, sizeof(recordSize));
        offset += sizeof(recordSize);

        Record::Record tempRecord;
        tempRecord.toObject(bytes_block + offset);
        
        records[i] = tempRecord;

        offset += recordSize;
    }
}

} 
