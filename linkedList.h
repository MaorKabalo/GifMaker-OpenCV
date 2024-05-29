
#ifndef LINKEDLISTH
#define LINKEDLISTH

#define FALSE 0
#define TRUE !FALSE

#define STR_LEN 50

#define _CRT_SECURE_NO_WARNINGS
#define CV_IGNORE_DEBUG_BUILD_GUARD

// Frame struct
typedef struct Frame
{
	char name[STR_LEN];
	unsigned int duration;
	char path[STR_LEN];
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;


void insertAtEnd(FrameNode** head, FrameNode* newNode);
void printFrameNode(FrameNode* FrameNodeHead);
FrameNode* createFrame(char* name, char* path, unsigned int duration);
void addFrame(FrameNode** FrameNodeHead);
int findFrame(FrameNode** FrameNodeHead, char* name);
void changeDurationOfAllFrames(FrameNode* FrameNodeHead);
void changeDurationOfSpecificFrame(FrameNode* FrameNodeHead, char* name);
void changeFrameLocation(FrameNode** FrameNodeHead, char* name);
int listLength(FrameNode* head);
void deleteSpecificFrame(FrameNode** FrameNodeHead, char* name);
void freeFrameNode(FrameNode* FrameNodeHead);
FrameNode* loadProject(char* path);


#endif