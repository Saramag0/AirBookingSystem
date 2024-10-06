#include "FlightSchedule.h"
#include "Flight.h"
#include "InquiryRefund.h"
#include "ReservationDataBase.h"
#include "Resservation.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

InquiryRefund::InquiryRefund(ReservationDataBase reservationdatabase, FlightSchedule flightschedule)
{
    InquiryRefund::reservationdatabase = reservationdatabase;
    InquiryRefund::flightschedule = flightschedule;
}

// perform booking inquiry
bool InquiryRefund::bookingInquiry(string id) 
{
    flightschedule.loadFlightSchedules();
    reservationdatabase.loadReservations();

    int number = 1;
    bool check = false;

    for (int i = 0; i < reservationdatabase.getNum(); i++) {
        if (reservationdatabase.getreservations(i).getIdValue() == id) {  //存在與輸入相符合的id
            cout << endl << number << ". ";
            reservationdatabase.displayReservation(reservationdatabase.getreservations(i), flightschedule, 108);
            number++;
            check = true;
        }
    }

    if (check == false) {
        cout << endl << "No reservations!" << endl;
    }
    return check;
}
// perform refund application
void InquiryRefund::refundApplication(string id)
{
    fstream ioFile("Reservations.dat", ios::in | ios::out | ios::binary);
    ioFile.seekg(0, ios::end);
    int num = static_cast<int>(ioFile.tellg()) / sizeof(Reservation);
    ioFile.seekg(0, ios::beg);

    Reservation recard;
    if (bookingInquiry(id)) {
        cout << endl << "Enter your choice: ";
        int choosefunction;
        cin >> choosefunction;
        cout << endl;
        int function = 1;
        for (int i = 0; i < num; i++) {
            ioFile.read((char*)&recard, sizeof(Reservation));
            if (reservationdatabase.getreservations(i).getIdValue() == id) {
                if (choosefunction == function) {
                    int s = sizeof(Reservation);
                    ioFile.seekp(-s, ios::cur);
                    char a = ' ';
                    ioFile.write(reinterpret_cast<char*>(&a), s);
                    cout << endl << "The seleted booking has been deleted." << endl;
                    ioFile.close();
                    return;
                }
                else function++;
            }
        }
    }
    ioFile.close();
}