#include<stdio.h> //header files//
#include<ctype.h>

int main() // body of main//
{          // neeche we are iputting values for an array which has a maximum limit of 100 character aur comma laga ke hum posiitons de rahe hain take for loop mein iterate ho sake//
    char questions[][100] = {"\t\t\t\t\t\t\t1.The Euro currency is used by how many countries?: ",
                             "\t\t\t\t\t\t\t2.The second largest continent (by area) of the world is?: ",
                             "\t\t\t\t\t\t\t4.The smallest sea of the world is?: ",
                             "\t\t\t\t\t\t\t5.The biggest island of the world is?: ",
                             "\t\t\t\t\t\t\t6.The motto of UNO is?: ",
                             "\t\t\t\t\t\t\t7.The currency of Indonesia is?: ",
                             "\t\t\t\t\t\t\t3.The Earth Surface is divided in how many continents?: ",
                             "\t\t\t\t\t\t\t8.The first nobel prize was awarded in?: ",
                             "\t\t\t\t\t\t\t9.The deepest part of the Earth is?: ",
                             "\t\t\t\t\t\t\t10.The highest part of the Earth is?: "};
    // ye similar hai but iss array mein maine options ki value input ki hai//
    char options[][100] = {"\t\t\t\t\t\t\tA. 18", "\t\t\t\t\t\t\tB. 19", "\t\t\t\t\t\t\tC. 20", "\t\t\t\t\t\t\tD. None of these",
                           "\t\t\t\t\t\t\tA. Asia", "\t\t\t\t\t\t\tB. Europe", "\t\t\t\t\t\t\tC. Africa", "\t\t\t\t\t\t\tD. North America",
                           "\t\t\t\t\t\t\tA. 5", "\t\t\t\t\t\t\tB. 6", "\t\t\t\t\t\t\tC. 7", "\t\t\t\t\t\t\tD. 8",
                           "\t\t\t\t\t\t\tA. Dead Sea", "\t\t\t\t\t\t\tB. Red Sea", "\t\t\t\t\t\t\tC. Baltic Sea", "\t\t\t\t\t\t\tD.Arabian Sea",
                           "\t\t\t\t\t\t\tA. Iceland", "\t\t\t\t\t\t\tB. Greenland", "\t\t\t\t\t\t\tC. England", "\t\t\t\t\t\t\tD. Sri Lanka",
                           "\t\t\t\t\t\t\tA. It's your world!", "\t\t\t\t\t\t\tB. Life for All!", "\t\t\t\t\t\t\tC. PEACE!", "\t\t\t\t\t\t\tD. Love and Peace!",
                           "\t\t\t\t\t\t\tA. rupiah", "\t\t\t\t\t\t\tB. dinar", "\t\t\t\t\t\t\tC. ringgit", "\t\t\t\t\t\t\tD. riyal",
                           "\t\t\t\t\t\t\tA. 1895", "\t\t\t\t\t\t\tB. 1901", "\t\t\t\t\t\t\tC. 1907", "\t\t\t\t\t\t\tD. 1913",
                           "\t\t\t\t\t\t\tA. Dead Sea", "\t\t\t\t\t\t\tB. Mariana Trench", "\t\t\t\t\t\t\tC. South Africa", "\t\t\t\t\t\t\tD. South Pole",
                           "\t\t\t\t\t\t\tA. Mount Everest", "\t\t\t\t\t\t\tB. K2", "\t\t\t\t\t\t\tC. Norway", "\t\t\t\t\t\t\tD. North Pole"};
    // yeh saare sahi jawaab hai in the third array//
    char answers[10] = {'C', 'C', 'C', 'C', 'B', 'A', 'A', 'B', 'B', 'A'};
    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);
    // declaring variables//
    char ans;
    int score=0;

    printf("\n\t\t\t\t\t\t\t\tGENERAL KNOWLEDGE QUIZ!\n");
    // first for loop hai questions print karne ke liye//
    for (int i = 0; i < numberOfQuestions; i++)
    {

        printf("\n%s\n", questions[i]);
        // this nested for loop is for options taake har char array ki position ke baad naya sawaal chale bhi chaar options uske aaye//
        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s\n", options[j]);
        }
        // yahan pe user se answer input lenge//
        printf("answer: ");
        scanf("%c", &ans);
        scanf("%*c"); // clears buffer //

        ans = toupper(ans); // this is for ke agar user lower case mein answer de to woh automatically uppercase mein change ho jaaye//
                                // below is the checking condition so that the program could match the answers from the provided answers' array//
        if (ans == answers[i])
        {
            printf("Correct\n");
            // this would add up the scores//
            score++;
        }

        else
        {
            printf("Wrong\n");
        }
    }
    // aur finally hamara final score print hoga//
    printf("\n\t\t\t\t\t\t\t\tFINAL SCORE: %d/%d\n\n\n", score, numberOfQuestions);

    return 0;
}
// short simple aur efficient general knowledge quiz game i hope you like it //
//  i have taken some help from internet for e.g that "toupper" functionality or that above fixing the array values etc//