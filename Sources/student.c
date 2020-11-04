#include <string.h>
#include <stdio.h>
#include "student.h"

ApplicantList initialize_applicant_list() {
  ApplicantList list;
  list.numberOfApplicants = 0;
  return list;
}

int8_t add_new_application(ApplicantList *list, const char *name, const char *program, const char *email, uint32_t entranceTestRank, float UGGrade) {
  if (list->numberOfApplicants >= MAX_APPLICATION_LEN) {
    printf("Maximum applications received.\n");
    return -1;
  }
  list->List[list->numberOfApplicants] = create_new_application(list->numberOfApplicants, name, program, email, entranceTestRank, UGGrade);
  printf("Your application has been accepted! Please note the application number: %d \n", list->numberOfApplicants);
  list->numberOfApplicants++;
  return 0;
}

Application create_new_application(uint16_t _application_number_, const char *name, const char *program, const char *email, uint32_t entranceTestRank, float UGGrade) {
  Application application = {_application_number_, "", "", "", 0, entranceTestRank, UGGrade, WAITING};
  strcpy(application.name, name);
  strcpy(application.program, program);
  strcpy(application.email, email);
  return application;
}

void update_application_status(Application * application, APPLICATION_STATUS status) {
  application->admissionStatus = status;
}

void update_application_registration_number(Application * application, const uint32_t regNumber) {
  application->regNumber = regNumber;
}

void print_application_details(ApplicantList *list, uint16_t applicationNumber) {
  Application *application = &list->List[applicationNumber];
  printf("Application number: %d\n", application->_application_number_);
  printf("Applicant name    : %d\n", application->name);
  printf("Applied program   : %d\n", application->program);
  printf("Applicant email   : %d\n", application->email);
  printf("Entrance exam rank: %d\n", application->entranceTestRank);
  printf("Applicant UG grade: %d\n", application->UGGrade);
  printf("Application status: %d\n", application->admissionStatus);
  if (application->admissionStatus == ALLOTTED)
    printf("Registration number: %d\n", application->regNumber);
}

uint32_t get_total_applicants(const ApplicantList *list) {
  return list->numberOfApplicants;
}


void update_application_program(ApplicantList *list , const uint16_t applicationNumber, const char *programName) {
  strcpy(list->List[applicationNumber].program, programName);
}
