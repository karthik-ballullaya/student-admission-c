#include <stdint.h>
#include "appconst.h"
#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

struct _program_ {
  char         programName[PROGRAM_NAME_LEN];
  uint32_t      programCode;
  uint16_t     maxSeats;
  uint16_t     filledSeats;
};

typedef struct _program_ Program;

struct _program_list_ {
  Program      List[MAX_PROGRAM_LEN];
  int8_t       numberOfPrograms;
};

typedef struct _program_list_ ProgramList;

ProgramList           initialize_program_list();
int8_t                add_new_program(ProgramList *, char *, uint32_t, uint16_t);
static Program        create_program(char *, uint32_t, uint16_t);
Program *             get_program_details(ProgramList *, const char *);
uint16_t              get_filled_seat_count(const ProgramList *, const char *);


#endif