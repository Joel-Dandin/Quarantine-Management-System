#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#define MAXBEDS 10
#define MAXDOC 20
#define MAXALLOCATION 2

using namespace std;

string PatFileLoc = "D:\\BE IV SEM\\Projects\\oops\\Files\\Patients\\";
string DocFileLoc = "D:\\BE IV SEM\\Projects\\oops\\Files\\Doctors\\";
string LogFileLoc = "D:\\BE IV SEM\\Projects\\oops\\Files\\Log.txt";

class Person
{
public:
    int Age;
    string Gender;
    string BloodGroup;

public:
    string Name;
    long ContactNo;

    Person()
    {
    }

    void Display();
};

class Doctor : public Person
{
    string Specialty;

public:
    int DocID;
    int NoOfPatients;
    string DoctorAvaliable;
    //QuarantineHall *HallNo;
    int HallNo;
    static int DocIDCounter;

    Doctor(int n) : HallNo(n) //works fully
    {
        DocID = DocIDCounter++;
        fstream file;
        string filename;
        filename = DocFileLoc + to_string(DocID) + ".txt";
        file.open(filename, ios::app);

        cout << "Enter Doctor Details\nName : ";
        cin >> Name;
        cout << "Age : ";
        cin >> Age;
        cout << "Gender : ";
        cin >> Gender;
        cout << "Blood Group : ";
        cin >> BloodGroup;
        cout<< "Contact Number : ";
        cin >> ContactNo;
        cout << "Specialty : ";
        cin >> Specialty;
        NoOfPatients = 0;
        DoctorAvaliable = "YES";
        if (!file)
        {
            cout << "Doctor File not created!";
        }
        else
        {
            cout << "Doctor File created successfully!" << endl;
            file << "Doctor Details\nDoctor ID : " << DocID << endl;
            file << "Name : " << Name << endl;
            file << "Age : " << Age << endl;
            file << "Gender : " << Gender << endl;
            file << "Blood Group : " << BloodGroup << endl;
            file << "Contact Number : " << ContactNo << endl;
            file << "Speciality : " << Specialty << endl;
            file << "Hall No : " << HallNo << endl;
            file.close();
        }
    }
    Doctor(int n, string N) : HallNo(n) //works fully
    {
        Name = "Dummy";
        DocID = 0;
        Age = 0;
        Gender = "None";
        BloodGroup = "None";
        ContactNo = 0;
        Specialty = "None";
        NoOfPatients = 0;
        DoctorAvaliable = "YES";
    }
    void Display() //works fully
    {
        cout << "Doctor Details\nDoctor ID : " << DocID
             << "\nName : " << Name
             << "\nAge : " << Age
             << "\nGender : " << Gender
             << "\nBlood Group : " << BloodGroup
             << "\nContact Number : " << ContactNo
             << "\nSpecialty : " << Specialty
             << "\nNo of Patients : " << NoOfPatients
             << "\nDoctor available : " << DoctorAvaliable << endl;
    }
};
int Doctor::DocIDCounter = 1;
class Patient : public Person
{
public:
    int PatientID;
    int BedId;
    int HallNo;
    string CovidTest;
    string OtherHealthIssues;
    float CurrentOxygenLevel;
    float Temperature;
    float AmountOFOxygenRequired;
    static int PatientCount;

    Patient(int n) : AmountOFOxygenRequired(n) //works fully
    {
        PatientID = PatientCount++;
        fstream file;
        string filename;
        filename = PatFileLoc + to_string(PatientID) + ".txt";
        file.open(filename, ios::app);
        cout << "Enter patient Details\nName : ";
        cin >> Name;
        cout << "Age : ";
        cin >> Age;
        cout << "Gender : ";
        cin >> Gender;
        cout << "Blood Group : ";
        cin >> BloodGroup;
        cout << "Contact Number : ";
        cin >> ContactNo;
        cout << "Covid test : ";
        cin >> CovidTest;
        cout << "Other Health Issues : ";
        cin >> OtherHealthIssues;
        cout << "Temperature : ";
        cin >> Temperature;
        if (!file)
        {
            cout << "Patient File not created!";
        }
        else
        {
            cout << "Patient File created successfully!" << endl;
            file << "Patient Details\nPatient ID : " << PatientID << endl;
            file << "Name : " << Name << endl;
            file << "Age : " << Age << endl;
            file << "Gender : " << Gender << endl;
            file << "Blood Group : " << BloodGroup << endl;
            file << "Contact Number : " << ContactNo << endl;
            file << "Covid test : " << CovidTest << endl;
            file << "Other Health Issues : " << OtherHealthIssues << endl;
            file << "Current Oxygen Level : " << CurrentOxygenLevel << endl;
            file << "Amount of Oxygen Required : " << AmountOFOxygenRequired << endl;
            file << "Temperature : " << Temperature << endl;
            file.close();
        }
    }
    Patient(int n, string N) : AmountOFOxygenRequired(n) //works fully
    {
        Name = N;
        PatientID = 0;
        Age = 0;
        Gender = "None";
        BloodGroup = "None";
        ContactNo = 0;
        CovidTest = "None";
        CurrentOxygenLevel = 0;
        Temperature = 0;
    }

    void Display() //works fully
    {
        cout << "Patient Details\nPatient ID : " << PatientID
             << "\nName : " << Name
             << "\nAge : " << Age
             << "\nGender : " << Gender
             << "\nBlood Group : " << BloodGroup
             << "\nContact Number : " << ContactNo
             << "\nCovid test : " << CovidTest
             << "\nCurrent Oxygen Level : " << CurrentOxygenLevel
             << "\nTemperature : " << Temperature << endl;
    }
    string CoronaTest()
    {
        return CovidTest;
    }
    float OxygenRequired()
    {
        return AmountOFOxygenRequired;
    }
    Patient ReturnPtr()
    {
        return *this;
    }
};
int Patient::PatientCount = 1;
class Bed
{
public:
    int BedID;
    Doctor *doctor;
    Patient *patient;
    static int BedCount;

    Bed(int n) : BedID(BedCount) //works fully
    {
        BedCount++;
        Patient *p = new Patient(0, "Dummy");
        patient = p;
        Doctor *d = new Doctor(0, "Dummy");
        doctor = d;
    }
    //works fully
    Bed(Doctor *D, Patient *P) : BedID(BedCount), doctor(D), patient(P)
    {
        BedCount++;
    }

    void Display()
    {
        if (doctor->DocID != 0 && patient->PatientID != 0)
        {
            cout << "Bed ID : " << BedID + 1 << endl;
            doctor->Display();
            cout << endl;
            patient->Display();
            cout << endl;
        }
        else if (doctor->DocID == 0 && patient->PatientID != 0)
        {
            cout << "Bed ID : " << BedID + 1 << "\nDoctor not assigned!" << endl;
            patient->Display();
            cout << endl;
        }
        else if (patient->PatientID == 0 && doctor->DocID != 0)
        {
            cout << "Bed ID : " << BedID + 1 << "\nPatient not present!" << endl;
            doctor->Display();
            cout << endl;
        }
        else
        {
            cout << "Bed ID : " << BedID + 1 << "\nDoctor and patient not assigned!" << endl;
            cout << endl;
        }
        cout << endl;
    }
    void DisplayMin()
    {
        if (doctor->DocID != 0 && patient->PatientID != 0)
        {
            cout << "Bed ID : " << BedID + 1 << endl;
            cout << "Doctor ID : " << doctor->DocID << endl;
            cout << endl;
            cout << "Patient ID : " << patient->PatientID << endl;
            cout << endl;
        }
        else if (doctor->DocID == 0 && patient->PatientID != 0)
        {
            cout << "Bed ID : " << BedID + 1 << "\nDoctor not assigned!" << endl;
            cout << "Patient ID : " << patient->PatientID << endl;
            cout << endl;
        }
        else if (patient->PatientID == 0 && doctor->DocID != 0)
        {
            cout << "Bed ID : " << BedID + 1 << "\nPatient not present!" << endl;
            cout << "Doctor ID : " << doctor->DocID << endl;
            cout << endl;
        }
        else
        {
            cout << "Bed ID : " << BedID + 1 << "\nDoctor and patient not assigned!" << endl;
            cout << endl;
        }
    }
};
int Bed::BedCount = 0;
class Supply
{
public:
    int FoodItems;
    int Medicine;
    float OxygenLevel;

    Supply(int F, int M, float O) : FoodItems(F), Medicine(M), OxygenLevel(O)
    {
    }

    void AddSupply(int f, int m, float o)
    {
        FoodItems += f;
        Medicine += m;
        OxygenLevel += o;
    }
    void AddFoodItems(int n)
    {
        FoodItems += n;
    }
    void AddMedicine(int n)
    {
        Medicine += n;
    }
    void AddOxygenLevel(float n)
    {
        OxygenLevel += n;
    }
    void DisplaySupply()
    {
        cout << "Supply Contents\nFood Items : " << FoodItems << "\nMedicine : " << Medicine << "\nOxygen Present : " << OxygenLevel << endl;
    }
};

class QuarantineHall
{
    int NoBeds;
    int NoPatients;
    int NoDoctors;
    int NoDoctorsHired;
    int NoAvaliableBeds;

public:
    int HallNo;
    string HallIncharge;
    Bed *bed[MAXBEDS];
    Doctor *docUnit[MAXDOC];
    Supply *supply;
    static int HallNoCount;

    QuarantineHall() //works fully
    {
        HallNoCount++;
        HallNo = HallNoCount;
        Supply *S = new Supply(0, 0, 0);
        supply = S;
        Doctor *d = new Doctor(1, "Dummy");
        for (int i = 0; i < NoBeds; i++)
        {
            Bed B(0);
            bed[i] = &B;
        }
        for (int i = 0; i <= NoDoctors; i++)
        {
            docUnit[i] = d;
            //docUnit[i]->Display();
        }

        cout << "Quarantine hall is created" << endl;
    }
    //works fully
    QuarantineHall(int B, int P, int D, string I) : NoBeds(B), NoPatients(P), NoDoctors(D), HallIncharge(I)
    {
        NoAvaliableBeds = B;
        NoDoctorsHired = 0;
        HallNoCount++;
        HallNo = HallNoCount;
        Supply *S = new Supply(0, 0, 0);
        supply = S;
        Doctor *d = new Doctor(1, "Dummy");

        for (int i = 0; i <= NoBeds; i++)
        {
            Bed *B = new Bed(0);
            bed[i] = B;
            //bed[i]->doctor->Display();
        }
        for (int i = 0; i <= NoDoctors; i++)
        {
            docUnit[i] = d;
            //docUnit[i]->Display();
        }
        cout << "Quarantine hall is created" << endl;
    }
    bool Admit() //works fully
    {

        int select = 0, i = 0;
        float OxyLevel,OxyNeded;
        if (supply->FoodItems >= 14 && supply->Medicine >= 14)
        {
            //cout << "If patient need oxygen press 1 otherwise 0" << endl;
            //cin >> select;
            cout << "Current Oxygen Level : ";
            cin >> OxyLevel;
            if (OxyLevel < 95) //checks if oxygen level is less than normal
            {
                cout << "Oxygen level less than normal.Enter amount of oxygen prescribed by doctor" << endl;
                cin >> OxyNeded;
                if (supply->OxygenLevel >= OxyNeded)
                {
                    i = 0;
                    while (bed[i]->patient->PatientID != 0 && i < NoBeds)
                    {
                        i++;
                    }
                    if (i >= NoBeds -1)
                    {
                        cout << "No beds Please try other Hall" << endl;
                        return false;
                    }
                    else
                    {
                        Patient p(OxyNeded);                  //this will ask for patient details
                        p.CurrentOxygenLevel = OxyLevel;
                        *bed[i]->patient = p;
                        cout << "Patient admited" << endl;
                        supply->FoodItems -= 14;
                        supply->Medicine -= 14;
                        supply->OxygenLevel -= OxyNeded;
                        NoPatients += 1;
                        NoAvaliableBeds -= 1;
                        cout << "Patient added to Bed " << i + 1 << endl;
                        bed[i]->Display();
                        return true;
                    }
                }
                else
                {
                    cout << "Sorry Oxygen supply is less try other hall" << endl;
                    return false;
                }
            }
            else
            {
                while (bed[i]->patient->PatientID != 0 && i < NoBeds)
                {
                    i++;
                }
                if (i >= NoBeds - 1)
                {
                    cout << "No beds Please try other Hall" << endl;
                    return false;
                }
                else
                {
                    Patient p(0);                  //this will ask for patient details
                    p.CurrentOxygenLevel = OxyLevel;
                    *bed[i]->patient = p;
                    cout << "Patient admited" << endl;
                    supply->FoodItems -= 14;
                    supply->Medicine -= 14;
                    NoPatients += 1;
                    NoAvaliableBeds -= 1;
                    cout << "Patient added to Bed " << i + 1 << endl;
                    bed[i]->Display();
                    return true;
                }
            }
        }
        else
        {
            cout << "Sorry the supply is less please try other hall" << endl;
            return false;
        }
    }
    bool Discharge() //works fully
    {
        int ID, i = 0, days;
        bool flag = false;
        cout << "Enter patient ID to discharge" << endl;
        cin >> ID;
        for (int i = 0; i < NoBeds; i++)
        {
            if (bed[i]->patient->PatientID == ID)
            {
                Patient *p = new Patient(0, "Dummy");
                bed[i]->patient = p;
                flag = true;
            }
        }
        if (flag)
        {
            NoPatients -= 1;
            NoAvaliableBeds += 1;
            cout << "After how many days did the patient leave? ";
            cin >> days;
            supply->FoodItems += (14 - days);
            supply->Medicine += (14 - days);
            cout << "Patient " << ID << " Discharged" << endl;
            return true;
        }
        else
        {
            cout << "Sorry patient not found" << endl;
            return false;
        }
    }
    void HireDoctor() //works fully
    {
        int i = 0;
        while (docUnit[i]->DocID != 0 && i < NoDoctors)
        {
            i++;
        }
        if (i >= NoDoctors)
        {
            cout << "No room for doctor admission" << endl;
        }
        else
        {
            Doctor *d = new Doctor(1);
            docUnit[i] = d;
            NoDoctorsHired += 1;
            cout << "Doctor added to the center " << i + 1 << "\n"
                 << endl;
        }
    }
    void FireDoctor() //works fully
    {
        int ID, i = 0;
        bool flag = false;
        cout << "Enter Doctor ID to Fire : ";
        cin >> ID;
        for (int i = 0; i < NoDoctors; i++)
        {
            if (docUnit[i]->DocID == ID)
            {
                Doctor *d = new Doctor(1, "Dummy");
                docUnit[i] = d;
                flag = true;
            }
        }
        if (flag)
        {
            NoDoctorsHired -= 1;
            cout << "Doctor " << ID << " Fired" << endl;
        }
        else
        {
            cout << "Sorry Doctor not found" << endl;
        }
    }
    void AssignDoctor()
    {
        int pid, adid, did;
        bool flag;
        cout << "Enter Patient Id : ";
        cin >> pid;
        cout << "Assign doctor ID : ";
        cin >> adid;
        for (int i = 0; i < NoDoctors; i++)
        {
            if (docUnit[i]->DocID == adid)
            {
                did = i;
                flag = true;
            }
        }
        if (flag)
        {
            flag = false;
            for (int i = 0; i < NoBeds; i++)
            {
                if (bed[i]->patient->PatientID == pid && docUnit[did]->NoOfPatients < MAXALLOCATION)
                {
                    bed[i]->doctor = docUnit[did];
                    flag = true;
                }
            }
            if (flag)
            {
                docUnit[did]->NoOfPatients += 1;
                if (docUnit[did]->NoOfPatients >= MAXALLOCATION)
                {
                    docUnit[did]->DoctorAvaliable = "NO";
                }

                cout << "Doctor Id " << did + 1 << " assigned to Patient ID " << pid << endl;
            }
            else if (docUnit[did]->NoOfPatients >= MAXALLOCATION)
            {
                cout << "Sorry doctor's Max allocation of full try other doctor" << endl;
            }
            else
            {
                cout << "Sorry patient not found or you are not assigned to this patient" << endl;
            }
        }
        else
        {
            cout << "Sorry Doctor not found" << endl;
        }
    }
    void RemoveDoctor()
    {
        int pid, did;
        bool flag;
        cout << "Enter Patient Id" << endl;
        cin >> pid;
        for (int i = 0; i < NoBeds; i++)
        {
            if (bed[i]->patient->PatientID == pid)
            {
                did = i;
                flag = true;
            }
        }
        if (flag)
        {
            Doctor *d = new Doctor(1, "Dummy");
            bed[did]->doctor->NoOfPatients -= 1;
            bed[did]->doctor = d;
            cout << "Doctor Id " << did + 1 << " removed from Patient ID " << pid << endl;
        }
        else
        {
            cout << "Sorry patient not found or you are not assigned to this patient" << endl;
        }
    }
    void GetPatientInfo()
    {
        int pn, did, i = 0;
        bool flag = false;
        cout << "Enter patient ID : ";
        cin >> pn;
        cout << "Enter your Doc ID : ";
        cin >> did;
        for (int i = 0; i < NoBeds; i++)
        {
            if (bed[i]->patient->PatientID == pn && bed[i]->doctor->DocID == did)
            {
                cout << "Doctor Assigned " << did << endl;
                bed[i]->patient->Display();
                flag = true;
            }
        }
        if (flag)
        {
            cout << "end of Patient detail" << endl;
        }
        else
        {
            cout << "Sorry patient not found" << endl;
        }
    }
    void GetDocInfo()
    {
        int did;
        bool flag = false;
        cout << "Enter your Doc ID : ";
        cin >> did;
        for (int i = 0; i < NoDoctors; i++)
        {
            if (docUnit[i]->DocID == did)
            {
                docUnit[i]->Display();
                flag = true;
            }
        }
        if (flag)
        {
            cout << "End of Doctor detail" << endl;
        }
        else
        {
            cout << "Sorry Doctor not found" << endl;
        }
    }
    void GetDocpatients()
    {
        int did;
        bool flag;
        cout << "enter Doc ID : ";
        cin >> did;
        cout << "Patients Assigned Doctor id" << did << endl;
        for (int i = 0; i < NoBeds; i++)
        {
            if (bed[i]->doctor->DocID == did && bed[i]->patient->PatientID != 0)
            {
                cout << "Patient ID : " << bed[i]->patient->PatientID << endl;
                flag = true;
            }
        }
        if (flag)
        {
            cout << "End of Patient detail" << endl;
        }
        else
        {
            cout << "No Patients assigned or doctor does not exist" << endl;
        }
    }
    void AvaliabilityOfBeds()
    {
        cout << "No of Beds available : " << NoAvaliableBeds << endl;
    }
    void DisplayTotal() //works fully
    {
        for (int i = 0; i < NoBeds; i++)
        {
            cout << "quarantine hall bed no " << i + 1 << endl;
            bed[i]->Display();
        }
    }
    void DisplayBeds() //works fully
    {
        for (int i = 0; i < NoBeds; i++)
        {
            cout << "quarantine hall bed no " << i + 1 << endl;
            bed[i]->DisplayMin();
        }
    }
    void DisplayDoctors() //works fully
    {

        for (int i = 0; i < NoDoctors; i++)
        {
            if (docUnit[i]->DocID != 0)
            {
                cout << "Quarantine hall Doctor ID " << docUnit[i]->DocID << endl;
                docUnit[i]->Display();
                cout << endl;
            }
        }
    }
    void Search()
    {
        int choice;
        string searchname1, searchname2;
        cout << "Enter 0 to search Patient and 1 to search doctor : ";
        cin >> choice;
        if (!choice)
        {
            cout << "Enter Patient Name : ";
            cin >> searchname1;
            cout << "Search results" << endl;
            for (int i = 0; i < NoBeds; i++)
            {
                if (bed[i]->patient->Name == searchname1)
                {
                    cout << "Patient ID " << bed[i]->patient->PatientID << endl;
                }
            }
        }
        else
        {
            cout << "Enter Doctor Name : ";
            cin >> searchname2;
            cout << "Search results" << endl;
            for (int i = 0; i < NoDoctors; i++)
            {
                if (docUnit[i]->Name == searchname2)
                {
                    cout << "Doctor ID " << docUnit[i]->DocID << endl;
                }
            }
        }
    }
    void DisplayHallInfo()
    {
        cout << "Basis Information\nNo of Beds : " << NoBeds
             << "\nNo of Beds Avaliable : " << NoAvaliableBeds
             << "\nNo of Patients : " << NoPatients
             << "\nNo of Doctors : " << NoDoctors
             << "\nNo of Doctors Hired : " << NoDoctorsHired << endl;
    }
};
int QuarantineHall::HallNoCount = 0;
int main()
{
    int ch, b = 3, p = 0, d = 2, s1 = 30, s2 = 30, s3 = 30, did, pid, i;
    QuarantineHall H1(b, p, d, "admin");
    bool ret;
    string n, pass, pass2;
    time_t my_time = time(NULL);
    string CurrentTime = ctime(&my_time);
    CurrentTime.pop_back();
    fstream Logfile;
    Logfile.open(LogFileLoc, ios::app);
    PlaySoundA((LPCSTR) "D:\\BE IV SEM\\Projects\\oops\\Music\\Quarentine hall.WAV", NULL, SND_FILENAME | SND_ASYNC);
    sleep(5);

    while (1)
    {
        cout << "1 - Add Supply\n"
             << "2 - Hire Doctors\n"
             << "3 - Fire Doctor\n"
             << "4 - Admit patient\n"
             << "5 - Discharge patient\n"
             << "6 - Assign Doctor\n"
             << "7 - remove doctor\n"
             << "8 - Search\n"
             << "9 - Display Beds In hall\n"
             << "10 - Display Individual Patient information\n"
             << "11 - Display Individual Doctor information\n"
             << "12 - Display Doctor's Patients\n"
             << "13 - Display All doctors information\n"
             << "14 - Display current hall information\n"
             << "15 - Supply details\n"
             << "16 - Setting\n"
             << "17 - Clear screen\n"
             << "18 - Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        /*case 0:{
            0 - Create Quarantine hall
            cout<<"Enter no of Beds"<<endl;
            cin>>b;
            cout<<"Enter no of Patients"<<endl;
            cin>>p;
            cout<<"Enter no of Doctor"<<endl;
            cin>>d;
            cout<<"Enter Hall Incharge Name"<<endl;
            cin>>n;
            QuarantineHall H1(b,p,d,n);
            cout<<"Quarantine hall created"<<endl;
            break;}*/
        case 1:
            cout << "Enter Supply to the Hall" << endl;
            cout << "Enter food Sets : ";
            cin >> s1;
            cout << "Enter Medicine Sets : ";
            cin >> s2;
            cout << "Enter Oxygen Sets : ";
            cin >> s3;
            H1.supply->AddSupply(s1, s2, s3);
            Logfile << CurrentTime << " Supply was added F=" << s1 << " M=" << s2 << " O=" << s3 << endl;
            cout << "Supply added\n"
                 << endl;
            break;
        case 2:
            cout << "Hiring a doctor " << endl;
            Logfile << CurrentTime << " Receptionist tried to hire a Doctor" << endl;
            H1.HireDoctor();
            Logfile << "Doctor Hired" << endl;
            break;
        case 3:
            cout << "Fire a doctor" << endl;
            Logfile << CurrentTime << " Receptionist tried to Fire a Doctor" << endl;
            H1.FireDoctor();
            Logfile << "Doctor Fired" << endl;
            break;
        case 4:
            cout << "Admit a patient" << endl;
            Logfile << CurrentTime << " Receptionist tried to Admit a patient" << endl;
            H1.AvaliabilityOfBeds();
            ret = H1.Admit();
            if(ret)
            {
                PlaySoundA((LPCSTR) "D:\\BE IV SEM\\Projects\\oops\\Music\\Get well soon.WAV", NULL, SND_FILENAME | SND_ASYNC);
                sleep(2);
            }
            break;
        case 5:
            cout << "Discharge a patient" << endl;
            Logfile << CurrentTime << " Receptionist tried to Discharge a patient" << endl;
            ret = H1.Discharge();
            if(ret)
            {
                PlaySoundA((LPCSTR) "D:\\BE IV SEM\\Projects\\oops\\Music\\Congats on getting well.WAV", NULL, SND_FILENAME | SND_ASYNC);
                sleep(2);
            }
            break;
        case 6:
            cout << "Assigining Doctor" << endl;
            Logfile << CurrentTime << " Receptionist tried to Assign a Doctor to a patient" << endl;
            H1.AssignDoctor(); //assign doc to patient
            cout << "End of details" << endl;
            break;
        case 7:
            cout << "Removing doctor" << endl;
            Logfile << CurrentTime << " Receptionist tried to Remove a Doctor from patient" << endl;
            H1.RemoveDoctor(); //remove patient's doctor
            cout << "End of details" << endl;
            break;
        case 8:
            Logfile << CurrentTime << " Receptionist tried to Search a patient" << endl;
            H1.Search(); //Search rthe doc or patient
            cout << "End of details" << endl;
            break;
        case 9:
            cout << "Beds in hall" << endl;
            Logfile << CurrentTime << " Receptionist tried to Display Bed Info" << endl;
            H1.DisplayBeds(); //write a function to display only patint id and doc id in a bed
            break;
        case 10:
            Logfile << CurrentTime << " Doctor tried to Get Patient Information" << endl;
            H1.GetPatientInfo(); //gets the information to the doc who is assined to the patient
            cout << "End of details" << endl;
            break;
        case 11:
            cout << "Information of Doctor\n Enter Password : ";
            cin >> pass;
            if (pass == "admin")
            {
                Logfile << CurrentTime << " Admin tried to read doctors information" << endl;
                H1.GetDocInfo(); //gets the information of the doc
                cout << "End of Data" << endl;
            }
            else
            {
                Logfile << CurrentTime << " Someone tried to get Doctors information with wrong password!" << endl;
                cout << "wrong password" << endl;
            }

            break;
        case 12:
            Logfile << CurrentTime << " Doctor tried to display his patients ID" << endl;
            H1.GetDocpatients(); //shows the pid of each patient he is assined to
            cout << "End of details" << endl;
            break;
        case 13:
            cout << "Information of doctors" << endl;
            Logfile << CurrentTime << " Receptionist tried to Display all Doctors Information" << endl;
            H1.DisplayDoctors();
            cout << "End of Working doctors" << endl;
            break;
        case 14:
            cout << "Information of hall\nEnter Password : ";
            cin >> pass;
            if (pass == "admin")
            {

                Logfile << CurrentTime << " Admin tried to display Whole hall's information" << endl;
                H1.DisplayHallInfo();
                cout << "For Dept Information press 1 : ";
                cin >> i;
                if (1)
                {
                    H1.DisplayTotal();
                    Logfile << CurrentTime << " Admin tried to display Whole hall's Detailed information" << endl;
                }
                cout << "End of Data" << endl;
            }
            else
            {
                Logfile << CurrentTime << " Someone tried to display Whole hall's information with wrong password!" << endl;
                cout << "wrong password" << endl;
            }
            break;
        case 15:
            cout << "supply details" << endl;
            Logfile << CurrentTime << " Receptionist tried to Display Supply Details" << endl;
            H1.supply->DisplaySupply();
            cout << "End of Data" << endl;
            break;
        case 16:
            cout << "Information of hall\nEnter Password : ";
            cin >> pass2;
            if (pass2 == "admin")
            {
                Logfile << CurrentTime << " Admin tried to change software settings!!" << endl;
                cout << "Enter Patient file location : ";
                cin >> PatFileLoc;
                cout << "Enter Doctor file location : ";
                cin >> DocFileLoc;
                cout << "Enter Log file location : ";
                cin >> LogFileLoc;
                cout << "Setting changed" << endl;
            }
            else
            {
                Logfile << CurrentTime << " Someone tried to change software settings!!!" << endl;
                cout << "wrong password" << endl;
            }

            break;
        case 17:
            system("cls");
            break;
        case 18:
            Logfile.close();
            PlaySoundA((LPCSTR) "D:\\BE IV SEM\\Projects\\oops\\Music\\Thank you.WAV", NULL, SND_FILENAME | SND_ASYNC);
            sleep(5);
            exit(0);
        }
    }
}
