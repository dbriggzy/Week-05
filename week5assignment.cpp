#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//set constants for prices
double priceS = 175.00;
double priceM = 190.00;
double priceL = 200.00;
double priceX = 300.00;

//function to give instructions to user
void ShowUsage()
{
    cout << "To show program usage press 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
    cout << setfill(' ') << setw(60) << " " << endl;
}

//function to take an order for surfboards from user
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalX)
{
    //input statement
    cout << "Please enter the quantity and type (S=small, M=medium, L=large, X=squirrel surfing) of surfboard you would like to purchase:" << endl;
    //declare input variables to store
    int userq;
    char usert;
    cin >> userq; cin >> usert;
    usert = tolower(usert);
    //conditions to add user purchases to surfboard counts in each individual size category
    if(usert == 's')
        iTotalSmall = iTotalSmall + userq;
    if(usert == 'm')
        iTotalMedium = iTotalMedium + userq;
    if(usert == 'l')
        iTotalLarge = iTotalLarge + userq;
    if(usert == 'x')
        iTotalX = iTotalX + userq;
}

//function to display number of surfboards per size on "tab"
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalX)
{
    if(iTotalSmall > 0)
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    if(iTotalMedium > 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    if(iTotalLarge > 0)
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    if(iTotalX > 0)
        cout << "The total number of X surfboards is " << iTotalX << endl;
    if((iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0) && (iTotalX ==0))
        cout << "No purchases made yet." << endl;
}

//calculate and output totals for each surfboard size and overall total due
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalX)
{
    //declare variables
    double tsmall;
    double tmedium;
    double tlarge;
    double tx;
    double tdue;
    //math for totals
    tsmall = iTotalSmall * priceS;
    tmedium = iTotalMedium * priceM;
    tlarge = iTotalLarge * priceL;
    tx = iTotalX * priceX;
    tdue = tsmall + tmedium + tlarge + tx;
    //output totals to user
    if(iTotalSmall > 0)
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of " << '$' << fixed << setprecision(2) << tsmall << endl;
    if(iTotalMedium > 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of " << '$' << fixed << setprecision(2) << tmedium << endl;
    if(iTotalLarge > 0)
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of " << '$' << fixed << setprecision(2) << tlarge << endl;
    if(iTotalX > 0)
        cout << "The total number of X surfboards is " << iTotalX << " at a total of " << '$' << fixed << setprecision(2) << tx << endl;
    if((iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0) && (iTotalX == 0))
        cout << "No purchases made yet." << endl;
    else
        cout << "Amount due: " << '$' << setprecision(2) << tdue << endl;
    
}

int main()
{
    //welcome message (I decided to keep it out of the ShowUsage() function because you don't need another welcome message if you enter 's')
    cout << setfill('*') << setw(60) << "*" << endl;
    cout << setfill('*') << setw(55) << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << "*" << endl;
    cout << setfill('*') << setw(60) << "*" << endl;
    cout << setfill(' ') << setw(60) << " " << endl;
    cout << setfill(' ') << setw(60) << " " << endl;

    //call instruction function
    ShowUsage();
    //declare variables
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    int iTotalX = 0;
    char selection;
    //infinite loop allowing the user to select each operation until user wants to quit
    while(selection != 'q')
    {
        cout << setfill(' ') << setw(60) << " " << endl;
        cout << "Please enter selection: " << endl;
        cin >> selection;
        selection = tolower(selection);
        if(selection == 'p')
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalX);
        if(selection == 'c')
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalX);
        if(selection == 't')
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalX);
        if(selection == 's')
            ShowUsage();
        if(selection == 'q')
            cout << "Thank you" << endl;
    }
    return 1;
}
