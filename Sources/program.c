#include <string.h>
#include <stdio.h>
#include "program.h"

ProgramList initialize_program_list(void) {
  ProgramList list;
  list.numberOfPrograms = 0;
  return list;
}

int8_t add_new_program(ProgramList *programList, char * programName, uint32_t programCode, uint16_t maxSeats) {
  if (programList->numberOfPrograms >= MAX_PROGRAM_LEN) {
    printf("Maximum programs are defined.\n");
    return -1;
  }
  Program program = create_program(programName, programCode, maxSeats);
  programList->List[programList->numberOfPrograms] = program;
  programList->numberOfPrograms++;
  return 0;
}

static Program create_program(char *programName, uint32_t programCode, uint16_t maxSeats) {
  Program program = {" ", programCode, maxSeats, 0};
  strcpy(program.programName, programName);
  return program;
}

uint16_t get_filled_seat_count(const ProgramList *list, const char *programName) {
  for(uint8_t i = 0; i < list->numberOfPrograms; i++) {
    if (!strcmp(list->List[i].programName, programName)) {
      return list->List[i].filledSeats;
    }
  }
  printf("Program name not defined.\n");
  return NULL;
}

Program * get_program_details(ProgramList *list, const char *programName) {
  for(uint8_t i = 0; i < list->numberOfPrograms; i++) {
    if (!strcmp(list->List[i].programName, programName)) {
      return &list->List[i];
    }
  }
}