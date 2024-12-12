#include <iostream>
#include <fstream>

void setupTemperatures();
void showTemperatures();

int main() {
    std::string tempo;
    double temp;
    int choice;
    int counter = 0;
    bool running = true;

    setupTemperatures();

    while (running) {
        std::cout << "**************************\n";
        std::cout << "What Do You Want To Do?:\n";
        std::cout << "1. Show Temperatures\n";
        std::cout << "2. Enter More Temperatures\n";
        std::cout << "3. Delete All Temperatures\n";
        std::cout << "4. Quit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showTemperatures();
                break;

            case 2: {

                std::ofstream fileOut("weather.txt", std::ios::app);
                if (!fileOut.is_open()) {
                    std::cerr << "File Could Not Be Opened\n";
                    return 1;
                    break;
                }

                while (true) {
                    std::cout << "Enter Your Temperature Or 'Q' To Quit: ";
                    std::cin >> tempo;

                    if (tempo == "Q" || tempo == "q")
                    {

                    break;

                    }
                    
                    temp = std::stod(tempo);
                    fileOut << temp << '\n';

                    }

                fileOut.close();
                break;
            }

            case 3: {
                std::ofstream fileIn("weather.txt", std::ios::trunc);
                if (!fileIn.is_open()) {
                    std::cerr << "File Could Not Be Opened\n";
                    return 1;
                }

                fileIn << "";
                std::cout << "Temperatures Were Deleted Successfully.\n";

                fileIn.close();
                break;
            }

            case 4:
                running = false;
                break;

            default:
                std::cout << "Please Enter A Number From 1-3.\n";
                break;
        }
    }

    return 0;
}

void setupTemperatures(){

    std::ifstream fileIn("weather.txt");

    if (!fileIn.is_open()) {
        std::ofstream fileOut("weather.txt");
        fileOut.close();
    }

    fileIn.close();
}

void showTemperatures() {
    std::ifstream fileIn("weather.txt");

    if (!fileIn.is_open()) {
        std::cerr << "File Could Not Be Opened\n";
        return;
    }

    std::string line;
    int lineNumber = 0;
    double total = 0;
    double average = 0;

    while (std::getline(fileIn, line)) {
        std::cout << "Day " << lineNumber + 1 << ": " << line << '\n';
        total += std::stod(line);
        lineNumber++;
    }

    if (lineNumber > 0) {
        average = total / lineNumber;
        std::cout << "The Average Is: " << average << '\n';
    } else {
        std::cout << "No Temperatures Available.\n";
    }

    fileIn.close();
}
