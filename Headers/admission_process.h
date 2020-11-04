#include <stdint.h>
#include "student.h"
#include "program.h"

#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

void                allocate_seat(Program *, Application *);
static int8_t       check_condition(const Program *program, const Application *application);
static uint32_t     generate_reg_number(const Program *);
void                withdraw_application(const ProgramList *, Application *);

#endif