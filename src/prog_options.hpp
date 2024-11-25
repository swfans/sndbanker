#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <cstdio>

extern int verbose;

#define LogMsg(format,args...) std::fprintf(stdout,format "\n", ## args)
#define LogDbg(format,args...) if (verbose) std::fprintf(stdout,format "\n", ## args)
#define LogErr(format,args...) std::fprintf(stderr,format "\n", ## args)

enum {
    ERR_OK          =  0,
    ERR_CANT_OPEN   = -1, // fopen problem
    ERR_BAD_FILE    = -2, // incorrect file format
    ERR_NO_MEMORY   = -3, // malloc error
    ERR_FILE_READ   = -4, // fget/fread/fseek error
    ERR_FILE_WRITE  = -5, // fput/fwrite error
    ERR_LIMIT_EXCEED= -6, // static limit exceeded
};

#define SAMPLE_FNAME_LEN 18

class SoundData {
public:
    /** Name of the sound file the sample comes from. */
    std::string fname;
    std::vector<unsigned char> data;
    /** Unknown1. */
    long unkn1;
    /** Unknown3. */
    long sfxid;
};

#pragma pack(1)

class SoundBankSample {
public:
    /** Name of the sound file the sample comes from. */
    char fname[SAMPLE_FNAME_LEN];
    /** Offset of the sample data in DAT file. */
    uint32_t data;
    /** Unknown1. */
    int32_t unkn1;
    /** Size of the sample file. */
    uint32_t length;
    /** SFX ID. */
    uint8_t sfxid;
    /** Unknown3. */
    uint8_t field_1F;
};

class SoundBankHead {
public:
  uint8_t field_0[14];
  uint32_t field_E;
};

class SoundBankEntry {
public:
    /** Offset of the first catalog entry in DAT file. */
    uint32_t field_0;
    /** Offset to the sample data area. */
    uint32_t field_4;
    /** Size of the sample catalog in DAT file. */
    uint32_t field_8;
    /** Offset of the first catalog entry in DAT file. */
    uint32_t field_C;
};

class SoundBankFoot {
public:
    /** Block 0x00 filled */
    char unkn7[16];
    /** Offset of the first catalog entry in DAT file. */
    uint32_t start3;
    /** Size of the catalog in DAT file. */
    uint32_t catsize3;
    char unkn8[48];
    /** Offset of the footer in DAT file. */
    uint32_t footpos;
};

#pragma pack()

class SoundFile {
public:
    SoundFile(const std::string &nname, const int nsfxid):
        fname(nname),sfxid(nsfxid) { };
    /** Name of the source sound sample file */
    std::string fname;
    int sfxid;
};

/** A class closing non-global command line parameters */
class ProgramOptions {
public:
    ProgramOptions()
    {
        clear();
    }
    void clear()
    {
        inp.clear();
        fname_lst.clear();
        fname_out.clear();
    }
    std::vector<SoundFile> inp;
    std::string fname_lst;
    std::string fname_out;
};

