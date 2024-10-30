#include <iostream>
#include <cstring> 
#include "libraries/Record/Record.hpp"
#include "libraries/Block/Block.hpp"
using namespace std;
int main(){
    Record::Record records[10] = {
        Record::Record(1, "Title 1", 2020, "Author A", 100, "2024-01-01 12:00:00", "Snippet 1"),
        Record::Record(2, "Title 2", 2019, "Author B", 150, "2024-02-01 12:00:00", "Snippet 2"),
        Record::Record(3, "Title 3", 2018, "Author C", 200, "2024-03-01 12:00:00", "Snippet 3"),
        Record::Record(4, "Title 4", 2017, "Author D", 250, "2024-04-01 12:00:00", "Snippet 4"),
        Record::Record(5, "Title 5", 2021, "Author E", 300, "2024-05-01 12:00:00", "Snippet 5"),
        Record::Record(6, "Title 6", 2016, "Author F", 350, "2024-06-01 12:00:00", "Snippet 6"),
        Record::Record(7, "Title 7", 2022, "Author G", 400, "2024-07-01 12:00:00", "Snippet 7"),
        Record::Record(8, "Title 8", 2020, "Author H", 450, "2024-08-01 12:00:00", "Snippet 8"),
        Record::Record(9, "Title 9", 2021, "Author I", 500, "2024-09-01 12:00:00", "Snippet 9"),
        Record::Record(10, "Title 10", 2023, "Author J", 550, "2024-10-01 12:00:00", "Snippet 10")
    };

    /*Record::Record r(1, "Title 1", 2020, "Author A", 100, "2024-01-01 12:00:00", "Snippet 1");

    char* serializedRecord = r.toString();  // Supondo que toString retorne um char*
    if (serializedRecord) {
        r.display();
        size_t totalSize = sizeof(unsigned short) * 7 + sizeof(serializedRecord); // Adapte para o tamanho do offset e bytes totais
        cout << "Total size of serialized record: " << totalSize << "\n";

        cout<<"t: "<<strlen(serializedRecord)<<" so: "<<sizeof(serializedRecord)<<"\n";
        unsigned short* offsets = reinterpret_cast<unsigned short*>(serializedRecord);
        for (int i = 0; i < 7; ++i) {
            std::cout << "Offset[" << i << "]: " << offsets[i] << "\n";
        }
        r.toObject(serializedRecord);
        r.display();
        free(serializedRecord);  // Libere a memória se toString retornar char* alocado dinamicamente
    }*/
    Block::Block b(0, 0);

    for(int i=10; i>0; i--){
        if(b.able) b.addRecord(records[i-1]);
    }

    b.deserializedBlock();
    cout<<"Id: "<<b.id<<" fs: "<<b.freeSize<<" co: "<<b.currentOffset<<"\n";
    for(int i=0; i<b.record_counter; i++){
        b.records[i].display();
    }

    
    return 1;
}
