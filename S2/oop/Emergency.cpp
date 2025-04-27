#include<iostream>
#include<string>
using namespace std;
class Emergency
{
private:
    string CalerName,CallerPhone,Location,NatureOfEmergency,ResponseType,ResponseStatus;
    time_t TimeOfReport;
public:
    Emergency(string,string,string,string ,string,string);
    ~Emergency();
    void print();
};

Emergency::Emergency(string CalerName,string CallerPhone,string Location,string NatureOfEmergency,string ResponseType,string ResponseStatus):CalerName(CalerName),CallerPhone(CallerPhone),Location(Location),NatureOfEmergency(NatureOfEmergency),ResponseType(ResponseType),ResponseStatus(ResponseStatus)
{
    TimeOfReport=time(nullptr);
}

Emergency::~Emergency()
{
}
void Emergency::print(){
    cout <<"Name of Caller: "<<CalerName << endl;
    cout <<"Phone of Caller: "<<CallerPhone << endl;
    cout <<"Location: " <<Location<< endl;
    cout <<"Nature of emergency: "<<NatureOfEmergency << endl;
    cout <<"Response type: "<<ResponseType << endl;
    cout <<"Response status: "<<ResponseStatus << endl;
    cout <<"Time: "<<ctime(&TimeOfReport) << endl;
}

int main (){
    Emergency e("Tarek","123-234-234","Sidi Abdellah","Police","Crime","now");
    e.print();
}