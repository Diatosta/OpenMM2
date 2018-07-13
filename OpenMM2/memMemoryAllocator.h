#pragma once

class memMemoryAllocator
{
public:
    memMemoryAllocator* Prev;
    void *HeapData;
    int TotalSize;
    int Alignment;
    int Locked;
    bool field_14;
    bool field_15;
    bool CheckAlloc;
    bool field_17;
    int Array1[32];
    int Array2[16];
    float fieldD8;

    memMemoryAllocator();
    ~memMemoryAllocator();

    void Init(void * heapData, uint32_t heapSize, BOOL a3, BOOL checkalloc);
    void Kill(void);

    static void DisplayUsed(char const* status);

    declstatic(memMemoryAllocator*, First);
    declstatic(memMemoryAllocator*, Current);
};

declvar(void(*)(char const *), datDisplayUsed);

check_size(memMemoryAllocator, 0xDC);