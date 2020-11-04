#include <stdio.h>
#include <assert.h>
#include "student.h"
#include "program.h"
#include "admission_process.h"

void test_program_methods() {
  /* *
   * Test initialization, add_new_program methods
   * Implicitly test create_program method
   * */
  ProgramList p = initialize_program_list();
  ProgramList *programList = &p;
  assert(add_new_program(programList, "BDA", 2010460, 40) == 0);
  assert(programList->numberOfPrograms == 1);
  /* *
   * Test get_filled_seat_count method
   * */
  programList->List[0].filledSeats = 20;  // updating the filled seats of bda to 20
  assert(get_filled_seat_count(programList, "BDA") == 20);
  assert(get_filled_seat_count(programList, "ML") == NULL);
  /* *
   * Test get_program_details method
   * */
  Program *BDAProgram = get_program_details(programList, "BDA");
  BDAProgram->filledSeats = 40;
  assert(get_filled_seat_count(programList, "BDA") == 40);
}

void test_student_methods() {
  /* *
   * Test initialization, add_new_application methods
   * Implicitly test create_new_application method
   * */
  ApplicantList a = initialize_applicant_list();
  ApplicantList *applicantList = &a;
  ProgramList p = initialize_program_list();
  ProgramList *programList = &p;
  add_new_program(programList, "BDA", 2010460, 40);
  assert(add_new_application(applicantList, "Name0", "BDA", "test@test.com", 100, 6.0) == 0);
  assert(add_new_application(applicantList, "Name1", "BDA", "test@test.com", 100, 4.9) == 0);
  assert(applicantList->List[0]._application_number_ == 0);
  applicantList->numberOfApplicants = MAX_APPLICATION_LEN;
  assert(add_new_application(applicantList, "Name", "BDA", "test@test.com", 100, 6.0) == -1);
  applicantList->numberOfApplicants = 2;
  /* *
   * Test update_application_status method
   * */
  Application *application_0 = &applicantList->List[0];
  update_application_status(application_0, ALLOTTED);
  assert(applicantList->List[0].admissionStatus == ALLOTTED);
  /* *
   * Test update_application_registration_number method
   * */
  update_application_registration_number(application_0, 20104601);
  assert(applicantList->List[0].regNumber == 20104601);
  /* *
   * Test print_application_details method
   * */
  print_application_details(applicantList, 0);
  /* *
   * Test get_total_applicants method
   * */
  assert(get_total_applicants(applicantList) == 2);
}

void test_admission_process_methods() {
  /* *
   * Test allocate_seat methods
   * Implicitly test check_condition and generate_reg_number
   * */
  ApplicantList a = initialize_applicant_list();
  ApplicantList *applicantList = &a;
  ProgramList p = initialize_program_list();
  ProgramList *programList = &p;
  const uint32_t programCode = 2010460;
  add_new_program(programList, "BDA", programCode, 40);
  Program *BDAProgram = get_program_details(programList, "BDA");
  assert(add_new_application(applicantList, "Name0", "BDA", "test@test.com", 100, 6.0) == 0);
  assert(add_new_application(applicantList, "Name1", "BDA", "test@test.com", 100, 4.9) == 0);
  Application *application_0 = &applicantList->List[0];
  Application *application_1 = &applicantList->List[1];
  allocate_seat(BDAProgram, application_0);
  assert(application_0->admissionStatus == ALLOTTED && application_0->regNumber == 201046001);
  allocate_seat(BDAProgram, application_1);
  assert(application_1->admissionStatus == REJECTED && application_1->regNumber == NULL);
  assert(BDAProgram->filledSeats == 1);
  /* *
   * Test withdraw_application methods
   * */
  withdraw_application(programList, application_0);
  assert(application_0->admissionStatus == WITHDRAWN);
  assert(BDAProgram->filledSeats == 0);
}

int main() {
  printf("********************Testing Program methods********************\n");
  test_program_methods();
  printf("********************Testing Student methods********************\n");
  test_student_methods();
  printf("***************Testing Admission Process methods***************\n");
  test_admission_process_methods();
  return 0;
}