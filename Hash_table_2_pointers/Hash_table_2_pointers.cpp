#include <iostream>
#include <cstring>
#include <cstdint>

class HashTable{
 private:
  enum State{EMPTY, OCCUPIED, DELETED};  // состояние ячейки

  struct Slot{
    char* str;  // ключ
    State state;
  };

  static const int kM = 10007;  // размер таблицы
  static const int kQ = 9973;   // Q < M 
  static const int kBase = 31;  // Основание полиномиального кэша

  Slot* table_;

  // Первая полиномиальная хэш функуия
  unsigned int PolyH1(const char* s) const {
    uint64_t h = 0;

    for (int i = 0; s[i]; ++i) {
      h = h * kBase + static_cast<unsigned char>(s[i]);
    }
    return static_cast<unsigned int>(h % kM);
  }

  // Вторая хэш функция. Даёт шаг в диапазоне от 1 до М - 1
  unsigned int StepH2(const char* s) const {
    uint64_t h = 0;

    for (int i = 0; s[i]; ++i) {
      h = h * kBase + static_cast<unsigned char>(s[i]);
    }
    return static_cast<unsigned int>(kQ - (h % kQ));
  }

  // Индекс i пробы
  unsigned int Probe(const char* s, unsigned int i) {
    return (PolyH1(s) + i * StepH2(s)) % kM;
  }

 public:
  HashTable() {
    table_ = new Slot[kM];
    for (int i = 0; i < kM; ++i) {
      table_[i].str = nullptr;
      table_[i].state = EMPTY;
    }
  }

  ~HashTable() {
    for (int i = 0; i < kM; ++i) {
      delete[] table_[i].str;
    }
    delete[] table_;
  }

  void Push(const char* s) {
    int first_deleted = -1;
    
    for (unsigned int i = 0; i < kM; ++i) {
      unsigned int index = Probe(s, i);
      if (table_[index].state == OCCUPIED) {
        if (strcmp(table_[index].str, s) == 0) { // Дубликат
          return;
        }
      } else if (table_[index].state == DELETED) {
        if (first_deleted < 0) {
          first_deleted = static_cast<int>(index);  // Кандидат на вставку
        }
      } else {  // Empty
        int target = (first_deleted >= 0) ? first_deleted : static_cast<int>(index);
        size_t len = strlen(s);
        table_[target].str = new char[len + 1];
        memcpy(table_[target].str, s, len + 1);
        table_[target].state = OCCUPIED;
        return;
      }
    }
    // Тут ничего, если таблица не переполнена
  }

  bool Search(const char* s) {
    for (unsigned int i = 0; i < kM; ++i) {
      unsigned int index = Probe(s, i);
      if (table_[index].state == EMPTY) {
        return false;
      }
      if (table_[index].state == OCCUPIED) {
        if (strcmp(table_[index].str, s) == 0) {
          return true;
        }
      }
    }
    return false;
  }

  bool Pop(const char* s) {
    for (unsigned int i = 0; i < kM; ++i) {
      unsigned int index = Probe(s, i);
      if (table_[index].state == EMPTY) {
        return false;
      }
      if (table_[index].state == OCCUPIED) {
        if (strcmp(table_[index].str, s) == 0) {
          delete[] table_[index].str;
          table_[index].str = nullptr;
          table_[index].state = DELETED;
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  HashTable ht;
  char command[20];
  char buffer[1000];

  for (int i = 0; i < n; ++i) {
    std::cin >> command >> buffer;
    if (strcmp(command, "push") == 0) {
      ht.Push(buffer);
    } else if (strcmp(command, "pop") == 0) {
      std::cout << (ht.Pop(buffer) ? "TRUE\n" : "FALSE\n");
    } else if (strcmp(command, "search") == 0) {
      std::cout << (ht.Search(buffer) ? "TRUE\n" : "FALSE\n");
    }
  }
  return 0;
}