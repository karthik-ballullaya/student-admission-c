#ifndef _APPCONST_H_
#define _APPCONST_H_

  #define STUDENT_NAME_LEN    64
  #define PROGRAM_NAME_LEN    32
  #define EMAIL_LEN           64
  #define MAX_PROGRAM_LEN     10
  #define MAX_APPLICATION_LEN 1000

  #define UG_GRADE_CUT_OFF    5.0
  #define REG_NUMBER_OFFSET   100

  /* Application status enum */
  enum _application_status_ {WAITING, ALLOTTED, REJECTED, WITHDRAWN};
  typedef enum _application_status_ APPLICATION_STATUS;

#endif