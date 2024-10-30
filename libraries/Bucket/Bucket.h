#ifndef BUCKET_H
#define BUCKET_H

#include "../Block/Block.hpp"
#include <cstring> 
#define MAX_BLOCK_COUNTER 4000

class Bucket{
    public:
        std::string hash_key;
        //unsigned int id_init_block;
        Block::Block blocks[MAX_BLOCK_COUNTER];
        std::unsigned short block_counter;

};
#endif