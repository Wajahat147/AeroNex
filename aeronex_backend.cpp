#include <iostream>
#include <string>
#include <sstream>
#include <limits> // For input validation

using namespace std;

// Constants
const int MAX_FLIGHTS = 20;
const int MAX_BOOKINGS = 50;

// Flight structure
struct Flight {
    string flightID;
    string departureTime;
    string locationFrom;
    string destination;
    string classType;
    int ticketPrice;
};

// Booking structure
struct Booking {
    string bookingID;
    string passengerName;
    int age;
    string cnic;
    string flightID;
    string paymentMethod;
    string transactionID;
};

// Global arrays to store flights and bookings
Flight flights[MAX_FLIGHTS];
Booking bookings[MAX_BOOKINGS];
int flightCount = 0;
int bookingCount = 0;

// Function declarations
void adminPanel();
void passengerPanel();
void displayFlights();
void addFlight();
void updateFlight();
void deleteFlight();
void bookTicket();
void cancelTicket();
void showBookings();
void seedFlights();
string generateBookingID();
int getValidatedChoice();
string intToString(int num);

// Main function
int main() {
    seedFlights(); // Pre-load Pakistani domestic flights

    int choice;
    do {
        cout << "\n===============================\n";
        cout << "        MAIN MENU\n";
        cout << "===============================\n";
        cout << "1. ADMIN PANEL\n";
        cout << "2. PASSENGER PANEL\n";
        cout << "3. EXIT\n";
        cout << "Enter your choice: ";
        choice = getValidatedChoice();

        switch (choice) {
            case 1:
                adminPanel();
                break;
            case 2:
                passengerPanel();
                break;
            case 3:
                cout << "Exiting the program. Thank you!\n";
                break;
            default:
                cout << "INVALID CHOICE! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Pre-load 10 Pakistani domestic flights
void seedFlights() {
    flights[flightCount++] = {"PK-101", "08:30 AM", "Karachi",   "Lahore",    "Economy",     15000};
    flights[flightCount++] = {"PK-201", "10:00 AM", "Lahore",    "Islamabad", "Economy",      8500};
    flights[flightCount++] = {"PK-301", "12:30 PM", "Islamabad", "Karachi",   "Business",    28000};
    flights[flightCount++] = {"PK-401", "02:00 PM", "Karachi",   "Peshawar",  "Economy",     18000};
    flights[flightCount++] = {"PK-501", "05:30 PM", "Peshawar",  "Quetta",    "Economy",     12000};
    flights[flightCount++] = {"PK-601", "07:00 AM", "Multan",    "Islamabad", "Economy",      9000};
    flights[flightCount++] = {"PK-701", "09:30 PM", "Lahore",    "Karachi",   "Business",    32000};
    flights[flightCount++] = {"PK-801", "11:15 AM", "Sialkot",   "Karachi",   "Economy",     16500};
    flights[flightCount++] = {"PK-901", "03:45 PM", "Quetta",    "Lahore",    "Economy",     14000};
    flights[flightCount++] = {"PA-101", "06:00 AM", "Karachi",   "Islamabad", "First Class", 45000};
}

// Function to get validated choice
int getValidatedChoice() {
    int choice;
    cin >> choice;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> choice;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear trailing newline for getline
    return choice;
}

// Admin Panel
void adminPanel() {
    string password;
    cout << "Enter Admin Password: ";
    cin >> password;

    if (password == "wajahat") {
        int adminChoice;
        do {
            cout << "\n====== ADMIN PANEL ======\n";
            cout << "1. Add Flight\n";
            cout << "2. Update Flight\n";
            cout << "3. Delete Flight\n";
            cout << "4. Return to Main Menu\n";
            cout << "Enter your choice: ";
            adminChoice = getValidatedChoice();

            switch (adminChoice) {
                case 1:
                    addFlight();
                    break;
                case 2:
                    updateFlight();
                    break;
                case 3:
                    deleteFlight();
                    break;
                case 4:
                    cout << "Returning to Main Menu...\n";
                    break;
                default:
                    cout << "INVALID CHOICE! Try again.\n";
            }
        } while (adminChoice != 4);
    } else {
        cout << "Incorrect Password! Returning to Main Menu...\n";
    }
}

// Add Flight
void addFlight() {
    if (flightCount >= MAX_FLIGHTS) {
        cout << "Flight storage is full! (Max " << MAX_FLIGHTS << ")\n";
        return;
    }

    cout << "\n====== ADD FLIGHT ======\n";

    // Read ID and check for duplicates
    string newID;
    cout << "Enter Flight ID: ";
    getline(cin, newID);
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightID == newID) {
            cout << "Error: Flight ID '" << newID << "' already exists!\n";
            return;
        }
    }
    flights[flightCount].flightID = newID;

    cout << "Enter Departure Time (e.g. 08:30 AM): ";
    getline(cin, flights[flightCount].departureTime);
    cout << "Enter Location From (e.g. Karachi): ";
    getline(cin, flights[flightCount].locationFrom);
    cout << "Enter Destination (e.g. Lahore): ";
    getline(cin, flights[flightCount].destination);
    cout << "Enter Class (Economy/Business/First Class): ";
    getline(cin, flights[flightCount].classType);
    cout << "Enter Ticket Price (PKR): ";
    cin >> flights[flightCount].ticketPrice;

    while (cin.fail() || flights[flightCount].ticketPrice < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid price. Please enter a positive number: ";
        cin >> flights[flightCount].ticketPrice;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Flight Added Successfully!\n";
    flightCount++;
}

// Update Flight
void updateFlight() {
    string flightID;
    cout << "\n====== UPDATE FLIGHT ======\n";
    cout << "Enter Flight ID to Update: ";
    getline(cin, flightID);

    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightID == flightID) {
            cout << "Enter New Departure Time: ";
            getline(cin, flights[i].departureTime);
            cout << "Enter New Location (From): ";
            getline(cin, flights[i].locationFrom);
            cout << "Enter New Destination: ";
            getline(cin, flights[i].destination);
            cout << "Enter New Class (Economy/Business/First Class): ";
            getline(cin, flights[i].classType);
            cout << "Enter New Ticket Price (PKR): ";
            cin >> flights[i].ticketPrice;

            while (cin.fail() || flights[i].ticketPrice < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid price. Please enter a valid number: ";
                cin >> flights[i].ticketPrice;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Flight Updated Successfully!\n";
            return;
        }
    }
    cout << "Flight ID not found!\n";
}

// Delete Flight (cascade-deletes related bookings)
void deleteFlight() {
    string flightID;
    cout << "\n====== DELETE FLIGHT ======\n";
    cout << "Enter Flight ID to Delete: ";
    getline(cin, flightID);

    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightID == flightID) {
            // CASCADE: remove bookings linked to this flight
            int newBkgCount = 0;
            for (int k = 0; k < bookingCount; k++) {
                if (bookings[k].flightID != flightID)
                    bookings[newBkgCount++] = bookings[k];
            }
            int removed = bookingCount - newBkgCount;
            bookingCount = newBkgCount;

            // Shift flights array
            for (int j = i; j < flightCount - 1; j++)
                flights[j] = flights[j + 1];
            flightCount--;

            cout << "Flight Deleted Successfully!";
            if (removed > 0)
                cout << " (" << removed << " related booking(s) also removed.)";
            cout << "\n";
            return;
        }
    }
    cout << "Flight ID not found!\n";
}

// Passenger Panel
void passengerPanel() {
    int passengerChoice;
    do {
        cout << "\n====== PASSENGER PANEL ======\n";
        cout << "1. View Flights\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. View Bookings\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter your choice: ";
        passengerChoice = getValidatedChoice();

        switch (passengerChoice) {
            case 1:
                displayFlights();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                showBookings();
                break;
            case 5:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "INVALID CHOICE! Try again.\n";
        }
    } while (passengerChoice != 5);
}

// Display Flights
void displayFlights() {
    cout << "\n====== AVAILABLE FLIGHTS ======\n";
    for (int i = 0; i < flightCount; i++) {
        cout << "Flight ID: " << flights[i].flightID
             << ", From: " << flights[i].locationFrom
             << ", To: " << flights[i].destination
             << ", Class: " << flights[i].classType
             << ", Price: " << flights[i].ticketPrice << " PKR\n";
    }
}

// Book Ticket
void bookTicket() {
    if (bookingCount >= MAX_BOOKINGS) {
        cout << "Booking storage is full!\n";
        return;
    }

    string flightID;
    cout << "\n====== BOOK TICKET ======\n";
    displayFlights();
    cout << "Enter Flight ID to Book: ";
    cin >> flightID;

    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightID == flightID) {
            bookings[bookingCount].bookingID = generateBookingID();

            cout << "Enter Passenger Name: ";
            cin.ignore();
            getline(cin, bookings[bookingCount].passengerName);
            cout << "Enter Age: ";
            cin >> bookings[bookingCount].age;

            while (cin.fail() || bookings[bookingCount].age <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid age. Please enter a valid number: ";
                cin >> bookings[bookingCount].age;
            }

            cout << "Enter CNIC: ";
            cin >> bookings[bookingCount].cnic;
            cout << "Choose Payment Method (Bank/Digital Wallet): ";
            cin >> bookings[bookingCount].paymentMethod;
            cout << "Account Number: 123456789\n";
            cout << "Please transfer the payment and enter your Transaction ID: ";
            cin >> bookings[bookingCount].transactionID;

            bookings[bookingCount].flightID = flightID;
            bookingCount++;
            cout << "Transaction ID Received. Ticket Booked Successfully!\n";
            cout << "Your Booking ID: " << bookings[bookingCount - 1].bookingID << "\n";
            return;
        }
    }
    cout << "Flight ID not found!\n";
}

// Cancel Ticket
void cancelTicket() {
    string bookingID;
    cout << "\n====== CANCEL TICKET ======\n";
    cout << "Enter Booking ID to Cancel: ";
    cin >> bookingID;

    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingID == bookingID) {
            for (int j = i; j < bookingCount - 1; j++) {
                bookings[j] = bookings[j + 1];
            }
            bookingCount--;
            cout << "Booking Canceled Successfully!\n";
            return;
        }
    }
    cout << "No booking found with the provided Booking ID!\n";
}

// Show Bookings
void showBookings() {
    cout << "\n====== ALL BOOKINGS ======\n";
    for (int i = 0; i < bookingCount; i++) {
        cout << "Booking ID: " << bookings[i].bookingID
             << ", Name: " << bookings[i].passengerName
             << ", CNIC: " << bookings[i].cnic
             << ", Flight ID: " << bookings[i].flightID << "\n";
    }
}

// Generate Booking ID
string generateBookingID() {
    return "BKG" + intToString(bookingCount + 1);
}

// Convert Integer to String
string intToString(int num) {
    ostringstream ss;
    ss << num;
    return ss.str();
}
