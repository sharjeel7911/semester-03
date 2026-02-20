#include "hospital.h"

void hospital() {
    clearScreen();
    cout << "********** Hospital Management System **********" << endl;

    Patient* patient = new Patient(101, "Sharjeel");
    Doctor* doctor = new Doctor(1, "General Physician");

    patient->consultDoctor(doctor);
    patient->display();

    MedicalRecord* record = new MedicalRecord("Cold", "Rest and hydration");
    patient->updateMedicalRecord("Cold", "Rest and hydration");
    patient->display();
    delete doctor;
    delete patient;
    delete record;
    pauseScreen();
}