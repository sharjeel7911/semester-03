#include "../main.h"

class Patient;
class Doctor;

class MedicalRecord {
private:
    string m_diagnosis;
    string m_treatment;
public:
    MedicalRecord(const string& diagnosis = "", const string& treatment = "");
    void updateRecord(const string& diagnosis, const string& treatment);
    void display() const;
};

class Doctor {
private:
    int m_doctor_id;
    string m_specialization;
public:
    Doctor(int id = 0, const string& specialization = "");
    void treatPatient(Patient* patient);
};

class Patient {
private:
    int m_patient_id;
    string m_name;
    MedicalRecord* m_record;   //composition
public:
    Patient(int id = 0, const string& name = "");
    ~Patient();
    void consultDoctor(Doctor* doctor);
    void updateMedicalRecord(const string& diagnosis, const string& treatment);
    void display() const;
};