#ifndef __binary_chunk_h__
#define __binary_chunk_h__

#include "unidef.h"

#define LUA_SIGNATURE       "\x1bLua"
#define LUAC_VERSION        0x53
#define LUAC_FORMAT         0
#define LUAC_DATA           "\x19\x93\r\n\x1a\n"
#define CINT_SIZE           4
#define CSIZET_SIZE         8
#define INSTRUCTION_SIZE    4
#define LUA_INTEGER_SIZE    8
#define LUA_NUMBER_SIZE     8
#define LUAC_INT            0x5678
#define LUAC_NUM            370.5

typedef struct _header {
    
    byte    signature[4];
    byte    version;
    byte    format;
    byte    luacData[6];
    byte    cintSize;
    byte    sizetSize;
    byte    instructionSize;
    byte    luaIntegerSize;
    byte    luaNumberSize;
    int64   luacInt;
    float64 luacNum;

} Header;

typedef struct _prototype {
    
} Prototype;

typedef struct _binaryChunk {

    Header      *header;
    byte        sizeUpvalues;
    Prototype   *mainFunc;
    
} BinaryChunk;

#endif /* __binary_chunk_h__ */