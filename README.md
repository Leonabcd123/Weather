# Temperature Logger Program

## Description
This C++ program allows the user to manage temperature data. The user can:

- View previously recorded temperatures.
- Enter new temperatures and add them to a file.
- Delete all recorded temperatures.
- Quit the program.
The program stores the temperature data in a text file (`weather.txt`), where each line contains one temperature.

## Features
- Show Temperatures: Displays all recorded temperatures with the day number and the average temperature.
- Enter More Temperatures: Allows the user to input new temperatures, which are added to the file. The user can quit entering temperatures by typing `'Q'` or `'q'`.
- Delete All Temperatures: Clears all data stored in the file.
- Quit: Exits the program.
## Requirements
- A C++ compiler that supports C++11 or later.
- The program works on Windows, macOS, and Linux as long as the file system allows text file manipulation.
## File Structure
- `weather.txt`: A text file that stores the entered temperatures. Each temperature is written on a new line.
## How to Compile and Run
1. **Compile** the program using a C++ compiler:

```bash
g++ -o temperature_logger temperature_logger.cpp
```
2. **Run** the compiled program:

```bash
./temperature_logger
```

## Usage
Upon running the program, the user will be presented with a menu:

markdown
**************************
What Do You Want To Do?:
1. Show Temperatures
2. Enter More Temperatures
3. Delete All Temperatures
4. Quit
### Option 1: Show Temperatures
- Displays the temperatures recorded so far, along with the average temperature.
### Option 2: Enter More Temperatures
- Prompts the user to input a temperature. The temperature is added to the weather.txt file. To stop entering temperatures, the user can type 'Q'.
### Option 3: Delete All Temperatures
- Deletes all the temperature data stored in the weather.txt file.
### Option 4: Quit
- Exits the program.
## Example Interaction:
mathematica
**************************
What Do You Want To Do?:
1. Show Temperatures
2. Enter More Temperatures
3. Delete All Temperatures
4. Quit
2
Enter Your Temperature Or 'Q' To Quit: 25.5
Enter Your Temperature Or 'Q' To Quit: 30.2
Enter Your Temperature Or 'Q' To Quit: Q
**************************
What Do You Want To Do?:
1. Show Temperatures
2. Enter More Temperatures
3. Delete All Temperatures
4. Quit
1
Day 1: 25.5
Day 2: 30.2
The Average Is: 27.85
## How It Works
- setupTemperatures(): Ensures that the weather.txt file exists. If it doesn't, it creates the file.
- showTemperatures(): Reads the temperature data from weather.txt, displays each temperature, and calculates the average.
- Main Menu: The program continuously prompts the user to perform actions until the user chooses to quit.
## Troubleshooting
1. **File Access Issues**:

- Ensure the program has permission to read and write to the directory where weather.txt is stored.
If the program can't access weather.txt, it will show an error message and terminate.
2. **Invalid Input**:

- If the user enters something that cannot be converted to a number (e.g., a string instead of a temperature), the program will ignore the invalid input and prompt the user again.
## License
This program is released under the MIT License. You can freely use, modify, and distribute it.
