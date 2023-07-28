# Automatic Performance Appraisal System

This is a C++ program that implements an Automatic Performance Appraisal System for a company. The system allows different team members (Developers, Designers, and Architects) to input their self-ratings and managers to provide ratings for their team members. Additionally, the HR department can provide normalized ratings based on certain constraints.

## Requirements

- C++ compiler (Supporting C++11 or higher)
- Input CSV file containing employee data

## Instructions

1. Compile the code using a C++ compiler.
2. Set the environment variable `FOLDER_PATH_ENV_VAR` to the folder path containing the input CSV file.
3. The CSV file should contain data in the following format:
- Each row represents a different team member, and each column represents their corresponding tasks.
- The Developer Task, Designer Task, and Architect Task should be semicolon-separated strings.
4. Run the compiled executable.
5. Use the menu options to input self-ratings, manager ratings, HR ratings, and view departmental ratings.
6. The CEO can view overall department ratings and generate a CSV file containing CEO ratings.

## Classes

### TeamMember

- Abstract base class for all team members (Developer, Designer, Architect).
- Defines common methods for inputting and printing ratings.

### Developer, Designer, Architect

- Derived classes from the TeamMember class.
- Overrides the `inputSelfRatings()` method to input self-ratings for specific tasks.
- Overrides the `getTaskName()` method to get the task names for each team member.

### Manager

- Derived from the TeamMember class.
- Allows managers to input ratings for their team members.
- Overrides the `getTaskName()` method to display "Employee X" for each team member.

### HR

- Derived from the TeamMember class.
- Allows HR to input normalized ratings for all team members.
- Uses constraints to ensure a balanced distribution of ratings.

### Other Helper Functions

- `deepCopyVector`: Creates a deep copy of a vector of TeamMember objects.
- `getFolderPathFromEnvVar` and `getFullFilePath`: Helper functions to retrieve the folder path and construct the full file path.

## Usage

1. Run the program and choose the appropriate options from the menu.
2. Input self-ratings for individual team members.
3. Managers can input ratings for their team members.
4. HR can input normalized ratings based on constraints.
5. The CEO can view overall department ratings and generate a CSV file containing CEO ratings.

## Note

- Make sure to set the environment variable `FOLDER_PATH_ENV_VAR` to the correct folder path containing the input CSV file before running the program.
- The program uses console input/output for simplicity.

## Example

Here is an example of the input CSV file format:
```
Developer Name,Developer Task,Designer Name,Designer Task,Architect Name,Architect Task
```
## License

This project is licensed under the [MIT License](LICENSE).

Feel free to contribute and improve this project!
