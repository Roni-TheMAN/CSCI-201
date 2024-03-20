# CSCI-201-M01-1
This is the code for the assingment for the CSCI 201 class module 1. 

#####################QUESTION###############################################

In this program, you will create a cube object and display its volume. Create a class Cube that
includes private data members length (int), width (int), height (int), and color (string).
Create a constructor for the class that receives the length, width, height, and color. The constructor
should set the attributes with the values provided. Your class should also have public member
functions:
- Accessor methods getLength, getWidth, getHeight, and getColor returning the
appropriate attribute of the cube.
- Mutator methods setLength, setWidth, setHeight, and setColor that allow the attributes of
the cube to be changed.
- A calculateVolume method that will return the volume of the cube (volume =
length*width * height).
Create a main program that utilizes the Cube class
1. Prompt the user for the length, width, height, and color of a cube
2. Validate the information
3. After Information from the user has been validated, create an object for the Cube.
4. Using the Accessor Methods, display the cube’s information (length, width, height, color,
and volume).
5. Allow the user to change/set the length, width, height, and color. Validate any input
before calling the appropriate functions.
6. Display the cube’s attributes after the cube has been changed using the appropriate
methods.
Be sure to include in your program:
1. An appropriate header comment and annotation,
2. Input validation of any values provided by the user.
The program may be run through Safe-Assign and may be peer-reviewed. In addition to
submitting the program here, make sure you have access to it during class, so that you can send
it to a fellow student.In this program, you will create a cube object and display its volume. Create a class Cube that
includes private data members length (int), width (int), height (int), and color (string).
Create a constructor for the class that receives the length, width, height, and color. The constructor
should set the attributes with the values provided. Your class should also have public member
functions:
- Accessor methods getLength, getWidth, getHeight, and getColor returning the
appropriate attribute of the cube.
- Mutator methods setLength, setWidth, setHeight, and setColor that allow the attributes of
the cube to be changed.
- A calculateVolume method that will return the volume of the cube (volume =
length*width * height).
Create a main program that utilizes the Cube class
1. Prompt the user for the length, width, height, and color of a cube
2. Validate the information
3. After Information from the user has been validated, create an object for the Cube.
4. Using the Accessor Methods, display the cube’s information (length, width, height, color,
and volume).
5. Allow the user to change/set the length, width, height, and color. Validate any input
before calling the appropriate functions.
6. Display the cube’s attributes after the cube has been changed using the appropriate
methods.
Be sure to include in your program:
1. An appropriate header comment and annotation,
2. Input validation of any values provided by the user.
The program may be run through Safe-Assign and may be peer-reviewed. In addition to
submitting the program here, make sure you have access to it during class, so that you can send
it to a fellow student.

#####################################

# Volume Calculator Program

## Description
This C++ program calculates the volume of a cube based on user-provided dimensions (length, width, height) and color. It provides an interactive interface for users to input the cube parameters and view the calculated volume.

## Installation
1. Ensure you have a C++ compiler installed on your system.
2. Download the "volumeCalculator.cpp" file to your local machine.
3. Open a terminal or command prompt and navigate to the directory containing "volumeCalculator.cpp."
4. Compile the program using the following command:
5. After successful compilation, run the compiled executable:


## Usage
1. Upon running the program, you will be prompted to enter the length, width, height, and color of the cube.
2. The program validates the input and calculates the volume of the cube using the formula: volume = length * width * height.
3. The calculated volume is displayed along with the provided cube parameters.
4. If desired, you can choose to edit any of the cube parameters (length, width, height, color) and see the updated volume.
5. The program provides an interactive menu for editing parameters and exiting when satisfied with the changes.

## Sample Output
Welcome to Volume Calculator 🧮
Please Enter the Following values to proceed
Enter the length of the cube: 5
Enter the width of the cube: 3
Enter the height of the cube: 2
Enter the color of the cube: blue
The length of the cube is 5 m.
The width of the cube is 3 m.
The height of the cube is 2 m.
The color of the cube is blue.
The volume of the cube is 30 m^3.
Do you want to make any changes to the values of the cube? (Y or N): Y
Enter The Corresponding Number to Select the option:
Change length: 1
Change width: 2
Change height: 3
Change color: 4
Exit (Satisfied with Changes): 0
Enter Your Choice: 2
Enter the width of the cube: 4
The length of the cube is 5 m.
The width of the cube is 4 m.
The height of the cube is 2 m.
The color of the cube is blue.
The volume of the cube is 40 m^3.

## Credits
- **Author:** Ronit Patel
- **Date Last Updated:** 3/20/2024
