#ifdef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer {
private:
    Serializer();
    Serializer(const Serializer&);
    ~Serializer();
    Serializer& operator=(const Serializer&);

public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
}

#endif;