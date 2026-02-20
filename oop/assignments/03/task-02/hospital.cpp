#include "hospital.h"

MedicalRecord::MedicalRecord(const string& diagnosis, const string& treatment) : m_diagnosis(diagnosis), m_treatment(treatment) {}

void MedicalRecord::updateRecord(const string& diagnosis, const string& treatment) {
    m_diagnosis = diagnosis;
    m_treatment = treatment;
}

void MedicalRecord::display() const {
    cout << "Diagnosis: " << m_diagnosis << endl;
    cout << "Treatment: " << m_treatment << endl;
}

//____________________________________________________________

Doctor::Doctor(int id, const string& specialization) : m_doctor_id(id), m_specialization(specialization) {}

void Doctor::treatPatient(Patient* patient) {
    cout << "Doctor (" << m_specialization << ") treating patient.\n";
    patient->updateMedicalRecord("Fever", "Prescribed medication");
}

//____________________________________________________________l

Patient::Patient(int id, const string& name) : m_patient_id(id), m_name(name) {
    m_record = new MedicalRecord();
}

Patient::~Patient() {
    delete m_record;
}
void Patient::consultDoctor(Doctor* doctor) {
    cout << m_name << " is consulting doctor.\n";
    doctor->treatPatient(this);
}

void Patient::updateMedicalRecord(const string& diagnosis, const string& treatment) {
    m_record->updateRecord(diagnosis, treatment);
}

void Patient::display() const {
    cout << "\nPatient ID: " << m_patient_id << "\nName: " << m_name << endl;
    m_record->display();
}