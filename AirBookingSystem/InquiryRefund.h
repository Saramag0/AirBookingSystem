#ifndef _INQUIRYREFUND_H
#define _INQUIRYREFUND_H

#include <string>
#include "FlightSchedule.h"
#include "ReservationDataBase.h"
using namespace std;

class InquiryRefund {
public:
	InquiryRefund(ReservationDataBase reservationdatabase, FlightSchedule flightschedule);

	// perform booking inquiry
	bool bookingInquiry(string id);
	// perform refund application
	void refundApplication(string id);

	ReservationDataBase reservationdatabase;
	FlightSchedule flightschedule;
private:

};

#endif