#include <stdint.h>
#include "appconst.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct _application_ {
  uint16_t                _application_number_;
  char                    name[STUDENT_NAME_LEN];
  char                    program[PROGRAM_NAME_LEN];
  char                    email[EMAIL_LEN];
  uint32_t                regNumber;
  uint32_t                entranceTestRank;
  float                   UGGrade;
  APPLICATION_STATUS      admissionStatus;
};

typedef struct _application_ Application;

struct _applicant_list_ {
  Application List[MAX_APPLICATION_LEN];
  uint32_t    numberOfApplicants;
};

typedef struct _applicant_list_ ApplicantList;

ApplicantList           initialize_applicant_list(void);
int8_t                  add_new_application(ApplicantList *, const char *, const char *, const char *, uint32_t, float);
static Application      create_new_application(uint16_t, const char *, const char *, const char *, uint32_t, float);
void                    update_application_status(Application *, APPLICATION_STATUS);
void                    print_application_details(ApplicantList *, uint16_t);
uint32_t                get_total_applicants(const ApplicantList *);
void                    update_application_registration_number(Application * , const uint32_t);
void                    update_application_program(ApplicantList * , const uint16_t, const char *);

#endif