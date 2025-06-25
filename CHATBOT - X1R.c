#include <stdio.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<dos.h>


#define GOOGLE "https://www.google.com"
#define YOUTUBE "https://www.youtube.com"


void speak(const char *text) {
    printf("%s\n", text);
}

void wishMe(const char *activationMessage) {
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    int hour = tm_info->tm_hour;

    if (hour < 12) {
        speak("Good Morning Master...");
        PlaySound(TEXT("H6.WAV"), NULL, SND_SYNC);
    } else if (hour < 17) {
        speak("Good Afternoon Master...");
        PlaySound(TEXT("H6.WAV"), NULL, SND_SYNC);
    } else {
        speak("Good Evening Master...");
        PlaySound(TEXT("H6.WAV"), NULL, SND_SYNC);
    }
}

void showDateTime() {
    time_t t;
    struct tm *tm_info;
    char timeBuffer[50];
    char dateBuffer[50];

    time(&t);
    tm_info = localtime(&t);

    strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", tm_info);
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", tm_info);

    printf("Current Time: %s\n", timeBuffer);
    printf("Current Date: %s\n", dateBuffer);
}

int isAppInstalled(const char *appName) {
    char command[256];
    snprintf(command, sizeof(command), "where %s >nul 2>nul", appName);
    return system(command) == 0; // Returns 0 if the app is found
}

void trimWhitespace(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }

    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t')) {
        end--;
    }

    *(end + 1) = '\0';
}

void searchSport(const char *sport) {
    char searchQuery[200];
    snprintf(searchQuery, sizeof(searchQuery), "start %s/search?q=%s", GOOGLE, sport);
    PlaySound(TEXT("H8.WAV"), NULL, SND_SYNC);
    printf("_Ok sir, I am searching for: %s\n", sport);
    printf("Opening Google to find the sport...\n");
    system(searchQuery);
}

void searchJob(const char *job) {
    char searchQuery[200];
    snprintf(searchQuery, sizeof(searchQuery), "start %s/search?q=%s job openings", GOOGLE, job);
    PlaySound(TEXT("H8.WAV"), NULL, SND_SYNC);
    printf("_Ok sir, I am searching for job openings related to: %s\n", job);
    printf("Opening Google to find job openings...\n");
    system(searchQuery);
}

void searchCodingProblem(const char *problem) {
    char searchQuery[200];
    snprintf(searchQuery, sizeof(searchQuery), "start %s/search?q=%s programming problem", GOOGLE, problem);
    PlaySound(TEXT(".WAV"), NULL, SND_SYNC);
    printf("_Ok sir, I am searching for: %s programming problem\n", problem);
    printf("Opening Google to find solutions for the programming problem...\n");
    system(searchQuery);
}

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void performMathOperation() {
    char operation[10];
    double num1, num2, result;

    printf("Enter the operation (add, subtract, multiply, divide): ");
    scanf("%s", operation);
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    if (strcmp(operation, "add") == 0) {
        result = num1 + num2;
        printf("The result is: %.2lf\n", result);
    } else if (strcmp(operation, "subtract") == 0) {
        result = num1 - num2;
        printf("The result is: %.2lf\n", result);
    } else if (strcmp(operation, "multiply") == 0) {
        result = num1 * num2;
        printf("The result is: %.2lf\n", result);
    } else if (strcmp(operation, "divide") == 0) {
        if (num2 != 0) {
            result = num1 / num2;
            printf("The result is: %.2lf\n", result);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
    } else {
        printf("Invalid operation. Please try again.\n");
    }
}


void takeCommand(char *input) {
    trimWhitespace(input);
    toLowercase(input);

    if (strcmp(input, "hi") == 0) {
        PlaySound(TEXT("hi sir.WAV"), NULL, SND_SYNC);
        printf("hello\n");
    } else if (strcmp(input, "hello") == 0) {
        PlaySound(TEXT("how r u.WAV"), NULL, SND_SYNC);
        printf("HELLO SIR HOW CAN I HELP YOU !!\n");
    } else if (strcmp(input, "bye") == 0) {
        printf("Are you sure you want to exit? (yes/no): ");
        fgets(input, 256, stdin);
        input[strcspn(input, "\n")] = 0;
        toLowercase(input);

        if (strcmp(input, "yes") == 0) {
            PlaySound(TEXT("THANK YOU FOR CHOISE.WAV"), NULL, SND_SYNC);
            printf("HAVE A NICE DAY \n");
            exit(0);
        } else {
            printf("Alright! How can I assist further?\n");
        }
    } else if (strcmp(input, "open google") == 0) {
        PlaySound(TEXT("_Ok sir I am opening.WAV"), NULL, SND_SYNC);
        printf("_OK Sir I am Opening Google...\n");
        system("start " GOOGLE);
    } else if (strcmp(input, "open youtube") == 0) {
        PlaySound(TEXT("h4.WAV"), NULL, SND_SYNC);
        printf("_Ok sir I am opening YouTube.\n");
        system("start " YOUTUBE);
    } else if (strncmp(input, "play song ", 10) == 0) {
        char searchQuery[200];
        snprintf(searchQuery, sizeof(searchQuery), "start %s/results?search_query=%s", YOUTUBE, input + 10);
        PlaySound(TEXT("Ok sir i am finding .WAV"), NULL, SND_SYNC);
        printf("_Ok sir I am finding the song: %s\n", input + 10);
        printf("Opening YouTube to play the song...\n");
        system(searchQuery);
    } else if (strncmp(input, "open app ", 9) == 0) {
        char appName[200];
        PlaySound(TEXT("h5.WAV"), NULL, SND_SYNC);
        snprintf(appName, sizeof(appName), "%s", input + 9);
        if (isAppInstalled(appName)) {
            char appCommand[200];
            snprintf(appCommand, sizeof(appCommand), "start %s", appName);

            printf("_Ok sir I am opening the application: %s\n", appName);
            system(appCommand);
        } else {
            char searchQuery[200];
            snprintf(searchQuery, sizeof(searchQuery), "start %s/search?q=%s", GOOGLE, appName);
            PlaySound(TEXT("_Sorry sir, I couldn't find the app. Searching on Google.WAV"), NULL, SND_SYNC);
            printf("Sorry sir, the app %s is not installed. Searching for it on Google...\n", appName);
            system(searchQuery);
        }
    } else if (strncmp(input, "find article ", 30) == 0) {
        char article[200];
        snprintf(article, sizeof(article), "%s", input + 30);
        char searchQuery[200];
        snprintf(searchQuery, sizeof(searchQuery), "start https://en.wikipedia.org/wiki/%s", article);
        PlaySound(TEXT("open.WAV"), NULL, SND_SYNC);
        printf("_Ok sir I am searching for the article: %s\n", article);
        printf("Opening Wikipedia to find the article...\n");
        system(searchQuery);
    } else if (strncmp(input, "find sport ", 11) == 0) {
        char sport[200];
        snprintf(sport, sizeof(sport), "%s", input + 11);
        searchSport(sport);
    } else if (strncmp(input, "find job ", 9) == 0) {
        char job[200];
        snprintf(job, sizeof(job), "%s", input + 9);
        searchJob(job);
    } else if (strcmp(input, "math") == 0) {
        performMathOperation();
    } else if (strcmp(input, "help") == 0) {
        printf("Here are some things I can do:\n");
        printf(" Say 'hi' or 'hello' for greetings.\n");
        printf("- 'open google', 'open youtube', etc.\n");
        printf("- 'play song [song name]' to search for music.\n");
        printf("- 'find article [topic]' to search Wikipedia.\n");
        printf("- 'find sport [sport name]' to search for sports.\n");
        printf("- 'find job [job title]' to search for job openings.\n");
        printf("- 'math' to perform mathematical operations.\n");
        printf("- Mention 'code' or 'problem' for programming help.\n");
    } else if (strstr(input, "code") != NULL || strstr(input, "program") != NULL || strstr(input, "problem") != NULL) {
        searchCodingProblem(input);
    } else {
        PlaySound(TEXT("_h4.WAV"), NULL, SND_SYNC);
        printf("I'm sorry, I didn't understand that command. Please try 'help' for a list of valid commands.\n");
    }
}

int main() {
    system(" color 0c");
    char input[500]; // Increased buffer size to handle longer inputs
    char activationCode[] = "X1R"; // Fixed activation code
    int attempts = 0; // Counter for incorrect attempts
    const int maxAttempts = 3; // Maximum allowed attempts

    printf("************** || DESIGN BY TEAM - X1R || **************\n");


    // Request activation code
    while (attempts < maxAttempts) {
        printf("\nHey Boss Enter activation message : ");
        Printf("TYPE -- HELP : FOR KNOW ABOUT TASK TO PERFORM BY CHATBOT");
        PlaySound(TEXT("hey boss Enter activ.WAV"), NULL, SND_SYNC);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline character

        if (strcmp(input, activationCode) == 0) {
            printf("Activation successful! Task Proceeding...\n");
            PlaySound(TEXT("SOR.WAV"), NULL, SND_SYNC);
            break;  // Exit the loop if the code is correct
        } else {
            attempts++;
            printf("Incorrect code Plese try again later . You have %d attempt(s) remaining.\n", maxAttempts - attempts);
            PlaySound(TEXT("Incorrect code pleas.WAV"), NULL, SND_SYNC);
            if (attempts == maxAttempts) {
                printf("Maximum attempts reached. Exiting the program.\n");
                exit(1);
            }
        }
    }

    wishMe(input);
    showDateTime();

    while (1) {
        printf("\nType your task for processing: ");
        PlaySound(TEXT("Type you task for pr.WAV"), NULL, SND_SYNC);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        takeCommand(input);
    }

    return 0;
}
