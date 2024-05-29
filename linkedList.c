
#define _CRT_SECURE_NO_WARNINGS
#define CV_IGNORE_DEBUG_BUILD_GUARD

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "linkedList.h"




void insertAtEnd(FrameNode** head, FrameNode* newNode)
{

	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		FrameNode* p = *head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNode;
	}

}


/*print list
input: head
output: NONE*/
void printFrameNode(FrameNode* FrameNodeHead)
{
	printf("Name\tDuration\tPath\n");

	FrameNode* curr = FrameNodeHead;

	while (curr != NULL)
	{
		printf("%s\t%d ms\t\t%s\n", curr->frame->name, curr->frame->duration, curr->frame->path);
		curr = curr->next;
	}
	free(curr);
	printf("\n");
}

FrameNode* createFrame(char* name, char* path, unsigned int duration)
{
	FrameNode* new = (FrameNode*)malloc(sizeof(FrameNode));
	new->frame = (Frame*)malloc(sizeof(Frame));
	new->frame->duration = duration;
	strcpy(new->frame->name, name);
	strcpy(new->frame->path, path);
	new->next = NULL;
	return new;
}

/*adds frame to list
input: head
output:None*/
void addFrame(FrameNode** FrameNodeHead)
{

	char name[STR_LEN] = { 0 };
	char path[STR_LEN] = { 0 };
	unsigned int duration;

	printf("*** Creating new frame ***\n");
	printf("Please insert frame path:\n");
	scanf("%s", &path);
	printf("Please insert frame duration(in miliseconds)\n");
	scanf("%u", &duration);

	while (TRUE)
	{
		printf("Please choose a name for that frame:\n");
		scanf("%s", &name);

		if (findFrame(FrameNodeHead, name) != -1)
		{
			printf("The name is already taken, please enter another name\n");
			continue;
		}
		break;
	}

	FILE* file;
	if (file = fopen(path, "rb"))
	{
		fclose(file);
	}
	else
	{
		printf("Can't find file! Frame will not be added\n\n");
		return;
	}


	FrameNode* new = createFrame(name, path, duration);


	insertAtEnd(FrameNodeHead, new);
	printf("\n");
}


/*finds frame's index
input: pointer of head, name of frame
output: NONE*/
int findFrame(FrameNode** FrameNodeHead, char* name)
{
	if (!*FrameNodeHead)
	{
		return -1;
	}


	int count = 1;

	FrameNode* curr = *FrameNodeHead;

	while (curr)
	{
		if (!strcmp(curr->frame->name, name))
		{
			return count;
		}
		curr = curr->next;
		count++;
	}
	return -1;
}


/*changes duration of all frames
input: head
output: NONE*/
void changeDurationOfAllFrames(FrameNode* FrameNodeHead)
{
	unsigned int newDur;
	printf("Enter the duration for all frames:\n");
	scanf("%d", &newDur);

	FrameNode* curr = FrameNodeHead;
	while (curr)
	{
		curr->frame->duration = newDur;
		curr = curr->next;
	}
	printf("\n");
}


/*changes duration of a specific frame
input: head
output: NONE*/
void changeDurationOfSpecificFrame(FrameNode* FrameNodeHead, char* name)
{
	unsigned int newDur;


	FrameNode* curr = FrameNodeHead;
	while (curr)
	{
		if (!strcmp(curr->frame->name, name))
		{
			printf("Enter new duration time for frame %s:\n", name);
			scanf("%d", &newDur);
			curr->frame->duration = newDur;
			return;
		}
		curr = curr->next;
	}
	printf("The frame does not exist\n\n");
}


/*changes location of frame (index starts from 1)
input: head, name of frame, index
output: NONE*/
void changeFrameLocation(FrameNode** FrameNodeHead, char* name) //fix
{


	if (findFrame(FrameNodeHead, name) == -1 || !*FrameNodeHead)
	{
		printf("this frame does not exist\n\n");
		return;
	}

	int index;

	while (TRUE)
	{
		printf("Enter the new index in the movie you wish to place the frame\n");
		scanf("%d", &index);
		if (!(index >= 1 && index <= listLength(*FrameNodeHead)))
		{
			printf("The movie contains only %d frames!\n", listLength(*FrameNodeHead));
			continue;
		}
		break;
	}

	if (findFrame(FrameNodeHead, name) == index)
	{
		return;
	}

	FrameNode* curr = *FrameNodeHead;


	while (strcmp(curr->frame->name, name))
	{
		curr = curr->next;
	}


	FrameNode* toChange = createFrame(curr->frame->name, curr->frame->path, curr->frame->duration);

	deleteSpecificFrame(FrameNodeHead, toChange->frame->name);


	if (index == 1)
	{
		toChange->next = *FrameNodeHead;
		*FrameNodeHead = toChange;
		return;
	}
	else if (index == listLength(*FrameNodeHead) + 1)
	{
		insertAtEnd(FrameNodeHead, toChange);
		return;
	}

	int count = 2;
	curr = *FrameNodeHead;
	while (count < index - 1)
	{
		curr = curr->next;
	}
	toChange->next = curr->next;
	curr->next = toChange;
}

/*length of person's list
input: head
output: length of list*/
int listLength(FrameNode* head)
{
	FrameNode* curr = head;

	int count = 0;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	free(curr);
	return count;

}




/*Deletes a frame
input: pointer of head, name of person you want to delete
output: NONE*/
void deleteSpecificFrame(FrameNode** FrameNodeHead, char* name)
{

	FrameNode* p = *FrameNodeHead;
	FrameNode* dNode = NULL;

	int flag = TRUE;

	if (*FrameNodeHead)
	{
		if (FALSE == strcmp((*FrameNodeHead)->frame->name, name))
		{
			*FrameNodeHead = (*FrameNodeHead)->next;
			free(p->frame);
			free(p);
			flag = FALSE;
		}
		else
		{
			while (p->next && FALSE != strcmp(p->next->frame->name, name))
			{
				p = p->next;
			}
			if (p->next)
			{
				dNode = p->next;
				p->next = dNode->next;
				free(dNode->frame);
				free(dNode);
				flag = FALSE;
			}
		}
	}

	if (flag)
	{
		printf("The frame was not found\n");
	}

}


FrameNode* loadProject(char* path)
{

	FILE* file = fopen(path, "r");

	char ch;
	int row = 0, col = 0;

	FrameNode* FrameNodeHead = NULL;
	FrameNode* curr;


	char frame[3][STR_LEN] = { 0 };


	while ((ch = (char)fgetc(file)) != EOF)
	{
		if (ch == '&')
		{
			frame[row][col] = '\0';
			row++;
			col = 0;
		}
		else if (ch == '\n')
		{
			curr = createFrame(frame[0], frame[2], strtoul(frame[1], NULL, 0));
			insertAtEnd(&FrameNodeHead, curr);
			memset(frame[0], 0, sizeof(frame[0]));
			memset(frame[1], 0, sizeof(frame[1]));
			memset(frame[2], 0, sizeof(frame[2]));
			row = 0;
			col = 0;
		}
		else
		{
			frame[row][col] = ch;
			col++;
		}

	}

	fclose(file);

	return FrameNodeHead;


}





/*free list
input: head
output: NONE*/
void freeFrameNode(FrameNode* FrameNodeHead)
{

	FrameNode* curr = FrameNodeHead;
	FrameNode* temp = NULL;

	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	FrameNodeHead = NULL;

}


