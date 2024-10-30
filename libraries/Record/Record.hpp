#ifndef RECORD_H
#define RECORD_H
#include <utility>
namespace Record {
class Record {

    public:

        int id;                     // Código identificador do artigo. 4 bytes
        char title[300];           // Título do artigo 300 bytes.
        unsigned short year;                  // Ano de publicação. 4 bytes.
        char authors[150];         // Lista dos autores 150 bytes
        unsigned int citations;             // Número de citações. 4 bytes
        char lastUpdated[19];      // Data e hora da última atualização (formato YYYY-MM-DD HH:MM:SS). 19 bytes
        char snippet[1024];        // Resumo textual do artigo ( +1 para o terminador nulo). 1024 bytes

        // 1505 bytes. 1,48kb no máximo

        Record() : id(0), year(0), citations(0) {
                title[0] = '\0'; 
                authors[0] = '\0';
                lastUpdated[0] = '\0';
                snippet[0] = '\0';
        }

        Record(int id, const char* title, unsigned short year, const char* authors, 
                unsigned int citations, const char* lastUpdated, const char* snippet);

        void display();
        std::pair<char*, int> toString();
        void toObject(char* bytes);
        void setObject(int id, const char* title, unsigned short year, const char* authors, 
                unsigned int citations, const char* lastUpdated, const char* snippet);
};

}
#endif 
