#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_QUESTIONS 5

// Structure to represent a quiz question
struct Question {
    char questionText[256];
    char options[4][64];
    int correctOption;
};

// Function to display a question and its options
void displayQuestion(struct Question q) {
    printf("%s\n", q.questionText);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
    printf("Enter your answer (1-4): ");
}

// Function to check the answer
int checkAnswer(struct Question q, int userAnswer) {
    return (userAnswer == q.correctOption);
}

int main() {
    // Initialize questions
    struct Question questions[TOTAL_QUESTIONS] = {
        {
            "What is the capital of France?",
            {"Paris", "London", "Berlin", "Madrid"},
            1
        },
        {
            "Which planet is known as the Red Planet?",
            {"Mars", "Venus", "Jupiter", "Saturn"},
            1
        },
        {
            "Who wrote the play 'Romeo and Juliet'?",
            {"William Shakespeare", "Jane Austen", "Charles Dickens", "Leo Tolstoy"},
            1
        },
        {
            "What is the largest ocean on Earth?",
            {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"},
            4
        },
        {
            "Which element has the chemical symbol 'O'?",
            {"Oxygen", "Gold", "Osmium", "Ozone"},
            1
        }
    };

    // Seed the random number generator
    srand(time(NULL));

    int score = 0;
    int askedQuestions[TOTAL_QUESTIONS] = {0}; // Track asked questions
    int numAsked = 0;

    printf("Welcome to the Enhanced Quiz Game!\n");

    while (numAsked < TOTAL_QUESTIONS) {
        int index;
        do {
            index = rand() % TOTAL_QUESTIONS;
        } while (askedQuestions[index]); // Ensure the question hasn't been asked already

        askedQuestions[index] = 1;
        numAsked++;

        displayQuestion(questions[index]);

        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer >= 1 && userAnswer <= 4) {
            if (checkAnswer(questions[index], userAnswer)) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %d. %s\n",
                       questions[index].correctOption,
                       questions[index].options[questions[index].correctOption - 1]);
            }
        } else {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            numAsked--; // Don't count this question
        }
    }

    printf("Quiz completed! Your score: %d out of %d\n", score, TOTAL_QUESTIONS);

    return 0;
}
