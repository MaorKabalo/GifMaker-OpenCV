/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#define _CRT_SECURE_NO_WARNINGS
#define CV_IGNORE_DEBUG_BUILD_GUARD
#define _CRTDBG_MAP_ALLOC





#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <crtdbg.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include "linkedList.h"
#include "view.h"

void menu();

int main()
{

    int option;
    FrameNode* head = NULL;
    char buffer[STR_LEN] = { 0 };
    printf("Welcome to Magshimim Movie Maker! what would you like to do?\n");


    while (TRUE)
    {
        printf(" [0] Create a new project\n");
        printf(" [1] Load existing project\n");
        scanf("%d", &option);

        if (!(option >= 0 && option <= 1))
        {
            printf("Invalid choice, try again:\n");
            continue;
        }
        break;
    }



    if (option == 0)
    {
        printf("Working on a new project.\n\n");
    }
    else
    {
        printf("Enter the path of the project (including project name):\n");
        scanf("%s", &buffer);

        FILE* file;
        if (file = fopen(buffer, "r"))
        {
            head = loadProject(buffer);
            printf("Project is loaded\n");
            fclose(file);
        }
        else
        {
            printf("Error!- cant open file, creating a new project\n");
        }

    }




    while (TRUE)
    {


        while (TRUE)
        {
            menu();
            scanf("%d", &option);

            if (!(option >= 0 && option <= 8))
            {
                printf("You should type one of the options - 0-8!\n");
                continue;
            }
            break;
        }

        if (option == 0)
        {
            printf("Bye!");
            break;
        }
        else if (option == 1)
        {
            addFrame(&head);
        }
        else if (option == 2)
        {
            printf("Enter the name of the frame you wish to erase\n");
            scanf("%s", &buffer);
            deleteSpecificFrame(&head, buffer);
        }
        else if (option == 3)
        {
            printf("Enter the name of the frame\n");
            scanf("%s", &buffer);
            changeFrameLocation(&head, buffer);
        }
        else if (option == 4)
        {
            printf("Enter the name of the frame\n");
            scanf("%s", &buffer);
            changeDurationOfSpecificFrame(head, buffer);
        }
        else if (option == 5)
        {
            changeDurationOfAllFrames(head);
        }
        else if (option == 6)
        {
            printFrameNode(head);
        }
        else if (option == 7)
        {
            play(head);
        }
        else if (option == 8)
        {
            saveProject(head);
        }

        memset(buffer, 0, sizeof(buffer));

    }

    freeFrameNode(head);
    getchar();
    return 0;

}

void menu()
{
    printf("What would you like to do?\n");
    printf(" [0] Exit\n");
    printf(" [1] Add new Frame\n");
    printf(" [2] Remove a Frame\n");
    printf(" [3] Change frame index\n");
    printf(" [4] Change frame duration\n");
    printf(" [5] Change duration of all frames\n");
    printf(" [6] List frames\n");
    printf(" [7] Play movie!\n");
    printf(" [8] Save project\n");
}