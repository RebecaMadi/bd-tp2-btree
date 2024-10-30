#include "Record.hpp"
#include <iostream>
#include <cstring> // Para strcpy
#include <cstdlib>  //realloc
#include <utility>

namespace Record {

Record::Record(int id, const char* title, unsigned short year, const char* authors, 
                   unsigned int citations, const char* lastUpdated, const char* snippet)
    : id(id), year(year), citations(citations) {

    strncpy(this->title, title, sizeof(this->title) - 1);
    this->title[sizeof(this->title) - 1] = '\0'; 

    strncpy(this->authors, authors, sizeof(this->authors) - 1);
    this->authors[sizeof(this->authors) - 1] = '\0'; 

    strncpy(this->lastUpdated, lastUpdated, sizeof(this->lastUpdated) - 1);
    this->lastUpdated[sizeof(this->lastUpdated) - 1] = '\0';

    strncpy(this->snippet, snippet, sizeof(this->snippet) - 1);
    this->snippet[sizeof(this->snippet) - 1] = '\0';
}

void Record::display(){
    std::cout << "ID: " << id << "\n"
              << "Titulo: " << title << "\n"
              << "Ano: " << year << "\n"
              << "Autores: " << authors << "\n"
              << "Citações: " << citations << "\n"
              << "Ultima atualização: " << lastUpdated << "\n"
              << "Snippet: " << snippet << "\n";
}

void Record::setObject(int id, const char* title, unsigned short year, const char* authors, 
                   unsigned int citations, const char* lastUpdated, const char* snippet) {
    this->id = id;
    this->year = year;
    this->citations = citations;

    strncpy(this->title, title, sizeof(this->title) - 1);
    this->title[sizeof(this->title) - 1] = '\0'; 

    strncpy(this->authors, authors, sizeof(this->authors) - 1);
    this->authors[sizeof(this->authors) - 1] = '\0'; 

    strncpy(this->lastUpdated, lastUpdated, sizeof(this->lastUpdated) - 1);
    this->lastUpdated[sizeof(this->lastUpdated) - 1] = '\0';

    strncpy(this->snippet, snippet, sizeof(this->snippet) - 1);
    this->snippet[sizeof(this->snippet) - 1] = '\0';
}

std::pair<char*, int> Record::toString() {
    size_t currentSize = 0;
    currentSize += sizeof(this->id); 
    currentSize += strlen(this->title) + 1; 
    currentSize += sizeof(this->year); 
    currentSize += strlen(this->authors) + 1; 
    currentSize += sizeof(this->citations); 
    currentSize += strlen(this->lastUpdated) + 1; 
    currentSize += strlen(this->snippet) + 1; 

    // Aloca espaço suficiente para o registro completo
    char* bytes_record = (char*) malloc(currentSize);
    size_t offset = 0;

    unsigned short offsets[7];
    offsets[0] = offset; 
    memcpy(bytes_record + offset, &id, sizeof(id));
    offset += sizeof(id);

    offsets[1] = offset; 
    memcpy(bytes_record + offset, title, strlen(title) + 1);
    offset += strlen(title) + 1;

    offsets[2] = offset;
    memcpy(bytes_record + offset, &year, sizeof(year));
    offset += sizeof(year);

    offsets[3] = offset; 
    memcpy(bytes_record + offset, authors, strlen(authors) + 1);
    offset += strlen(authors) + 1;

    offsets[4] = offset; 
    memcpy(bytes_record + offset, &citations, sizeof(citations));
    offset += sizeof(citations);

    offsets[5] = offset;
    memcpy(bytes_record + offset, lastUpdated, strlen(lastUpdated) + 1);
    offset += strlen(lastUpdated) + 1;

    offsets[6] = offset;
    memcpy(bytes_record + offset, snippet, strlen(snippet) + 1);

    char* result = (char*)malloc(currentSize + sizeof(offsets));
    memcpy(result, offsets, sizeof(offsets)); 
    memcpy(result + sizeof(offsets), bytes_record, currentSize); 

    free(bytes_record); 
    return {result, currentSize + sizeof(offsets)};
}


void Record::toObject(char* serializedRecord) {
    if (serializedRecord == nullptr) return;

    unsigned short* offsets = (unsigned short*)serializedRecord;

    int idOffset = offsets[0];
    int titleOffset = offsets[1];
    int yearOffset = offsets[2];
    int authorsOffset = offsets[3];
    int citationsOffset = offsets[4];
    int lastUpdatedOffset = offsets[5];
    int snippetOffset = offsets[6];

    memcpy(&id, serializedRecord + sizeof(unsigned short) * 7 + idOffset, sizeof(id));
    memcpy(&year, serializedRecord + sizeof(unsigned short) * 7 + yearOffset, sizeof(year));
    memcpy(&citations, serializedRecord + sizeof(unsigned short) * 7 + citationsOffset, sizeof(citations));

    setObject(
        id,
        serializedRecord + sizeof(unsigned short) * 7 + titleOffset,
        year,
        serializedRecord + sizeof(unsigned short) * 7 + authorsOffset,
        citations,
        serializedRecord + sizeof(unsigned short) * 7 + lastUpdatedOffset,
        serializedRecord + sizeof(unsigned short) * 7 + snippetOffset
    );
}

}