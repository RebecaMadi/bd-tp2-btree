#include "Block.hpp"
#include "../Record/Record.hpp"
#include "../Utils/Utils.hpp"

namespace Block {

Block::Block(unsigned int id, unsigned short record_counter) {
    this->id = id;
    this->record_counter = record_counter;
    this->records = new Record::Record[MAX_RECORD_COUNTER];
}

void Block::addRecord(Record::Record *rec) {
    if (this->record_counter < MAX_RECORD_COUNTER) {
        Utils::MinHeap heap(&this->records, MAX_RECORD_COUNTER, this->record_counter, 0);

        heap.insert(rec);

        this->id = this->records[0].id;

        heap.~MinHeap();
        
        this->record_counter++;
    }
}

}
