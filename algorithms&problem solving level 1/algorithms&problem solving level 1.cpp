// algorithms&problem solving level 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Info {
    string name;
    int age;
    bool driveLecin;
};
enum enPassFail { pass = 1,fail = 0};

enum enPrimeNotPrime{prime=1,notPrime=2};
float ReadPostiveNumber(string message) {
    float number=0;
    do {
    cout << message<<endl;
    cin >> number;

    } while (number <= 0);

    return number;
}
enPrimeNotPrime CheckPrime(int Number) {
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimeNotPrime::notPrime;
    }
    return enPrimeNotPrime::prime;
}
void printNumberType(int Number) {
    switch (CheckPrime(Number))
    {   
    case enPrimeNotPrime::prime:
        cout << "Prime Number \n";
        break;
    case enPrimeNotPrime::notPrime:
        cout << "not Prime Number \n";
        break;
    
    }
}
struct stPiggyBankContent {
    int Pinnies, Nickels, Dimes, Quarters, Dollars;
};
stPiggyBankContent readBankContent() {
    stPiggyBankContent PiggyBanckCount;
    cout << "Enter Piny";
    cin >> PiggyBanckCount.Pinnies;
    cout << "Enter Nicky";
    cin >> PiggyBanckCount.Nickels;
    cout << "Enter Dims";
    cin >> PiggyBanckCount.Dimes;
    cout << "Enter Quarters";
    cin >> PiggyBanckCount.Quarters;
    cout << "Enter Dollars";
    cin >> PiggyBanckCount.Dollars;

    return PiggyBanckCount;
}
int CalculateTotalPennies(stPiggyBankContent PiggyBankContent) {
    int TotalPiny = 0;
    TotalPiny = PiggyBankContent.Pinnies * 1 + PiggyBankContent.Nickels * 5 + PiggyBankContent.Dimes * 10 + PiggyBankContent.Quarters * 25 + PiggyBankContent.Dollars * 100;
    return TotalPiny;
}

int ReadMar() {
    int mark;
    cout << "Entar Mark";
    cin >> mark;
    return mark;
}
enPassFail CheckMark(int mark) {
    if (mark > 50)
        return enPassFail::pass;
    else
        return enPassFail::fail;
}
void printResult(int mark) {
    if (CheckMark(mark))
        cout << "Pass \n";
    else
        cout << "Fail \n";
}
Info readData() {
    Info p;
    cout << "Enter Your Name" << endl;
    cin >> p.name;
    cout << "Enter Your Age"<<endl;
    cin >> p.age;
    cout << "Do You Have driver licence" << endl;
    cin >> p.driveLecin;
    return p;
}
bool IsAccepted(Info p) {
    return(p.age > 18 && p.driveLecin);
}
void printData(Info p) {
    if (IsAccepted(p)) {
        cout << "Acceptable";
    }
    else {
        cout << "Rejected";
    }
}
enum enOpraor { add = 'add', divid = '-' };
enOpraor readOprator() {
    char oprator = '+';
    cout << "Enter (+,_)";
    cin >> oprator;
    return (enOpraor) oprator;
}
float readNumber(string message) {

    float number = 0;
    cout << message << endl;
    cin >> number;
    return number;

}
float calcute(float num1, float num2, enOpraor oprator) {
    switch (oprator)
    {
    case enOpraor::add:
        return num1 + num2;
    case enOpraor::divid:
        return num1 - num2;
    default:
        return num1 + num2;

    }
}

float CalculteRemainder(float TotalBill, float TotalCachPaid) {
   return TotalCachPaid - TotalBill  ;

        
}
float TotalBillAfterServiceAndTax(float TotalBill) {
     //TotalBill = (TotalBill * 10)/100 + TotalBill;
    //TotalBill =  TotalBill * 1.1;
  //  TotalBill = (TotalBill * 16) / 100 + TotalBill ;
    //short way 
    TotalBill =TotalBill * 100;

     return TotalBill;
}

struct strTaskDuration {
    int NumberOfDay, NumberOfHours, NumberOfMinuts, NumberOfSeconds;
};
strTaskDuration ReadTaskDuration() {
    strTaskDuration TaskDuration;
    TaskDuration.NumberOfDay = ReadPostiveNumber("Please Enter Number Of Days");
    TaskDuration.NumberOfHours = ReadPostiveNumber("Please Enter Number Of Hours");
    TaskDuration.NumberOfMinuts = ReadPostiveNumber("Please Enter Number Of Minuts");
    TaskDuration.NumberOfSeconds = ReadPostiveNumber("Please Enter Number Of Seconds");

    return TaskDuration;


}
int TaskDurationInSecond(strTaskDuration TaskDuration) {

    int durationInSecond = 0;
    durationInSecond = TaskDuration.NumberOfDay * 24 * 60 * 60;
    durationInSecond += TaskDuration.NumberOfHours  * 60 * 60;
    durationInSecond += TaskDuration.NumberOfMinuts  * 60;
    durationInSecond += TaskDuration.NumberOfSeconds;

    return  durationInSecond;

}

float HoursToDay(float NumberOfHour) {
    return (float) NumberOfHour / 24;
}
float HoursToWeeks(float NumberOfHour) {
    return (float) NumberOfHour / 24 / 7;
}
float DaysToWeeks(float Days) {
    return (float) Days /7;
}
strTaskDuration secondToTaskDuration(int TotalSecond) {
    strTaskDuration taskDuration;

    const int secondsPerDay = 24 * 60 * 60;
    const int secondsPerHour = 60 * 60;
    const int secondsPerMinute = 60;
    int Remainder = 0;

    taskDuration.NumberOfDay = floor(TotalSecond / secondsPerDay);
    Remainder = TotalSecond % secondsPerDay;
    taskDuration.NumberOfHours = (Remainder / secondsPerHour);
    Remainder = Remainder % secondsPerHour;
    taskDuration.NumberOfMinuts = (Remainder / secondsPerMinute);
    Remainder = Remainder % secondsPerMinute;
    taskDuration.NumberOfSeconds = Remainder;


    return taskDuration;


 }
void PrintTaskDurationDetails(strTaskDuration Taskduration) {
    cout << Taskduration.NumberOfDay << ':' << Taskduration.NumberOfHours << ':' << Taskduration.NumberOfMinuts << ':' << Taskduration.NumberOfSeconds;
}

//problem 44
    enum enDayOfWeek{Sat=1,Sun=2,Mon=3,Tue=4,Wed=5,Thu=6,Fr=7};
    int ReadNumberInRange(string Message, int From, int To) {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;

        } while (Number<From||Number>To);
        return Number;
    }

    enDayOfWeek ReadDayOfWeek() {
        return (enDayOfWeek) ReadNumberInRange(" Please enter day of number from 1 to 5", 1, 5);
    }
    string GetDayOfWeek(enDayOfWeek Day) {
        switch (Day)
        {
        case Sat:
            return "SaterDay";
        case Sun:
            return "SunDay";
        case Mon:
            return "MondayDay";
        case Tue:
            return "TuseDay";
        case Wed:
            return "WensDay";
        case Thu:
            return "ThursDay";
        case Fr:
            return "Friday";
        default:
            return "Not day";
        }
    }
    //proplem 45
    enum enMonthOfYear{Jan=1,Feb=2,Mar=3,Apr=4,May=5,Jun=6,Jul=7,Aug=8,Sep=9,Oct=10,Nov=11,Dec=12};
    enMonthOfYear ReadMonthOfYear() {
        return (enMonthOfYear)ReadNumberInRange("Please Enter number from 1 to 12", 1, 12);
    }
    string GetMonthOfYear(enMonthOfYear Month) {
        switch (Month)
        {
        case Jan:
            return "Janary";
        case Feb:
            return "February";

        case Mar:
            return "March";
        case Apr:
            return "April";
        case May:
            return "May";
        case Jun:
            return "Jun";
        case Jul:
            return "July";
        case Aug:
            return "Agust";

        case Sep:
            return "Spetamper";
        case Oct:
            return "October";

        case Nov:
            return "November";

        case Dec:
            return "Decamper";

        default:
            return "Not Month";
        }
    }
    //problem 46


    void PrintLitterAtoZ() {
        for (int i = 65; i <= 90; i++)
        {
            cout << char(i) << endl;
        }
    }
    //problem 47
    float TotalMonths(float LoanAmont, float MonthlyInstallment) {
        return (float)LoanAmont / MonthlyInstallment;
    }
    float MonthlyInstallLment(float LoanAmount, float HowManyMonths){
        return (float)LoanAmount / HowManyMonths;
}
int main()
{
    /*
    float number1=readNumber("Enter number1");
    float number2 = readNumber("Enter number2");
    enOpraor oprator = readOprator();

    cout << " Result" << calcute(number1, number2, oprator);
    */

    //printNumberType(ReadPostiveNumber("please ENter Prime Number"));
    /*
    float TotalPail = ReadPostiveNumber("Please Enter Total Pail");
    float TotalCachPaid = ReadPostiveNumber("Please Enter CachPaid");

    cout << "Reminder" << CalculteRemainder(TotalPail, TotalCachPaid);

    */
    /*
    float TotalBill = ReadPostiveNumber("Enter Total Pill");
    cout << "Total bill "<< TotalBill<<endl;
    cout << TotalBillAfterServiceAndTax(TotalBill);
    */
//    PrintTaskDurationDetails(secondToTaskDuration(193535));
    cout << GetMonthOfYear(ReadMonthOfYear());
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
