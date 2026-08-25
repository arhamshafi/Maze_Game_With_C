#include <iomanip>
#include <iostream>

using namespace std;

// ============================================================
//              HOSPITAL MANAGEMENT SYSTEM
//              Procedural C++ Project - No OOP
// ============================================================

const int MAX_PATIENTS = 100;
const int MAX_DOCTORS = 10;
const int MAX_APPOINTMENTS = 100;

// ============================================================
//                    FUNCTION PROTOTYPES
// ============================================================

void showHeader();
void showMainMenu();

// Patient Functions
void registerPatient(int patientIDs[], string patientNames[], int patientAges[],
                     string patientGenders[], string patientDiseases[],
                     int &patientCount);

void displayPatients(int patientIDs[], string patientNames[], int patientAges[],
                     string patientGenders[], string patientDiseases[],
                     int patientCount);

void searchPatient(int patientIDs[], string patientNames[], int patientAges[],
                   string patientGenders[], string patientDiseases[],
                   int patientCount);

// Doctor Functions
void showDoctors(int doctorIDs[], string doctorNames[],
                 string doctorSpecializations[], double doctorFees[],
                 int doctorCount);

// Appointment Functions
void bookAppointment(int appointmentIDs[], int appointmentPatientIDs[],
                     int appointmentDoctorIDs[], string appointmentDates[],
                     string appointmentTimes[], int &appointmentCount,
                     int patientIDs[], string patientNames[], int patientCount,
                     int doctorIDs[], string doctorNames[],
                     string doctorSpecializations[], double doctorFees[],
                     int doctorCount, double &totalRevenue);

void displayAppointments(int appointmentIDs[], int appointmentPatientIDs[],
                         int appointmentDoctorIDs[], string appointmentDates[],
                         string appointmentTimes[], int appointmentCount,
                         int patientIDs[], string patientNames[],
                         int patientCount, int doctorIDs[],
                         string doctorNames[], int doctorCount);

// Billing
void generateBill(int patientIDs[], string patientNames[], int patientCount,
                  int doctorIDs[], string doctorNames[],
                  string doctorSpecializations[], double doctorFees[],
                  int doctorCount);

// Hospital Summary
void hospitalSummary(int patientCount, int doctorCount, int appointmentCount,
                     double totalRevenue);

// ============================================================
//                         MAIN
// ============================================================

int main() {
  // --------------------------------------------------------
  // Patient Data
  // --------------------------------------------------------

  int patientIDs[MAX_PATIENTS];
  string patientNames[MAX_PATIENTS];
  int patientAges[MAX_PATIENTS];
  string patientGenders[MAX_PATIENTS];
  string patientDiseases[MAX_PATIENTS];

  int patientCount = 0;

  // --------------------------------------------------------
  // Doctor Data
  // --------------------------------------------------------

  int doctorIDs[MAX_DOCTORS] = {101, 102, 103, 104, 105};

  string doctorNames[MAX_DOCTORS] = {"Dr. Ahmed Khan", "Dr. Sara Ali",
                                     "Dr. Usman Malik", "Dr. Ayesha Noor",
                                     "Dr. Hamza Sheikh"};

  string doctorSpecializations[MAX_DOCTORS] = {"General Physician",
                                               "Cardiologist", "Dermatologist",
                                               "Pediatrician", "Orthopedic"};

  double doctorFees[MAX_DOCTORS] = {1500, 2500, 2000, 1800, 2200};

  int doctorCount = 5;

  // --------------------------------------------------------
  // Appointment Data
  // --------------------------------------------------------

  int appointmentIDs[MAX_APPOINTMENTS];
  int appointmentPatientIDs[MAX_APPOINTMENTS];
  int appointmentDoctorIDs[MAX_APPOINTMENTS];

  string appointmentDates[MAX_APPOINTMENTS];
  string appointmentTimes[MAX_APPOINTMENTS];

  int appointmentCount = 0;

  // --------------------------------------------------------
  // Financial Data
  // --------------------------------------------------------

  double totalRevenue = 0.0;

  // --------------------------------------------------------
  // Main Choice
  // --------------------------------------------------------

  int mainChoice = 0;

  // --------------------------------------------------------
  // Welcome Header
  // --------------------------------------------------------

  showHeader();

  // ========================================================
  //                    MAIN CONTROL LOOP
  // ========================================================

  while (mainChoice != 9) {
    showMainMenu();

    cout << "Enter your choice (1-9): ";
    cin >> mainChoice;

    // Input Validation
    while (cin.fail() || mainChoice < 1 || mainChoice > 9) {
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Invalid choice! Please enter 1-9: ";
      cin >> mainChoice;
    }

    // ====================================================
    // OPTION 1 - REGISTER PATIENT
    // ====================================================

    if (mainChoice == 1) {
      registerPatient(patientIDs, patientNames, patientAges, patientGenders,
                      patientDiseases, patientCount);
    }

    // ====================================================
    // OPTION 2 - DISPLAY PATIENTS
    // ====================================================

    else if (mainChoice == 2) {
      displayPatients(patientIDs, patientNames, patientAges, patientGenders,
                      patientDiseases, patientCount);
    }

    // ====================================================
    // OPTION 3 - SEARCH PATIENT
    // ====================================================

    else if (mainChoice == 3) {
      searchPatient(patientIDs, patientNames, patientAges, patientGenders,
                    patientDiseases, patientCount);
    }

    // ====================================================
    // OPTION 4 - VIEW DOCTORS
    // ====================================================

    else if (mainChoice == 4) {
      showDoctors(doctorIDs, doctorNames, doctorSpecializations, doctorFees,
                  doctorCount);
    }

    // ====================================================
    // OPTION 5 - BOOK APPOINTMENT
    // ====================================================

    else if (mainChoice == 5) {
      bookAppointment(appointmentIDs, appointmentPatientIDs,
                      appointmentDoctorIDs, appointmentDates, appointmentTimes,
                      appointmentCount, patientIDs, patientNames, patientCount,
                      doctorIDs, doctorNames, doctorSpecializations, doctorFees,
                      doctorCount, totalRevenue);
    }

    // ====================================================
    // OPTION 6 - VIEW APPOINTMENTS
    // ====================================================

    else if (mainChoice == 6) {
      displayAppointments(
          appointmentIDs, appointmentPatientIDs, appointmentDoctorIDs,
          appointmentDates, appointmentTimes, appointmentCount, patientIDs,
          patientNames, patientCount, doctorIDs, doctorNames, doctorCount);
    }

    // ====================================================
    // OPTION 7 - GENERATE BILL
    // ====================================================

    else if (mainChoice == 7) {
      generateBill(patientIDs, patientNames, patientCount, doctorIDs,
                   doctorNames, doctorSpecializations, doctorFees, doctorCount);
    }

    // ====================================================
    // OPTION 8 - HOSPITAL SUMMARY
    // ====================================================

    else if (mainChoice == 8) {
      hospitalSummary(patientCount, doctorCount, appointmentCount,
                      totalRevenue);
    }

    // ====================================================
    // OPTION 9 - EXIT
    // ====================================================

    else if (mainChoice == 9) {
      cout
          << "\n============================================================\n";
      cout << "       Thank You For Using Hospital Management System\n";
      cout << "                    Program Closed\n";
      cout << "============================================================\n";
    }
  }

  return 0;
}

// ============================================================
//                         HEADER
// ============================================================

void showHeader() {
  cout << "\n";
  cout << "============================================================\n";
  cout << "             HOSPITAL MANAGEMENT SYSTEM\n";
  cout << "============================================================\n";
  cout << "       Patient | Doctor | Appointment | Billing\n";
  cout << "============================================================\n";
  cout << "           Welcome to Hospital Management System\n";
  cout << "============================================================\n";
}

// ============================================================
//                       MAIN MENU
// ============================================================

void showMainMenu() {
  cout << "\n\n";
  cout << "------------------------------------------------------------\n";
  cout << "                       MAIN MENU\n";
  cout << "------------------------------------------------------------\n";

  cout << "  1. Register New Patient\n";
  cout << "  2. Display All Patients\n";
  cout << "  3. Search Patient\n";
  cout << "  4. View Doctors\n";
  cout << "  5. Book Appointment\n";
  cout << "  6. View Appointments\n";
  cout << "  7. Generate Patient Bill\n";
  cout << "  8. Hospital Summary\n";
  cout << "  9. Exit\n";

  cout << "------------------------------------------------------------\n";
}

// ============================================================
//                   REGISTER PATIENT
// ============================================================

void registerPatient(int patientIDs[], string patientNames[], int patientAges[],
                     string patientGenders[], string patientDiseases[],
                     int &patientCount) {
  if (patientCount >= MAX_PATIENTS) {
    cout << "\n[!] Patient database is full.\n";
    return;
  }

  cout << "\n============================================================\n";
  cout << "                  PATIENT REGISTRATION\n";
  cout << "============================================================\n";

  patientIDs[patientCount] = 1001 + patientCount;

  cout << "Patient ID: " << patientIDs[patientCount] << "\n";

  cin.ignore();

  cout << "Enter Patient Name: ";
  getline(cin, patientNames[patientCount]);

  cout << "Enter Patient Age: ";
  cin >> patientAges[patientCount];

  while (cin.fail() || patientAges[patientCount] <= 0 ||
         patientAges[patientCount] > 120) {
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Invalid age! Enter age between 1-120: ";
    cin >> patientAges[patientCount];
  }

  cout << "Enter Gender (Male/Female): ";
  cin >> patientGenders[patientCount];

  cin.ignore();

  cout << "Enter Disease / Medical Problem: ";
  getline(cin, patientDiseases[patientCount]);

  patientCount++;

  cout << "\n============================================================\n";
  cout << "           PATIENT REGISTERED SUCCESSFULLY!\n";
  cout << "============================================================\n";

  cout << "Patient ID: " << patientIDs[patientCount - 1] << "\n";

  cout << "Patient Name: " << patientNames[patientCount - 1] << "\n";

  cout << "============================================================\n";
}

// ============================================================
//                   DISPLAY PATIENTS
// ============================================================

void displayPatients(int patientIDs[], string patientNames[], int patientAges[],
                     string patientGenders[], string patientDiseases[],
                     int patientCount) {
  if (patientCount == 0) {
    cout << "\n[!] No patients registered yet.\n";
    return;
  }

  cout << "\n============================================================\n";
  cout << "                   REGISTERED PATIENTS\n";
  cout << "============================================================\n";

  cout << left << setw(8) << "ID" << setw(25) << "Name" << setw(8) << "Age"
       << setw(12) << "Gender"
       << "Disease\n";

  cout << "--------------------------------------------------------------------"
          "-\n";

  for (int i = 0; i < patientCount; i++) {
    cout << left << setw(8) << patientIDs[i] << setw(25) << patientNames[i]
         << setw(8) << patientAges[i] << setw(12) << patientGenders[i]
         << patientDiseases[i] << "\n";
  }

  cout << "--------------------------------------------------------------------"
          "-\n";
  cout << "Total Registered Patients: " << patientCount << "\n";
}

// ============================================================
//                    SEARCH PATIENT
// ============================================================

void searchPatient(int patientIDs[], string patientNames[], int patientAges[],
                   string patientGenders[], string patientDiseases[],
                   int patientCount) {
  if (patientCount == 0) {
    cout << "\n[!] No patients registered yet.\n";
    return;
  }

  int searchID;

  cout << "\n============================================================\n";
  cout << "                    PATIENT SEARCH\n";
  cout << "============================================================\n";

  cout << "Enter Patient ID: ";
  cin >> searchID;

  bool found = false;

  for (int i = 0; i < patientCount; i++) {
    if (patientIDs[i] == searchID) {
      found = true;

      cout
          << "\n------------------------------------------------------------\n";
      cout << "Patient Found\n";
      cout << "------------------------------------------------------------\n";

      cout << "Patient ID : " << patientIDs[i] << "\n";
      cout << "Name       : " << patientNames[i] << "\n";
      cout << "Age        : " << patientAges[i] << "\n";
      cout << "Gender     : " << patientGenders[i] << "\n";
      cout << "Disease    : " << patientDiseases[i] << "\n";

      cout << "------------------------------------------------------------\n";

      break;
    }
  }

  if (!found) {
    cout << "\n[!] Patient with ID " << searchID << " was not found.\n";
  }
}

// ============================================================
//                    SHOW DOCTORS
// ============================================================

void showDoctors(int doctorIDs[], string doctorNames[],
                 string doctorSpecializations[], double doctorFees[],
                 int doctorCount) {
  cout << "\n============================================================\n";
  cout << "                    AVAILABLE DOCTORS\n";
  cout << "============================================================\n";

  cout << left << setw(10) << "ID" << setw(25) << "Doctor Name" << setw(25)
       << "Specialization"
       << "Fee\n";

  cout << "--------------------------------------------------------------------"
          "-\n";

  for (int i = 0; i < doctorCount; i++) {
    cout << left << setw(10) << doctorIDs[i] << setw(25) << doctorNames[i]
         << setw(25) << doctorSpecializations[i] << "Rs. " << fixed
         << setprecision(0) << doctorFees[i] << "\n";
  }

  cout << "--------------------------------------------------------------------"
          "-\n";
}

// ============================================================
//                   BOOK APPOINTMENT
// ============================================================

void bookAppointment(int appointmentIDs[], int appointmentPatientIDs[],
                     int appointmentDoctorIDs[], string appointmentDates[],
                     string appointmentTimes[], int &appointmentCount,
                     int patientIDs[], string patientNames[], int patientCount,
                     int doctorIDs[], string doctorNames[],
                     string doctorSpecializations[], double doctorFees[],
                     int doctorCount, double &totalRevenue) {
  if (patientCount == 0) {
    cout << "\n[!] Please register a patient first.\n";
    return;
  }

  if (appointmentCount >= MAX_APPOINTMENTS) {
    cout << "\n[!] Appointment database is full.\n";
    return;
  }

  int patientID;
  int doctorID;

  cout << "\n============================================================\n";
  cout << "                    BOOK APPOINTMENT\n";
  cout << "============================================================\n";

  cout << "Enter Patient ID: ";
  cin >> patientID;

  int patientIndex = -1;

  for (int i = 0; i < patientCount; i++) {
    if (patientIDs[i] == patientID) {
      patientIndex = i;
      break;
    }
  }

  if (patientIndex == -1) {
    cout << "\n[!] Patient ID not found.\n";
    return;
  }

  cout << "\nPatient Name: " << patientNames[patientIndex] << "\n";

  cout << "\nAvailable Doctors:\n";

  showDoctors(doctorIDs, doctorNames, doctorSpecializations, doctorFees,
              doctorCount);

  cout << "\nEnter Doctor ID: ";
  cin >> doctorID;

  int doctorIndex = -1;

  for (int i = 0; i < doctorCount; i++) {
    if (doctorIDs[i] == doctorID) {
      doctorIndex = i;
      break;
    }
  }

  if (doctorIndex == -1) {
    cout << "\n[!] Doctor ID not found.\n";
    return;
  }

  cin.ignore();

  cout << "Enter Appointment Date (DD-MM-YYYY): ";
  getline(cin, appointmentDates[appointmentCount]);

  cout << "Enter Appointment Time (e.g. 10:30 AM): ";
  getline(cin, appointmentTimes[appointmentCount]);

  appointmentIDs[appointmentCount] = 5001 + appointmentCount;

  appointmentPatientIDs[appointmentCount] = patientID;

  appointmentDoctorIDs[appointmentCount] = doctorID;

  totalRevenue += doctorFees[doctorIndex];

  appointmentCount++;

  cout << "\n============================================================\n";
  cout << "            APPOINTMENT BOOKED SUCCESSFULLY!\n";
  cout << "============================================================\n";

  cout << "Appointment ID : " << appointmentIDs[appointmentCount - 1] << "\n";

  cout << "Patient        : " << patientNames[patientIndex] << "\n";

  cout << "Doctor         : " << doctorNames[doctorIndex] << "\n";

  cout << "Specialization : " << doctorSpecializations[doctorIndex] << "\n";

  cout << "Date           : " << appointmentDates[appointmentCount - 1] << "\n";

  cout << "Time           : " << appointmentTimes[appointmentCount - 1] << "\n";

  cout << "Consultation Fee: Rs. " << doctorFees[doctorIndex] << "\n";

  cout << "============================================================\n";
}

// ============================================================
//                 DISPLAY APPOINTMENTS
// ============================================================

void displayAppointments(int appointmentIDs[], int appointmentPatientIDs[],
                         int appointmentDoctorIDs[], string appointmentDates[],
                         string appointmentTimes[], int appointmentCount,
                         int patientIDs[], string patientNames[],
                         int patientCount, int doctorIDs[],
                         string doctorNames[], int doctorCount) {
  if (appointmentCount == 0) {
    cout << "\n[!] No appointments booked yet.\n";
    return;
  }

  cout << "\n============================================================\n";
  cout << "                    APPOINTMENT LIST\n";
  cout << "============================================================\n";

  cout << left << setw(8) << "ID" << setw(22) << "Patient" << setw(22)
       << "Doctor" << setw(15) << "Date"
       << "Time\n";

  cout << "--------------------------------------------------------------------"
          "-\n";

  for (int i = 0; i < appointmentCount; i++) {
    string patientName = "Unknown";
    string doctorName = "Unknown";

    for (int j = 0; j < patientCount; j++) {
      if (patientIDs[j] == appointmentPatientIDs[i]) {
        patientName = patientNames[j];
        break;
      }
    }

    for (int j = 0; j < doctorCount; j++) {
      if (doctorIDs[j] == appointmentDoctorIDs[i]) {
        doctorName = doctorNames[j];
        break;
      }
    }

    cout << left << setw(8) << appointmentIDs[i] << setw(22) << patientName
         << setw(22) << doctorName << setw(15) << appointmentDates[i]
         << appointmentTimes[i] << "\n";
  }

  cout << "--------------------------------------------------------------------"
          "-\n";

  cout << "Total Appointments: " << appointmentCount << "\n";
}

// ============================================================
//                    GENERATE BILL
// ============================================================

void generateBill(int patientIDs[], string patientNames[], int patientCount,
                  int doctorIDs[], string doctorNames[],
                  string doctorSpecializations[], double doctorFees[],
                  int doctorCount) {
  if (patientCount == 0) {
    cout << "\n[!] No patients registered yet.\n";
    return;
  }

  int patientID;
  int doctorID;

  cout << "\n============================================================\n";
  cout << "                    PATIENT BILLING\n";
  cout << "============================================================\n";

  cout << "Enter Patient ID: ";
  cin >> patientID;

  int patientIndex = -1;

  for (int i = 0; i < patientCount; i++) {
    if (patientIDs[i] == patientID) {
      patientIndex = i;
      break;
    }
  }

  if (patientIndex == -1) {
    cout << "\n[!] Patient not found.\n";
    return;
  }

  // Show doctors correctly
  showDoctors(doctorIDs, doctorNames, doctorSpecializations, doctorFees,
              doctorCount);

  cout << "\nEnter Doctor ID for consultation: ";
  cin >> doctorID;

  int doctorIndex = -1;

  for (int i = 0; i < doctorCount; i++) {
    if (doctorIDs[i] == doctorID) {
      doctorIndex = i;
      break;
    }
  }

  if (doctorIndex == -1) {
    cout << "\n[!] Doctor not found.\n";
    return;
  }

  double consultationFee = doctorFees[doctorIndex];

  double medicineCharges;
  double laboratoryCharges;

  cout << "Enter Medicine Charges (Rs): ";
  cin >> medicineCharges;

  while (cin.fail() || medicineCharges < 0) {
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Invalid amount. Enter again: ";
    cin >> medicineCharges;
  }

  cout << "Enter Laboratory Charges (Rs): ";
  cin >> laboratoryCharges;

  while (cin.fail() || laboratoryCharges < 0) {
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Invalid amount. Enter again: ";
    cin >> laboratoryCharges;
  }

  double totalBill = consultationFee + medicineCharges + laboratoryCharges;

  cout << "\n";
  cout << "============================================================\n";
  cout << "                    HOSPITAL BILL\n";
  cout << "============================================================\n";

  cout << "Patient ID          : " << patientIDs[patientIndex] << "\n";

  cout << "Patient Name        : " << patientNames[patientIndex] << "\n";

  cout << "Doctor              : " << doctorNames[doctorIndex] << "\n";

  cout << "Specialization      : " << doctorSpecializations[doctorIndex]
       << "\n";

  cout << "------------------------------------------------------------\n";

  cout << left << setw(30) << "Consultation Fee"
       << ": Rs. " << fixed << setprecision(2) << consultationFee << "\n";

  cout << left << setw(30) << "Medicine Charges"
       << ": Rs. " << medicineCharges << "\n";

  cout << left << setw(30) << "Laboratory Charges"
       << ": Rs. " << laboratoryCharges << "\n";

  cout << "------------------------------------------------------------\n";

  cout << left << setw(30) << "TOTAL BILL"
       << ": Rs. " << totalBill << "\n";

  cout << "============================================================\n";

  cout << "              Thank You For Visiting Us!\n";

  cout << "============================================================\n";
}

// ============================================================
//                    HOSPITAL SUMMARY
// ============================================================

void hospitalSummary(int patientCount, int doctorCount, int appointmentCount,
                     double totalRevenue) {
  cout << "\n============================================================\n";
  cout << "                  HOSPITAL SUMMARY REPORT\n";
  cout << "============================================================\n";

  cout << left << setw(30) << "Registered Patients"
       << ": " << patientCount << "\n";

  cout << left << setw(30) << "Available Doctors"
       << ": " << doctorCount << "\n";

  cout << left << setw(30) << "Total Appointments"
       << ": " << appointmentCount << "\n";

  cout << left << setw(30) << "Appointment Revenue"
       << ": Rs. " << fixed << setprecision(2) << totalRevenue << "\n";

  cout << "============================================================\n";

  if (patientCount == 0) {
    cout << "Hospital Status: Waiting for Patients\n";
  } else if (appointmentCount == 0) {
    cout << "Hospital Status: Patients Registered - No Appointments\n";
  } else {
    cout << "Hospital Status: ACTIVE\n";
  }

  cout << "============================================================\n";
}