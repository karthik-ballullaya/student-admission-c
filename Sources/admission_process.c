#include "admission_process.h"
#include "appconst.h"

static int8_t check_condition(const Program *program, const Application *application) {
  if ((application->UGGrade < UG_GRADE_CUT_OFF) || (program->filledSeats >= program->maxSeats)) {
    return 0;
  }
  return 1;
}

void allocate_seat(Program *program, Application *application) {
  if (check_condition(program, application)) {
    program->filledSeats++;
    program->admissionTaken++;
    const uint32_t regNumber = generate_reg_number(program);
    update_application_registration_number(application, regNumber);
    update_application_status(application, ALLOTTED);
  } else {
    update_application_status(application, REJECTED);
  }
}

static uint32_t generate_reg_number(const Program *program) {
  return (uint32_t) (program->programCode * REG_NUMBER_OFFSET + program->admissionTaken);
}

void withdraw_application(const ProgramList *programList, Application *application) {
  if (application->admissionStatus == ALLOTTED) {
    Program *program = get_program_details(programList, application->program);
    program->filledSeats--;
  }
  application->admissionStatus = WITHDRAWN;
}